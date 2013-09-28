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

#define NEED_newSVpvn_flags
#include "ppport.h"

#include "../../hoedown/src/markdown.h"
#include "../../hoedown/src/html.h"

MODULE = Text::Markdown::Hoedown    PACKAGE = Text::Markdown::Hoedown PREFIX=hoedown_markdown_

TYPEMAP: <<HERE

struct hoedown_markdown * T_HOEDOWN_MARKDOWN
struct hoedown_buffer* T_HOEDOWN_BUFFER
struct hoedown_callbacks* T_HOEDOWN_CALLBACKS
const struct hoedown_callbacks* T_HOEDOWN_CALLBACKS
struct hoedown_html_renderopt* T_HOEDOWN_HTML_RENDEROPT

OUTPUT

T_HOEDOWN_HTML_RENDEROPT
    sv_setref_pv($arg, \"Text::Markdown::Hoedown::HTMLRenderOpt\", (void*)$var);

T_HOEDOWN_CALLBACKS
    sv_setref_pv($arg, \"Text::Markdown::Hoedown::Callbacks\", (void*)$var);

T_HOEDOWN_MARKDOWN
    sv_setref_pv($arg, \"Text::Markdown::Hoedown::Markdown\", (void*)$var);

T_HOEDOWN_BUFFER
    sv_setref_pv($arg, \"Text::Markdown::Hoedown::Buffer\", (void*)$var);

INPUT

T_HOEDOWN_HTML_RENDEROPT
    $var = INT2PTR($type, SvROK($arg) ? SvIV(SvRV($arg)) : SvIV($arg));

T_HOEDOWN_CALLBACKS
    $var = INT2PTR($type, SvROK($arg) ? SvIV(SvRV($arg)) : SvIV($arg));

T_HOEDOWN_BUFFER
    $var = INT2PTR($type, SvROK($arg) ? SvIV(SvRV($arg)) : SvIV($arg));

T_HOEDOWN_MARKDOWN
    $var = INT2PTR($type, SvROK($arg) ? SvIV(SvRV($arg)) : SvIV($arg));

HERE

PROTOTYPES: DISABLE

MODULE = Text::Markdown::Hoedown    PACKAGE = Text::Markdown::Hoedown::Markdown PREFIX=hoedown_markdown_

struct hoedown_markdown *
hoedown_markdown_new(const char* klass, unsigned int extensions, size_t max_nesting, const struct hoedown_callbacks *callbacks, void *opaque)
CODE:
    RETVAL = hoedown_markdown_new(extensions, max_nesting, callbacks, opaque);
OUTPUT:
    RETVAL

SV*
hoedown_markdown_render(struct hoedown_markdown *self, SV *src_sv)
PREINIT:
    struct hoedown_buffer* ob;
    const char *src;
    STRLEN src_len;
CODE:
    ob = hoedown_buffer_new(64);

    src = SvPV(src_sv, src_len);
    hoedown_markdown_render(ob, src, src_len, self);

    SV* ret = newSVpv(hoedown_buffer_cstr(ob), 0);
    if (SvUTF8(src_sv)) {
        SvUTF8_on(ret);
    }
    hoedown_buffer_free(ob);
    RETVAL = ret;
OUTPUT:
    RETVAL

void
DESTROY(struct hoedown_markdown*self)
CODE:
    hoedown_markdown_free(self);

MODULE = Text::Markdown::Hoedown    PACKAGE = Text::Markdown::Hoedown::Callbacks

struct hoedown_callbacks*
new(const char*CLASS)
PREINIT:
    struct hoedown_callbacks* ptr;
CODE:
    Newxz(ptr, 1, struct hoedown_callbacks);
    RETVAL = ptr;
OUTPUT:
    RETVAL

struct hoedown_html_renderopt*
html_renderer(struct hoedown_callbacks* self, unsigned int render_flags)
PREINIT:
    struct hoedown_html_renderopt* options;
CODE:
    Newxz(options, 1, struct hoedown_html_renderopt);
    hoedown_html_renderer(self, options, render_flags);
    RETVAL = options;
OUTPUT:
    RETVAL

void
DESTROY(struct hoedown_callbacks* self)
CODE:
    Safefree(self);

MODULE = Text::Markdown::Hoedown    PACKAGE = Text::Markdown::Hoedown::Buffer PREFIX=hoedown_buffer_

struct hoedown_buffer*
hoedown_buffer_new(size_t size)

int
hoedown_buffer_grow(struct hoedown_buffer* self, size_t size)

void
hoedown_buffer_put(struct hoedown_buffer* self, const char*str, size_t length(str))

void
DESTROY(struct hoedown_buffer*self)
CODE:
    hoedown_buffer_free(self);

