package Text::Markdown::Hoedown;
use 5.008005;
use strict;
use warnings;

our $VERSION = "0.01";

use XSLoader;
XSLoader::load(__PACKAGE__, $VERSION);

1;
__END__

=encoding utf-8

=head1 NAME

Text::Markdown::Hoedown - It's new $module

=head1 SYNOPSIS

    use Text::Markdown::Hoedown;

=head1 DESCRIPTION

Text::Markdown::Hoedown is ...

=head1 HACKING

C<hoedown/> directory is managed by git subtree.

You can pull the modifications from upstream by following command:

     git subtree pull --prefix=hoedown git@github.com:hoedown/hoedown.git master

=head1 LICENSE

Copyright (C) tokuhirom.

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself.

=head1 AUTHOR

tokuhirom E<lt>tokuhirom@gmail.comE<gt>

=cut

