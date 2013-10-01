
void tmh_cb_blockcode(struct hoedown_buffer *ob, const struct hoedown_buffer *text, const struct hoedown_buffer *lang, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "blockcode", 0);
    
    if (!rcb) { return; }
    
    CB_HEADER("blockcode");
    
        PUSHBUF(text);
    
        PUSHBUF(lang);
    
    CB_FOOTER;
    
}
void tmh_cb_blockquote(struct hoedown_buffer *ob, const struct hoedown_buffer *text, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "blockquote", 0);
    
    if (!rcb) { return; }
    
    CB_HEADER("blockquote");
    
        PUSHBUF(text);
    
    CB_FOOTER;
    
}
void tmh_cb_blockhtml(struct hoedown_buffer *ob,const  struct hoedown_buffer *text, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "blockhtml", 0);
    
    if (!rcb) { return; }
    
    CB_HEADER("blockhtml");
    
        PUSHBUF(text);
    
    CB_FOOTER;
    
}
void tmh_cb_header(struct hoedown_buffer *ob, const struct hoedown_buffer *text, int level, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "header", 0);
    
    if (!rcb) { return; }
    
    CB_HEADER("header");
    
        PUSHBUF(text);
    
        mXPUSHi(level);
    
    CB_FOOTER;
    
}
void tmh_cb_hrule(struct hoedown_buffer *ob, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "hrule", 0);
    
    if (!rcb) { return; }
    
    CB_HEADER("hrule");
    
    CB_FOOTER;
    
}
void tmh_cb_list(struct hoedown_buffer *ob, const struct hoedown_buffer *text, int flags, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "list", 0);
    
    if (!rcb) { return; }
    
    CB_HEADER("list");
    
        PUSHBUF(text);
    
        mXPUSHi(flags);
    
    CB_FOOTER;
    
}
void tmh_cb_listitem(struct hoedown_buffer *ob, const struct hoedown_buffer *text, int flags, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "listitem", 0);
    
    if (!rcb) { return; }
    
    CB_HEADER("listitem");
    
        PUSHBUF(text);
    
        mXPUSHi(flags);
    
    CB_FOOTER;
    
}
void tmh_cb_paragraph(struct hoedown_buffer *ob, const struct hoedown_buffer *text, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "paragraph", 0);
    
    if (!rcb) { return; }
    
    CB_HEADER("paragraph");
    
        PUSHBUF(text);
    
    CB_FOOTER;
    
}
void tmh_cb_table(struct hoedown_buffer *ob, const struct hoedown_buffer *header, const struct hoedown_buffer *body, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "table", 0);
    
    if (!rcb) { return; }
    
    CB_HEADER("table");
    
        PUSHBUF(header);
    
        PUSHBUF(body);
    
    CB_FOOTER;
    
}
void tmh_cb_table_row(struct hoedown_buffer *ob, const struct hoedown_buffer *text, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "table_row", 0);
    
    if (!rcb) { return; }
    
    CB_HEADER("table_row");
    
        PUSHBUF(text);
    
    CB_FOOTER;
    
}
void tmh_cb_table_cell(struct hoedown_buffer *ob, const struct hoedown_buffer *text, int flags, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "table_cell", 0);
    
    if (!rcb) { return; }
    
    CB_HEADER("table_cell");
    
        PUSHBUF(text);
    
        mXPUSHi(flags);
    
    CB_FOOTER;
    
}
void tmh_cb_footnotes(struct hoedown_buffer *ob, const struct hoedown_buffer *text, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "footnotes", 0);
    
    if (!rcb) { return; }
    
    CB_HEADER("footnotes");
    
        PUSHBUF(text);
    
    CB_FOOTER;
    
}
void tmh_cb_footnote_def(struct hoedown_buffer *ob, const struct hoedown_buffer *text, unsigned int num, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "footnote_def", 0);
    
    if (!rcb) { return; }
    
    CB_HEADER("footnote_def");
    
        PUSHBUF(text);
    
        mXPUSHu(num);
    
    CB_FOOTER;
    
}
int tmh_cb_autolink(struct hoedown_buffer *ob, const struct hoedown_buffer *link, enum hoedown_autolink type, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "autolink", 0);
    
    if (!rcb) { return 0; }
    
    CB_HEADER("autolink");
    
        PUSHBUF(link);
    
        mXPUSHi(type);
    
    CB_FOOTER;
    
    return is_null ? 0 : 1;
    
}
int tmh_cb_codespan(struct hoedown_buffer *ob, const struct hoedown_buffer *text, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "codespan", 0);
    
    if (!rcb) { return 0; }
    
    CB_HEADER("codespan");
    
        PUSHBUF(text);
    
    CB_FOOTER;
    
    return is_null ? 0 : 1;
    
}
int tmh_cb_double_emphasis(struct hoedown_buffer *ob, const struct hoedown_buffer *text, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "double_emphasis", 0);
    
    if (!rcb) { return 0; }
    
    CB_HEADER("double_emphasis");
    
        PUSHBUF(text);
    
    CB_FOOTER;
    
    return is_null ? 0 : 1;
    
}
int tmh_cb_emphasis(struct hoedown_buffer *ob, const struct hoedown_buffer *text, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "emphasis", 0);
    
    if (!rcb) { return 0; }
    
    CB_HEADER("emphasis");
    
        PUSHBUF(text);
    
    CB_FOOTER;
    
    return is_null ? 0 : 1;
    
}
int tmh_cb_underline(struct hoedown_buffer *ob, const struct hoedown_buffer *text, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "underline", 0);
    
    if (!rcb) { return 0; }
    
    CB_HEADER("underline");
    
        PUSHBUF(text);
    
    CB_FOOTER;
    
    return is_null ? 0 : 1;
    
}
int tmh_cb_highlight(struct hoedown_buffer *ob, const struct hoedown_buffer *text, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "highlight", 0);
    
    if (!rcb) { return 0; }
    
    CB_HEADER("highlight");
    
        PUSHBUF(text);
    
    CB_FOOTER;
    
    return is_null ? 0 : 1;
    
}
int tmh_cb_quote(struct hoedown_buffer *ob, const struct hoedown_buffer *text, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "quote", 0);
    
    if (!rcb) { return 0; }
    
    CB_HEADER("quote");
    
        PUSHBUF(text);
    
    CB_FOOTER;
    
    return is_null ? 0 : 1;
    
}
int tmh_cb_image(struct hoedown_buffer *ob, const struct hoedown_buffer *link, const struct hoedown_buffer *title, const struct hoedown_buffer *alt, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "image", 0);
    
    if (!rcb) { return 0; }
    
    CB_HEADER("image");
    
        PUSHBUF(link);
    
        PUSHBUF(title);
    
        PUSHBUF(alt);
    
    CB_FOOTER;
    
    return is_null ? 0 : 1;
    
}
int tmh_cb_linebreak(struct hoedown_buffer *ob, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "linebreak", 0);
    
    if (!rcb) { return 0; }
    
    CB_HEADER("linebreak");
    
    CB_FOOTER;
    
    return is_null ? 0 : 1;
    
}
int tmh_cb_link(struct hoedown_buffer *ob, const struct hoedown_buffer *link, const struct hoedown_buffer *title, const struct hoedown_buffer *content, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "link", 0);
    
    if (!rcb) { return 0; }
    
    CB_HEADER("link");
    
        PUSHBUF(link);
    
        PUSHBUF(title);
    
        PUSHBUF(content);
    
    CB_FOOTER;
    
    return is_null ? 0 : 1;
    
}
int tmh_cb_raw_html_tag(struct hoedown_buffer *ob, const struct hoedown_buffer *tag, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "raw_html_tag", 0);
    
    if (!rcb) { return 0; }
    
    CB_HEADER("raw_html_tag");
    
        PUSHBUF(tag);
    
    CB_FOOTER;
    
    return is_null ? 0 : 1;
    
}
int tmh_cb_triple_emphasis(struct hoedown_buffer *ob, const struct hoedown_buffer *text, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "triple_emphasis", 0);
    
    if (!rcb) { return 0; }
    
    CB_HEADER("triple_emphasis");
    
        PUSHBUF(text);
    
    CB_FOOTER;
    
    return is_null ? 0 : 1;
    
}
int tmh_cb_strikethrough(struct hoedown_buffer *ob, const struct hoedown_buffer *text, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "strikethrough", 0);
    
    if (!rcb) { return 0; }
    
    CB_HEADER("strikethrough");
    
        PUSHBUF(text);
    
    CB_FOOTER;
    
    return is_null ? 0 : 1;
    
}
int tmh_cb_superscript(struct hoedown_buffer *ob, const struct hoedown_buffer *text, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "superscript", 0);
    
    if (!rcb) { return 0; }
    
    CB_HEADER("superscript");
    
        PUSHBUF(text);
    
    CB_FOOTER;
    
    return is_null ? 0 : 1;
    
}
int tmh_cb_footnote_ref(struct hoedown_buffer *ob, unsigned int num, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "footnote_ref", 0);
    
    if (!rcb) { return 0; }
    
    CB_HEADER("footnote_ref");
    
        mXPUSHu(num);
    
    CB_FOOTER;
    
    return is_null ? 0 : 1;
    
}
void tmh_cb_entity(struct hoedown_buffer *ob, const struct hoedown_buffer *entity, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "entity", 0);
    
    if (!rcb) { return; }
    
    CB_HEADER("entity");
    
        PUSHBUF(entity);
    
    CB_FOOTER;
    
}
void tmh_cb_normal_text(struct hoedown_buffer *ob, const struct hoedown_buffer *text, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "normal_text", 0);
    
    if (!rcb) { return; }
    
    CB_HEADER("normal_text");
    
        PUSHBUF(text);
    
    CB_FOOTER;
    
}
void tmh_cb_doc_header(struct hoedown_buffer *ob, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "doc_header", 0);
    
    if (!rcb) { return; }
    
    CB_HEADER("doc_header");
    
    CB_FOOTER;
    
}
void tmh_cb_doc_footer(struct hoedown_buffer *ob, void *opaque) {
    dTHX; dSP; bool is_null = 0;
    SV** rcb = hv_fetchs((HV*)opaque, "doc_footer", 0);
    
    if (!rcb) { return; }
    
    CB_HEADER("doc_footer");
    
    CB_FOOTER;
    
}
