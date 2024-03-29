#include "stdafx.h"

//Given an array of strings words and a width maxWidth, format the text such that
//each line has exactly maxWidth characters and is fully (left and right)
//justified.
//You should pack your words in a greedy approach; that is, pack as many words as
//you can in each line. Pad extra spaces ' ' when necessary so that each line has
//exactly maxWidth characters.
//Extra spaces between words should be distributed as evenly as possible. If the
//number of spaces on a line does not divide evenly between words, the empty
//slots on the left will be assigned more spaces than the slots on the right.
//For the last line of text, it should be left-justified, and no extra space is
//inserted between words.
//
//Note:
//A word is defined as a character sequence consisting of non-space characters
//only.
//Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
//The input array words contains at least one word.
// 
//
//Example 1:
//Input: words = ["This", "is", "an", "example", "of", "text", "justification."],
//maxWidth = 16
//Output:
//[
//   "This    is    an",
//   "example  of text",
//   "justification.  "
//]
//
//Example 2:
//Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
//Output:
//[
//  "What   must   be",
//  "acknowledgment  ",
//  "shall be        "
//]
//Explanation: 
//Note that the last line is "shall be    " instead of "shall    
//be", because the last line must be left-justified instead of fully-justified.
//
//Note that the second line is also left-justified because it contains only one
//word.
//
//Example 3:
//["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"],
//maxWidth = 20
//Output:
//[
//  "Science  is  what we",
//  "understand      well",
//  "enough to explain to",
//  "a  computer.  Art is",
//  "everything  else  we",
//  "do                  "
//]
// 
//Constraints:
//1 <= words.length <= 300
//1 <= words[i].length <= 20
//words[i] consists of only English letters and symbols.
//1 <= maxWidth <= 100
//words[i].length <= maxWidth

namespace Solution2022
{
	namespace TextJustification
	{
		vector<string> fullJustify(vector<string>& words, int maxWidth) {
			vector<string> result;
			int len = words.size();
			int k = 0;

			for (int i = 0; i < len; i += k) {
				int curWidth = 0;
				for (k = 0; i + k < len && curWidth + words[i + k].size() <= maxWidth - k; k++) {
					curWidth += words[i + k].size();
				}
				
				string line = words[i];
				for (int j = 0; j < k - 1; j++) {
					if (i + k >= len) { line += " "; }
					else {
						int spaceLen = (maxWidth - curWidth) / (k - 1) + (j < (maxWidth - curWidth) % (k - 1));
						line += string(spaceLen, ' ');
					}
					line += words[i + 1 + j];
				}
				line += string(maxWidth - line.size(), ' ');
				result.push_back(line);
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
