use strict;
use Data::Dumper;
use FileHandle;
use File::Basename;
use JSON;
 

my $dirname = 'problemIndex';
opendir(DIR, $dirname) or die "Could not open $dirname\n";


open OUT, ">problems" or die;
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


# use strict;
# use warnings;

# open IN, "<./data" or die;
# my @lines = <IN>;
# close IN;

# my $template="#include \"stdafx.h\"
# // 
# namespace Solution2022
# {
# 	namespace \$\$PROBLEM\$\$
# 	{
# 		void Main() {
# 			string test = \"tst test test\";
# 			print(test);
# 		}
# 	}
# }
# ";

# open OUT1, ">./out1" or die;
# open OUT2, ">./out2" or die;
# for my $line (@lines)
# {
# 	chomp $line;
# 	if ($line =~ m/^\s*\d+\.\s(.*)\s*$/)
# 	{
# 		$line = $1;
# 		$line =~ s/\s//g;
# 		$line =~ s/\-//g;
# 		$line =~ s/\'//g;
# 		$line =~ s/\://g;
# 		$line =~ s/\`//g;
# 		$line =~ s/\(.*\)//g;
# 		$line =~ s/\=//g;
# 		$line =~ s/3/Three/g;
# 		$line =~ s/2/Two/g;
# 		$line =~ s/4/Four/g;
# 		$line =~ s/1/One/g;
# 		$line =~ s/5/Five/g;
# 		$line =~ s/6/Six/g;
# 		$line =~ s/7/Seven/g;
# 		$line =~ s/8/Eight/g;
# 		$line =~ s/9/Nine/g;
# 		$line =~ s/0/Zero/g;
# 		print "$line\n";
# 		print OUT1 "//Solution2022::". $line."::Main();\n";
# 		print OUT2 "namespace ". $line."{ void Main(); }\n";
# 		my $content = $template;
# 		$content =~ s/\$\$PROBLEM\$\$/$line/g;
# 		my $cppFileName = "C:\\Users\\flame\\OneDrive\\Desktop\\2022\\Leet2022\\" . $line . ".cpp";
# 		print "$cppFileName\n";
# 		open OUT, ">$cppFileName" or die "Can't open file $cppFileName for write!\n";
# 		print OUT $content;
# 		close OUT;
# 	}
# }

# print "\n\nCompleted!\n\n\n";
