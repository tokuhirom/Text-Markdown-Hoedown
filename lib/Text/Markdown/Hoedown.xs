#ifdef __cplusplus
extern "C" {
#endif

#define PERL_NO_GET_CONTEXT /* we want efficiency */
#include <EXTERN.h>
#include <perl.h>
#include <XSUB.h>

#ifdef __cplusplus
} /* extern "C" */
#endif

#include <string.h>

#define NEED_newSVpvn_flags
#include "ppport.h"

#include "../../hoedown/src/markdown.h"
#include "../../hoedown/src/html.h"

#define XS_STRUCT2OBJ(sv, class, obj) \
    sv = newSViv(PTR2IV(obj));  \
    sv = newRV_noinc(sv); \
    sv_bless(sv, gv_stashpv(class, 1)); \
    SvREADONLY_on(sv);

#define XS_STATE(type, x) \
    INT2PTR(type, SvROK(x) ? SvIV(SvRV(x)) : SvIV(x))

typedef enum {
    TMH_CALLBACK_TYPE_HTML,
    TMH_CALLBACK_TYPE_CUSTOM
} tmh_callback_type;

typedef struct {
    struct hoedown_markdown *md;
    SV * cb;
} tmh_markdown;

typedef struct {
    tmh_callback_type type;
    struct hoedown_callbacks callbacks;
    union {
        struct hoedown_html_renderopt* html_opaque;
        HV * custom_opaque;
    };
} tmh_callbacks;

typedef void* hoedown_opaque_t;

#define PUSHBUF(text) \
    if (text) { \
        mXPUSHp(text->data, text->size); \
    } else { \
        XPUSHs(&PL_sv_undef); \
    }

#define CB_HEADER(key) \
    dTHX; dSP; bool is_null = 0; \
    SV** rcb = hv_fetch((HV*)opaque, key, strlen(key), 0); \
    if (!rcb) { return; } \
    SV* cb = *rcb; \
    \
    ENTER; \
    SAVETMPS; \
    \
    PUSHMARK(SP);

#define CB_FOOTER \
    PUTBACK; \
    \
    int count = call_sv(cb, G_SCALAR); \
    \
    SPAGAIN; \
    \
    if (count == 1) { \
        SV* ret = POPs; \
        if (ret != &PL_sv_undef) { \
            STRLEN l; \
            char * p = SvPV(ret, l); \
            hoedown_buffer_grow(ob, ob->size + l); \
            hoedown_buffer_put(ob, p, l); \
        } else {\
            is_null = 1;\
        } \
    } \
    \
    PUTBACK; \
    FREETMPS; \
    LEAVE;


#include "gen.callback.c"

