use strict;
use warnings;
use utf8;
use Test::More;
use Text::Markdown::Hoedown;

open my $fh, '<', 'lib/Text/Markdown/Hoedown.xs';
while (<$fh>) {
    if (/tmh_cb_([a-z0-9_]+)/) {
        can_ok(Text::Markdown::Hoedown::Callbacks::, $1);
    }
}

done_testing;

