package Text::Markdown::Hoedown::Markdown;
use strict;
use warnings;
use utf8;
use 5.010_001;

sub new {
    my ($class, $extensions, $max_nesting, $callbacks) = @_;
    my $md = _new($class, $extensions, $max_nesting, $callbacks);
    bless [$md, $callbacks], $class;
}

sub render {
    my ($self, $src) = @_;
    return _render($self->[0], $src);
}

sub DESTROY {
    my $self = shift;
    _destroy($self->[0]);
}

1;