#define TMH_CONST(name) \
    newCONSTSUB(stash, #name, newSViv(name)); \
    av_push(get_av("Text::Markdown::Hoedown::EXPORT", GV_ADD), newSVpv(#name, 0));

MODULE = Text::Markdown::Hoedown    PACKAGE = Text::Markdown::Hoedown PREFIX=hoedown_markdown_

BOOT:
    HV* stash = gv_stashpv("Text::Markdown::Hoedown", GV_ADD);

    TMH_CONST(HOEDOWN_EXT_NO_INTRA_EMPHASIS);
    TMH_CONST(HOEDOWN_EXT_TABLES);
    TMH_CONST(HOEDOWN_EXT_FENCED_CODE);
    TMH_CONST(HOEDOWN_EXT_AUTOLINK);
    TMH_CONST(HOEDOWN_EXT_STRIKETHROUGH);
    TMH_CONST(HOEDOWN_EXT_UNDERLINE);
    TMH_CONST(HOEDOWN_EXT_SPACE_HEADERS);
    TMH_CONST(HOEDOWN_EXT_SUPERSCRIPT);
    TMH_CONST(HOEDOWN_EXT_LAX_SPACING);
    TMH_CONST(HOEDOWN_EXT_DISABLE_INDENTED_CODE);
    TMH_CONST(HOEDOWN_EXT_HIGHLIGHT);
    TMH_CONST(HOEDOWN_EXT_FOOTNOTES);
    TMH_CONST(HOEDOWN_EXT_QUOTE);

    TMH_CONST(HOEDOWN_HTML_SKIP_HTML);
    TMH_CONST(HOEDOWN_HTML_SKIP_STYLE);
    TMH_CONST(HOEDOWN_HTML_SKIP_IMAGES);
    TMH_CONST(HOEDOWN_HTML_SKIP_LINKS);
    TMH_CONST(HOEDOWN_HTML_EXPAND_TABS);
    TMH_CONST(HOEDOWN_HTML_SAFELINK);
    TMH_CONST(HOEDOWN_HTML_TOC);
    TMH_CONST(HOEDOWN_HTML_HARD_WRAP);
    TMH_CONST(HOEDOWN_HTML_USE_XHTML);
    TMH_CONST(HOEDOWN_HTML_ESCAPE);
    TMH_CONST(HOEDOWN_HTML_PRETTIFY);

TYPEMAP: <<HERE

tmh_callbacks* T_TMH_CALLBACKS
tmh_markdown* T_TMH_MARKDOWN

OUTPUT

T_TMH_CALLBACKS
    sv_setref_pv($arg, \"Text::Markdown::Hoedown::Callbacks\", (void*)$var);

T_TMH_MARKDOWN
    sv_setref_pv($arg, \"Text::Markdown::Hoedown::Markdown\", (void*)$var);

INPUT

T_TMH_CALLBACKS
    $var = INT2PTR($type, SvROK($arg) ? SvIV(SvRV($arg)) : SvIV($arg));

T_TMH_MARKDOWN
    $var = INT2PTR($type, SvROK($arg) ? SvIV(SvRV($arg)) : SvIV($arg));

HERE

PROTOTYPES: DISABLE

MODULE = Text::Markdown::Hoedown    PACKAGE = Text::Markdown::Hoedown::Markdown

tmh_markdown *
new(const char* klass, unsigned int extensions, size_t max_nesting, SV*callbacks_sv)
PREINIT:
    tmh_markdown *tmhmd;
CODE:
    tmh_callbacks* callbacks = XS_STATE(tmh_callbacks*, callbacks_sv);
    Newxz(tmhmd, 1, tmh_markdown);
    if (callbacks->type == TMH_CALLBACK_TYPE_HTML) {
        tmhmd->md = hoedown_markdown_new(extensions, max_nesting, &(callbacks->callbacks), callbacks->html_opaque);
    } else {
        tmhmd->md = hoedown_markdown_new(extensions, max_nesting, &(callbacks->callbacks), callbacks->custom_opaque);
    }
    tmhmd->cb = newSVsv(callbacks_sv);
    RETVAL = tmhmd;
OUTPUT:
    RETVAL

SV*
render(tmh_markdown *self, SV *src_sv)
PREINIT:
    struct hoedown_buffer* ob;
    const char *src;
    STRLEN src_len;
CODE:
    ob = hoedown_buffer_new(64);

    src = SvPV(src_sv, src_len);
    hoedown_markdown_render(ob, src, src_len, self->md);

    SV* ret = newSVpv(hoedown_buffer_cstr(ob), 0);
    if (SvUTF8(src_sv)) {
        SvUTF8_on(ret);
    }
    hoedown_buffer_free(ob);
    RETVAL = ret;
OUTPUT:
    RETVAL

void
DESTROY(tmh_markdown*self)
CODE:
    SvREFCNT_dec(self->cb);
    hoedown_markdown_free(self->md);

MODULE = Text::Markdown::Hoedown    PACKAGE = Text::Markdown::Hoedown::Callbacks

tmh_callbacks*
new(const char*CLASS)
PREINIT:
    tmh_callbacks* self;
CODE:
    Newxz(self, 1, tmh_callbacks);
    self->type = TMH_CALLBACK_TYPE_CUSTOM;
    self->custom_opaque = newHV();
    RETVAL = self;
OUTPUT:
    RETVAL

INCLUDE: gen.callback.inc

tmh_callbacks*
html_renderer(const char *klass, unsigned int render_flags)
PREINIT:
    tmh_callbacks* self;
CODE:
    Newxz(self, 1, tmh_callbacks);
    Newxz(self->html_opaque, 1, struct hoedown_html_renderopt);
    self->type = TMH_CALLBACK_TYPE_HTML;

    hoedown_html_renderer(&(self->callbacks), self->html_opaque, render_flags);
    /* hoedown should provide API for setting nesting_level. But it doesn't provide. */
    self->html_opaque->toc_data.nesting_level = 99;
    RETVAL = self;
OUTPUT:
    RETVAL

tmh_callbacks*
html_toc_renderer(const char* klass, int nesting_level)
PREINIT:
    tmh_callbacks* self;
CODE:
    Newxz(self, 1, tmh_callbacks);
    Newxz(self->html_opaque, 1, struct hoedown_html_renderopt);
    self->type = TMH_CALLBACK_TYPE_HTML;

    hoedown_html_toc_renderer(&(self->callbacks), self->html_opaque, nesting_level);

    RETVAL = self;
OUTPUT:
    RETVAL

void
DESTROY(tmh_callbacks* self)
CODE:
    if (self->type == TMH_CALLBACK_TYPE_CUSTOM) {
        SvREFCNT_dec(self->custom_opaque);
    } else {
        Safefree(self->html_opaque);
    }
    Safefree(self);

