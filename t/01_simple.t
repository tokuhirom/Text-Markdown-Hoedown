use strict;
use Test::More;

use Text::Markdown::Hoedown;
use Encode;

ok HOEDOWN_EXT_NO_INTRA_EMPHASIS;

isa_ok(Text::Markdown::Hoedown::Callbacks->new(), 'Text::Markdown::Hoedown::Callbacks');
is(markdown("# foo"), "<h1>foo</h1>\n");
{
    use utf8;
    my $aiu = markdown("# あいう");
    ok Encode::is_utf8($aiu);
    is($aiu, "<h1>あいう</h1>\n");
}

is(markdown("http://mixi.jp", 0, HOEDOWN_EXT_AUTOLINK), qq{<p><a href="http://mixi.jp">http://mixi.jp</a></p>\n});

done_testing;

