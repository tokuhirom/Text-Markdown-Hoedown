package Text::Markdown::Hoedown;
use 5.008005;
use strict;
use warnings;
use parent qw(Exporter);

our $VERSION = "0.01";

our @EXPORT = qw(markdown);

use XSLoader;
XSLoader::load(__PACKAGE__, $VERSION);

sub markdown {
    my ($str, $html_options, $extensions, $max_nesting) = @_;
    if (not defined $html_options) {
        $html_options = 0;
    }
    if (not defined $extensions) {
        $extensions = 0;
    }
    if (not defined $max_nesting) {
        $max_nesting = 16;
    }

    my $cb = Text::Markdown::Hoedown::Callbacks->new();
    my $opaque = $cb->html_renderer($html_options);
    my $md = Text::Markdown::Hoedown::Markdown->new($extensions, $max_nesting, $cb, $opaque);
    return $md->render($str);
}

1;
__END__

=encoding utf-8

=head1 NAME

Text::Markdown::Hoedown - hoedown for Perl5

=head1 SYNOPSIS

    use Text::Markdown::Hoedown;

    print markdown(<<'...');
    # foo

    bar

      * hoge
      * fuga
    ...

=head1 DESCRIPTION

Text::Markdown::Hoedown is binding library for hoedown.

hoedown is a forking project from sundown.

=head1 FUNCTIONS

=over 4

=item my $out = markdown($src :Str, $extensions:Int, $options:Int, $max_nesting:Int) :Str

Rendering markdown.

=back

=head1 TODO

=over 4

=item Export constants

=item Document about constants

=item Document about low level APIs

=back

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

