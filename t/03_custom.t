use strict;
use warnings;
use utf8;
use Test::More;
use Text::Markdown::Hoedown;

my $cb = Text::Markdown::Hoedown::Callbacks->new();
ok $cb;
$cb->doc_header(sub {
    "(header)\n";
});
$cb->normal_text(sub {
    my ($text) = @_;
    qq{(normal_text "$text")};
});
$cb->entity(sub {
    my ($text) = @_;
    qq{(entity "$text")};
});
$cb->header(sub {
    my ($title, $level) = @_;
    qq{(h$level $title)\n};
});
$cb->doc_footer(sub {
    "(footer)\n";
});

my $md = Text::Markdown::Hoedown::Markdown->new(0, 16, $cb);
is $md->render(<<'...'), <<',,,';
# hoge
fuga & hige
...
(header)
(h1 (normal_text "hoge"))
(footer)
,,,

done_testing;

