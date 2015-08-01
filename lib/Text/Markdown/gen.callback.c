void tmh_cb_blockcode(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_buffer *lang, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "blockcode", 0);

    if (!rcb) { return; }

    CB_HEADER("blockcode");

        PUSHBUF(text);

        PUSHBUF(lang);

    CB_FOOTER;

}
void tmh_cb_blockquote(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "blockquote", 0);

    if (!rcb) { return; }

    CB_HEADER("blockquote");

        PUSHBUF(text);

    CB_FOOTER;

}
void tmh_cb_blockhtml(hoedown_buffer *ob, const  hoedown_buffer *text, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "blockhtml", 0);

    if (!rcb) { return; }

    CB_HEADER("blockhtml");

        PUSHBUF(text);

    CB_FOOTER;

}
void tmh_cb_header(hoedown_buffer *ob, const hoedown_buffer *text, int level, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "header", 0);

    if (!rcb) { return; }

    CB_HEADER("header");

        PUSHBUF(text);

        mXPUSHi(level);

    CB_FOOTER;

}
void tmh_cb_hrule(hoedown_buffer *ob, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "hrule", 0);

    if (!rcb) { return; }

    CB_HEADER("hrule");

    CB_FOOTER;

}
void tmh_cb_list(hoedown_buffer *ob, const hoedown_buffer *text, hoedown_list_flags flags, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "list", 0);

    if (!rcb) { return; }

    CB_HEADER("list");

        PUSHBUF(text);

        mXPUSHi(flags);

    CB_FOOTER;

}
void tmh_cb_listitem(hoedown_buffer *ob, const hoedown_buffer *text, hoedown_list_flags flags, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "listitem", 0);

    if (!rcb) { return; }

    CB_HEADER("listitem");

        PUSHBUF(text);

        mXPUSHi(flags);

    CB_FOOTER;

}
void tmh_cb_paragraph(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "paragraph", 0);

    if (!rcb) { return; }

    CB_HEADER("paragraph");

        PUSHBUF(text);

    CB_FOOTER;

}
void tmh_cb_table(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "table", 0);

    if (!rcb) { return; }

    CB_HEADER("table");

        PUSHBUF(content);

    CB_FOOTER;

}
void tmh_cb_table_header(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "table_header", 0);

    if (!rcb) { return; }

    CB_HEADER("table_header");

        PUSHBUF(content);

    CB_FOOTER;

}
void tmh_cb_table_body(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "table_body", 0);

    if (!rcb) { return; }

    CB_HEADER("table_body");

        PUSHBUF(content);

    CB_FOOTER;

}
void tmh_cb_table_row(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "table_row", 0);

    if (!rcb) { return; }

    CB_HEADER("table_row");

        PUSHBUF(content);

    CB_FOOTER;

}
void tmh_cb_table_cell(hoedown_buffer *ob, const hoedown_buffer *content, hoedown_table_flags flags, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "table_cell", 0);

    if (!rcb) { return; }

    CB_HEADER("table_cell");

        PUSHBUF(content);

        mXPUSHi(flags);

    CB_FOOTER;

}
void tmh_cb_footnotes(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "footnotes", 0);

    if (!rcb) { return; }

    CB_HEADER("footnotes");

        PUSHBUF(content);

    CB_FOOTER;

}
void tmh_cb_footnote_def(hoedown_buffer *ob, const hoedown_buffer *content, unsigned int num, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "footnote_def", 0);

    if (!rcb) { return; }

    CB_HEADER("footnote_def");

        PUSHBUF(content);

        mXPUSHu(num);

    CB_FOOTER;

}
int tmh_cb_autolink(hoedown_buffer *ob, const hoedown_buffer *link, hoedown_autolink_type type, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "autolink", 0);

    if (!rcb) { return 0; }

    CB_HEADER("autolink");

        PUSHBUF(link);

        mXPUSHi(type);

    CB_FOOTER;

    return is_null ? 0 : 1;

}
int tmh_cb_codespan(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "codespan", 0);

    if (!rcb) { return 0; }

    CB_HEADER("codespan");

        PUSHBUF(text);

    CB_FOOTER;

    return is_null ? 0 : 1;

}
int tmh_cb_double_emphasis(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "double_emphasis", 0);

    if (!rcb) { return 0; }

    CB_HEADER("double_emphasis");

        PUSHBUF(text);

    CB_FOOTER;

    return is_null ? 0 : 1;

}
int tmh_cb_emphasis(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "emphasis", 0);

    if (!rcb) { return 0; }

    CB_HEADER("emphasis");

        PUSHBUF(text);

    CB_FOOTER;

    return is_null ? 0 : 1;

}
int tmh_cb_underline(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "underline", 0);

    if (!rcb) { return 0; }

    CB_HEADER("underline");

        PUSHBUF(text);

    CB_FOOTER;

    return is_null ? 0 : 1;

}
int tmh_cb_highlight(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "highlight", 0);

    if (!rcb) { return 0; }

    CB_HEADER("highlight");

        PUSHBUF(text);

    CB_FOOTER;

    return is_null ? 0 : 1;

}
int tmh_cb_quote(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "quote", 0);

    if (!rcb) { return 0; }

    CB_HEADER("quote");

        PUSHBUF(text);

    CB_FOOTER;

    return is_null ? 0 : 1;

}
int tmh_cb_image(hoedown_buffer *ob, const hoedown_buffer *link, const hoedown_buffer *title, const hoedown_buffer *alt, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "image", 0);

    if (!rcb) { return 0; }

    CB_HEADER("image");

        PUSHBUF(link);

        PUSHBUF(title);

        PUSHBUF(alt);

    CB_FOOTER;

    return is_null ? 0 : 1;

}
int tmh_cb_linebreak(hoedown_buffer *ob, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "linebreak", 0);

    if (!rcb) { return 0; }

    CB_HEADER("linebreak");

    CB_FOOTER;

    return is_null ? 0 : 1;

}
int tmh_cb_link(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_buffer *link, const hoedown_buffer *title, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "link", 0);

    if (!rcb) { return 0; }

    CB_HEADER("link");

        PUSHBUF(content);

        PUSHBUF(link);

        PUSHBUF(title);

    CB_FOOTER;

    return is_null ? 0 : 1;

}
int tmh_cb_math(hoedown_buffer *ob, const hoedown_buffer *text, int displaymode, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "math", 0);

    if (!rcb) { return 0; }

    CB_HEADER("math");

        PUSHBUF(text);

        mXPUSHi(displaymode);

    CB_FOOTER;

    return is_null ? 0 : 1;

}
int tmh_cb_raw_html(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "raw_html", 0);

    if (!rcb) { return 0; }

    CB_HEADER("raw_html");

        PUSHBUF(text);

    CB_FOOTER;

    return is_null ? 0 : 1;

}
int tmh_cb_triple_emphasis(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "triple_emphasis", 0);

    if (!rcb) { return 0; }

    CB_HEADER("triple_emphasis");

        PUSHBUF(text);

    CB_FOOTER;

    return is_null ? 0 : 1;

}
int tmh_cb_strikethrough(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "strikethrough", 0);

    if (!rcb) { return 0; }

    CB_HEADER("strikethrough");

        PUSHBUF(text);

    CB_FOOTER;

    return is_null ? 0 : 1;

}
int tmh_cb_superscript(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "superscript", 0);

    if (!rcb) { return 0; }

    CB_HEADER("superscript");

        PUSHBUF(text);

    CB_FOOTER;

    return is_null ? 0 : 1;

}
int tmh_cb_footnote_ref(hoedown_buffer *ob, unsigned int num, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "footnote_ref", 0);

    if (!rcb) { return 0; }

    CB_HEADER("footnote_ref");

        mXPUSHu(num);

    CB_FOOTER;

    return is_null ? 0 : 1;

}
void tmh_cb_entity(hoedown_buffer *ob, const hoedown_buffer *entity, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "entity", 0);

    if (!rcb) { return; }

    CB_HEADER("entity");

        PUSHBUF(entity);

    CB_FOOTER;

}
void tmh_cb_normal_text(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "normal_text", 0);

    if (!rcb) { return; }

    CB_HEADER("normal_text");

        PUSHBUF(text);

    CB_FOOTER;

}
void tmh_cb_doc_header(hoedown_buffer *ob, int inline_render, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "doc_header", 0);

    if (!rcb) { return; }

    CB_HEADER("doc_header");

    mXPUSHi(inline_render);

    CB_FOOTER;

}
void tmh_cb_doc_footer(hoedown_buffer *ob, int inline_render, const hoedown_renderer_data *data) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)data->opaque, "doc_footer", 0);

    if (!rcb) { return; }

    CB_HEADER("doc_footer");

    mXPUSHi(inline_render);

    CB_FOOTER;

}
