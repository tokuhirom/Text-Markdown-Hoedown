requires 'perl', '5.008001';
requires 'parent';
requires 'Exporter';

on configure => sub {
    requires 'ExtUtils::ParseXS', 3.23;
    requires 'File::pushd';
};

on 'test' => sub {
    requires 'Test::More', '0.98';
};

