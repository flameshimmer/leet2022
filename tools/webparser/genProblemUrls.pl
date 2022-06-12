use strict;
use Data::Dumper;
use FileHandle;
use File::Basename;
use JSON;
use utf8;
binmode STDOUT, ':utf8';
 

# my $dir = 'problemIndex';
# foreach my $fp (glob("*")) {	
#     local $/ = undef;
#     my $json_str = <$fh>;
#     $fh->close();

#     my $djson = decode_json( $json_str );
#     foreach my $item (@{$djson->{"items"}}) {
#         print $item->{"title"}."\n";
#     }
# }

my $dirname = 'problemIndex';
opendir(DIR, $dirname) or die "Could not open $dirname\n";


open OUT, ">allProblemUrls" or die;
while (my $filename = readdir(DIR)) {
  if ($filename eq "." || $filename eq ".." ) {next;}
  my $path = $dirname . '/' . $filename;
  # print $path;
  open IN, "<$path" or die;
  my $content = <IN>;
  close IN;
  my @decoded_json = @{decode_json($content)};
	foreach my $json (@decoded_json) {
		my $url = $json->{"src"};
		if ((substr $url, -1) eq '/') {chop $url;}
	    print OUT "$url\n";
	    # print "$url\n";
	}  

}
close OUT;

print "\n\nCompleted!\n";
