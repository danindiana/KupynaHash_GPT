#!/usr/bin/perl
use strict;
use warnings;

my $sbox = "A8 43 5F 06 ..."; # Place the full S-box string here

# Convert string into an array
my @values = split(/\s+/, $sbox);

# Print C++ array
print "static const uint8_t KALYNA_SBOX[256] = {\n    ";
my $count = 0;
foreach my $value (@values) {
    print "0x$value, ";
    $count++;
    if ($count % 16 == 0) {
        print "\n    ";
    }
}
print "\n};\n";
