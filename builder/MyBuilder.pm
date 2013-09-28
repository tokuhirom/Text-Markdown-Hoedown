package builder::MyBuilder;
use strict;
use warnings;
use utf8;
use 5.010_001;

use parent qw(Module::Build);
use File::pushd;

sub new {
    my $class = shift;
    $class->SUPER::new(
        @_,
        c_source => [qw(hoedown/src/)],
    );
}

sub ACTION_code {
    my $self = shift;
    $self->SUPER::ACTION_code();
}

1;

