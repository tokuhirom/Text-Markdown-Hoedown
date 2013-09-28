# NAME

Text::Markdown::Hoedown - hoedown for Perl5

# SYNOPSIS

    use Text::Markdown::Hoedown;

    print markdown(<<'...');
    # foo

    bar

      * hoge
      * fuga
    ...

# DESCRIPTION

Text::Markdown::Hoedown is binding library for hoedown.

hoedown is a forking project from sundown.

# FUNCTIONS

- ` my $out = markdown($src :Str, $html_options:Int, $extensions:Int, $max_nesting:Int) :Str `

    Rendering markdown.

    `$extensions` and `$html_options` are bit flags.
    You can use the flags by '|' operator.

    `$html_options` flags are following:

        typedef enum {
            HOEDOWN_HTML_SKIP_HTML = (1 << 0),
            HOEDOWN_HTML_SKIP_STYLE = (1 << 1),
            HOEDOWN_HTML_SKIP_IMAGES = (1 << 2),
            HOEDOWN_HTML_SKIP_LINKS = (1 << 3),
            HOEDOWN_HTML_EXPAND_TABS = (1 << 4),
            HOEDOWN_HTML_SAFELINK = (1 << 5),
            HOEDOWN_HTML_TOC = (1 << 6),
            HOEDOWN_HTML_HARD_WRAP = (1 << 7),
            HOEDOWN_HTML_USE_XHTML = (1 << 8),
            HOEDOWN_HTML_ESCAPE = (1 << 9),
            HOEDOWN_HTML_PRETTIFY = (1 << 10)
        } hoedown_html_render_mode;

    Etensions flags is following.

        enum hoedown_extensions {
            HOEDOWN_EXT_NO_INTRA_EMPHASIS = (1 << 0),
            HOEDOWN_EXT_TABLES = (1 << 1),
            HOEDOWN_EXT_FENCED_CODE = (1 << 2),
            HOEDOWN_EXT_AUTOLINK = (1 << 3),
            HOEDOWN_EXT_STRIKETHROUGH = (1 << 4),
            HOEDOWN_EXT_UNDERLINE = (1 << 5),
            HOEDOWN_EXT_SPACE_HEADERS = (1 << 6),
            HOEDOWN_EXT_SUPERSCRIPT = (1 << 7),
            HOEDOWN_EXT_LAX_SPACING = (1 << 8),
            HOEDOWN_EXT_DISABLE_INDENTED_CODE = (1 << 9),
            HOEDOWN_EXT_HIGHLIGHT = (1 << 10),
            HOEDOWN_EXT_FOOTNOTES = (1 << 11),
            HOEDOWN_EXT_QUOTE = (1 << 12)
        };

    All `HOEDOWN_*` constants are exported by default.

# TODO

- Document about low level APIs

# HACKING

`hoedown/` directory is managed by git subtree.

You can pull the modifications from upstream by following command:

     git subtree pull --prefix=hoedown git@github.com:hoedown/hoedown.git master

# LICENSE

Copyright (C) tokuhirom.

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself.

# AUTHOR

tokuhirom <tokuhirom@gmail.com>
