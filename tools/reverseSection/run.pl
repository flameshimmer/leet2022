use strict;
use warnings;

open IN, "<./data" or die;
my @lines = <IN>;
close IN;

# This script reverse the section so the most recent block is on top. 

	# //6/1/2022
	# //Solution2022::BinarySearch::Main();
	# //Solution2022::FirstBadVersion::Main();
	# //Solution2022::SearchInsertPosition::Main();

	# //6/2/2022
	# //Solution2022::SquaresofaSortedArray::Main();
	# //Solution2022::RotateArray::Main();
	# //Solution2022::MoveZeroes::Main();

my @all = ();
my $content = "";
for my $line (@lines) {
	if ($line =~ m/^\s*$/) {
		push(@all, $content);
		$content = "";
	} else {
		$content = $content . $line;
	}
}

my @reversedAll = reverse @all;

my $result = join("\n", @reversedAll);
print $result;

open OUT, ">result" or die;
print OUT $result;
close OUT;

print "\n\n\nCompleted!\n\n";
