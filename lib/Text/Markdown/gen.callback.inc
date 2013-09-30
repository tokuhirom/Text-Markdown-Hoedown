
void
blockcode(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.blockcode = tmh_cb_blockcode;
    hv_stores(self->custom_opaque, "blockcode", newSVsv(code));

void
blockquote(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.blockquote = tmh_cb_blockquote;
    hv_stores(self->custom_opaque, "blockquote", newSVsv(code));

void
blockhtml(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.blockhtml = tmh_cb_blockhtml;
    hv_stores(self->custom_opaque, "blockhtml", newSVsv(code));

void
header(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.header = tmh_cb_header;
    hv_stores(self->custom_opaque, "header", newSVsv(code));

void
hrule(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.hrule = tmh_cb_hrule;
    hv_stores(self->custom_opaque, "hrule", newSVsv(code));

void
list(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.list = tmh_cb_list;
    hv_stores(self->custom_opaque, "list", newSVsv(code));

void
listitem(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.listitem = tmh_cb_listitem;
    hv_stores(self->custom_opaque, "listitem", newSVsv(code));

void
paragraph(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.paragraph = tmh_cb_paragraph;
    hv_stores(self->custom_opaque, "paragraph", newSVsv(code));

void
table(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.table = tmh_cb_table;
    hv_stores(self->custom_opaque, "table", newSVsv(code));

void
table_row(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.table_row = tmh_cb_table_row;
    hv_stores(self->custom_opaque, "table_row", newSVsv(code));

void
table_cell(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.table_cell = tmh_cb_table_cell;
    hv_stores(self->custom_opaque, "table_cell", newSVsv(code));

void
footnotes(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.footnotes = tmh_cb_footnotes;
    hv_stores(self->custom_opaque, "footnotes", newSVsv(code));

void
footnote_def(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.footnote_def = tmh_cb_footnote_def;
    hv_stores(self->custom_opaque, "footnote_def", newSVsv(code));

void
autolink(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.autolink = tmh_cb_autolink;
    hv_stores(self->custom_opaque, "autolink", newSVsv(code));

void
codespan(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.codespan = tmh_cb_codespan;
    hv_stores(self->custom_opaque, "codespan", newSVsv(code));

void
double_emphasis(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.double_emphasis = tmh_cb_double_emphasis;
    hv_stores(self->custom_opaque, "double_emphasis", newSVsv(code));

void
emphasis(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.emphasis = tmh_cb_emphasis;
    hv_stores(self->custom_opaque, "emphasis", newSVsv(code));

void
underline(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.underline = tmh_cb_underline;
    hv_stores(self->custom_opaque, "underline", newSVsv(code));

void
highlight(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.highlight = tmh_cb_highlight;
    hv_stores(self->custom_opaque, "highlight", newSVsv(code));

void
quote(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.quote = tmh_cb_quote;
    hv_stores(self->custom_opaque, "quote", newSVsv(code));

void
image(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.image = tmh_cb_image;
    hv_stores(self->custom_opaque, "image", newSVsv(code));

void
linebreak(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.linebreak = tmh_cb_linebreak;
    hv_stores(self->custom_opaque, "linebreak", newSVsv(code));

void
link(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.link = tmh_cb_link;
    hv_stores(self->custom_opaque, "link", newSVsv(code));

void
raw_html_tag(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.raw_html_tag = tmh_cb_raw_html_tag;
    hv_stores(self->custom_opaque, "raw_html_tag", newSVsv(code));

void
triple_emphasis(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.triple_emphasis = tmh_cb_triple_emphasis;
    hv_stores(self->custom_opaque, "triple_emphasis", newSVsv(code));

void
strikethrough(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.strikethrough = tmh_cb_strikethrough;
    hv_stores(self->custom_opaque, "strikethrough", newSVsv(code));

void
superscript(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.superscript = tmh_cb_superscript;
    hv_stores(self->custom_opaque, "superscript", newSVsv(code));

void
footnote_ref(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.footnote_ref = tmh_cb_footnote_ref;
    hv_stores(self->custom_opaque, "footnote_ref", newSVsv(code));

void
entity(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.entity = tmh_cb_entity;
    hv_stores(self->custom_opaque, "entity", newSVsv(code));

void
normal_text(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.normal_text = tmh_cb_normal_text;
    hv_stores(self->custom_opaque, "normal_text", newSVsv(code));

void
doc_header(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.doc_header = tmh_cb_doc_header;
    hv_stores(self->custom_opaque, "doc_header", newSVsv(code));

void
doc_footer(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.doc_footer = tmh_cb_doc_footer;
    hv_stores(self->custom_opaque, "doc_footer", newSVsv(code));

