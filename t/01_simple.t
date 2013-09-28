use strict;
use Test::More;

use Text::Markdown::Hoedown;
use Encode;

isa_ok(Text::Markdown::Hoedown::Callbacks->new(), 'Text::Markdown::Hoedown::Callbacks');
is(markdown("# foo"), "<h1>foo</h1>\n");
{
    use utf8;
    my $aiu = markdown("# あいう");
    ok Encode::is_utf8($aiu);
    is($aiu, "<h1>あいう</h1>\n");
}

done_testing;

