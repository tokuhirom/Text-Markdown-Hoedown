#!/usr/bin/env perl
use strict;
use warnings;
use utf8;
use 5.010000;
use autodie;
use Text::MicroTemplate;

my $CB_C = <<'...';
? my @callbacks = @_;

? for my $cb (@callbacks) {
<?= $cb->{type} ?> tmh_cb_<?= $cb->{name} ?>(<?= $cb->{params} ?>) {
    CB_HEADER("<?= $cb->{name} ?>");
    <? for my $a (@{$cb->{args}}) { ?>
        <?= $a ?>;
    <? } ?>
    CB_FOOTER;
    <? if ($cb->{type} eq 'int') { ?>
    return is_null ? 0 : 1;
    <? } ?>
}
? }
...

my $CB_INC = <<'...';
? my @callbacks = @_;

? for my $cb (@callbacks) {
void
<?= $cb->{name} ?>(tmh_callbacks* self, SV *code)
CODE:
    self->callbacks.<?= $cb->{name} ?> = tmh_cb_<?= $cb->{name} ?>;
    hv_stores(self->custom_opaque, "<?= $cb->{name} ?>", newSVsv(code));

? }
...

&main;

sub main {
    my @callbacks = scan_callbacks();
    render_c(@callbacks);
    render_inc(@callbacks);
}

sub render_c {
    my @callbacks = @_;
    my $tmt = Text::MicroTemplate->new(
        template => $CB_C,
        escape_func => sub { shift },
    );
    my $c = (eval $tmt->code())->(@callbacks);
    spew('lib/Text/Markdown/gen.callback.c', $c);
}

sub render_inc {
    my @callbacks = @_;
    my $tmt = Text::MicroTemplate->new(
        template => $CB_INC,
        escape_func => sub { shift },
    );
    my $c = (eval $tmt->code())->(@callbacks);
    spew('lib/Text/Markdown/gen.callback.inc', $c);
}

sub spew {
    my $fname = shift;
    open my $fh, '>', $fname
        or Carp::croak("Can't open '$fname' for writing: '$!'");
    print {$fh} $_[0];
}

sub scan_callbacks {
    open my $fh, '<', 'hoedown/src/markdown.h';
    my $content = do { local $/; <$fh> };
    $content =~ s/struct hoedown_callbacks {(.*?)}//sm or die "Invalid markdown.h";
    my @callbacks;
    for my $line (split /\n/, $1) {
        if ($line =~ /\A\s*(.*?)\s+\(\*(\w+)\)\((.*)\);/) {
            my ($type, $name, $opts) = ($1, $2, $3);
            my @opts = split /,/, $opts;
            shift @opts;
            pop @opts;
            my @args;
            for (@opts) {
                s/\A\s*//;
                s/\s*\z//;
                if ($_ =~ /\Aconst\s+struct hoedown_buffer \*(\w+)\z/) {
                    push @args, "PUSHBUF($1)";
                } elsif ($_ =~ /\Aint (\w+)\z/) {
                    push @args, "mXPUSHi($1)";
                } elsif ($_ =~ /\Aunsigned int (\w+)\z/) {
                    push @args, "mXPUSHu($1)";
                } elsif ($_ =~ /\Aenum hoedown_autolink type\z/) {
                    push @args, "mXPUSHi(type)";
                } else {
                    die "Unknown: $_";
                }
            }

            push @callbacks, +{
                type   => $type,
                name   => $name,
                args   => \@args,
                params => $opts,
            };
        }
    }
    return @callbacks;
}

