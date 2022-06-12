use strict;
use Data::Dumper;
use FileHandle;
use File::Basename;
use JSON;
 

my $dirname = 'problems';
opendir(DIR, $dirname) or die "Could not open $dirname\n";


my @jsons = ();
while (my $filename = readdir(DIR)) {
  if ($filename !~ m/data_/) {next;}
  my $path = $dirname . '/' . $filename;
  print "$path\n";
  open IN, "<$path" or die;
  my $content = <IN>;
  close IN;
  my $json = decode_json($content);
  push(@jsons, $json);
		# my $title = $json->{"title"};
		# my $desc = $json->{"description"};
	 #    # print "$title\n";
}



my $template="#include \"stdafx.h\"
\$\$DESC\$\$

namespace Solution2022
{
	namespace \$\$PROBLEM\$\$
	{
\$\$CODE\$\$
		void Main() {
			string test = \"tst test test\";
			print(test);
		}
	}
}
";

open OUT1, ">./out1" or die;
open OUT2, ">./out2" or die;
for my $json (@jsons)
{
		my $title = $json->{"title"};
		if ($title !~ m/\d+\.\s*(.+)/) {next;}
		$title = $1;
		$title =~ s/\s//g;
		$title =~ s/\-//g;
		$title =~ s/\'//g;
		$title =~ s/\://g;
		$title =~ s/\`//g;
		$title =~ s/\(.*\)//g;
		$title =~ s/\=//g;
		$title =~ s/3/Three/g;
		$title =~ s/2/Two/g;
		$title =~ s/4/Four/g;
		$title =~ s/1/One/g;
		$title =~ s/5/Five/g;
		$title =~ s/6/Six/g;
		$title =~ s/7/Seven/g;
		$title =~ s/8/Eight/g;
		$title =~ s/9/Nine/g;
		$title =~ s/0/Zero/g;
		print "$title\n";
		print OUT1 "//Solution2022::". $title."::Main();\n";
		print OUT2 "namespace ". $title."{ void Main(); }\n";

# Process and format description
		my $desc = $json->{"description"};
		$desc =~ s/\xa0/ /g;
		my @descLines = split('\n', $desc); 
		
		my $descContent = "";
		for my $descLine (@descLines) {
			$descContent = $descContent . wrapText($descLine, 80);
		}

		$descContent =~ s/\n{2,}/\n/g;
		$descContent =~ s/Example/\nExample/g;
		$descContent =~ s/\n{2,}Example/\n\nExample/g;

		$descContent =~ s/Note/\nNote/g;
		$descContent =~ s/\n{2,}Note/\n\nNote/g;

		$descContent =~ s/NOTE/\nNOTE/g;
		$descContent =~ s/\n{2,}NOTE/\n\nNOTE/g;
		$descContent =~ s/\n/\n\/\//g;


# Process and format code
		my $code = $json->{"functionSig"};
		$code =~ s/\xa0/ /g;
		my @codeLines = split('\n', $code); 
		my $filteredCode = "";
		for my $codeLine (@codeLines) {
			if ($codeLine =~ m/^\s*\d+\s*$/) {next;}
			if ($codeLine =~ m/^\s*class Solution {\s*$/) {next;}
			if ($codeLine =~ m/^\s*};\s*$/) {next;}
			if ($codeLine =~ m/^\s*public:\s*$/) {next;}
			# print "$codeLine\n";
			$filteredCode = $filteredCode . "\t" . $codeLine . "\n";
		}


		my $content = $template;
		$content =~ s/\$\$PROBLEM\$\$/$title/g;
		$content =~ s/\$\$CODE\$\$/$filteredCode/g;
		$content =~ s/\$\$DESC\$\$/$descContent/g;
		
		my $cppFileName = "$title.cpp";
		# print "$cppFileName\n";
		open OUT, ">./cpps/$cppFileName" or die "Can't open file $cppFileName for write!\n";
		print OUT $content;
		close OUT;
}

print "\n\nCompleted!\n\n\n";



 sub wrapText{
	my $text = shift;
	my $max = shift;
	
	my $result = "";
	my $success = 1;
	while ($text) {
	    if (length $text <= $max) {
	        $result = $result . "\n". $text;
	        last;
	    }
	    my $prefix = substr $text, 0, $max;
	    my $loc = rindex $prefix, ' ';
	 
	    if ($loc == -1) {
	        print "Error: We found a word which is longer than $max, $prefix\n";
	        $success = 0;
	        last;
	    }
	    my $str = substr $text, 0, $loc, '';
	   	$result = $result . "\n". $str;
	    substr $text, 0, 1, '';
	}
		if ($success == 1) {return $result;}
    return wrapText($text, $max + 5);
 }