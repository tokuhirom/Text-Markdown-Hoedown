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

- ` my $out = markdown($src :Str, $extensions:Int, $options:Int, $max_nesting:Int) :Str `

    Rendering markdown.

# TODO

- Export constants
- Document about constants
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
