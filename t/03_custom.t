use strict;
use warnings;
use utf8;
use Test::More;
use Text::Markdown::Hoedown;
use B qw(perlstring);

my $cb = Text::Markdown::Hoedown::Callbacks->new();
ok $cb;
$cb->doc_header(sub {
    join('',
        "<doctype html>\n",
        "<html>\n",
    );
});
$cb->normal_text(sub {
    my ($text) = @_;
    $text;
});
$cb->entity(sub {
    my ($text) = @_;
    $text;
});
$cb->header(sub {
    my ($title, $level) = @_;
    qq{<h$level>$title</h$level>\n};
});
$cb->codespan(sub {
    my ($body) = @_;
    qq{<code>$body</code>\n};
});
$cb->paragraph(sub {
    my ($text) = @_;
    "<p>$text</p>\n";
});
$cb->autolink(sub {
    my ($text) = @_;
    qq{<a href="$text">$text</a>};
});
$cb->linebreak(sub {
    '<br>';
});
$cb->underline(sub {
    my ($text) = @_;
    qq{<u>$text</u>};
});
$cb->raw_html_tag(sub {
    my ($text) = @_;
    $text;
});
$cb->image(sub {
    my ($link, $title, $alt) = @_;
    if (defined $title) {
        qq!<img title="$title" alt="$alt" src="$link">!;
    } else {
        qq!<img alt="$alt" src="$link">!;
    }
});
$cb->doc_footer(sub {
    "</body></html>\n";
});

my $md = Text::Markdown::Hoedown::Markdown->new(HOEDOWN_EXT_AUTOLINK|HOEDOWN_EXT_UNDERLINE, 16, $cb);
is $md->render(<<'...'), <<',,,';
# hoge
fuga & hige
http://mixi.jp/
`hoge()`
<b>bold</b>
_under_
![Alt text](/path/to/img.jpg "Optional title")
![Alt text](/path/to/img.jpg)
...
<doctype html>
<html>
<h1>hoge</h1>
<p>fuga & hige
<a href="http://mixi.jp/">http://mixi.jp/</a>
<code>hoge()</code>

<b>bold</b>
_under_
<img title="Optional title" alt="Alt text" src="/path/to/img.jpg">
<img alt="Alt text" src="/path/to/img.jpg"></p>
</body></html>
,,,

done_testing;

