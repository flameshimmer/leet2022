#include "stdafx.h"

//Given a rows x cols screen and a sentence represented as a list of strings,
//return the number of times the given sentence can be fitted on the screen.
//The order of words in the sentence must remain unchanged, and a word cannot be
//split into two lines. A single space must separate two consecutive words in a
//line.
// 
//
//Example 1:
//Input: sentence = ["hello","world"], rows = 2, cols = 8
//Output: 1
//Explanation:
//hello---
//world---
//The character '-' signifies an empty space on the screen.
//
//Example 2:
//Input: sentence = ["a", "bcd", "e"], rows = 3, cols = 6
//Output: 2
//Explanation:
//a-bcd- 
//e-a---
//bcd-e-
//The character '-' signifies an empty space on the screen.
//
//Example 3:
//Input: sentence = ["i","had","apple","pie"], rows = 4, cols = 5
//Output: 1
//Explanation:
//i-had
//apple
//pie-i
//had--
//The character '-' signifies an empty space on the screen.
// 
//Constraints:
//1 <= sentence.length <= 100
//1 <= sentence[i].length <= 10
//sentence[i] consists of lowercase English letters.
//1 <= rows, cols <= 2 * 104

namespace Solution2022
{
	namespace SentenceScreenFitting
	{
	    //https://leetcode.com/problems/sentence-screen-fitting/discuss/90845/21ms-18-lines-Java-solution
		
		int wordsTyping(vector<string>& sentence, int rows, int cols) {
			string s = "";
			for (string& sen : sentence) { s += sen + " "; }
			int len = s.size();

			int start = 0;
			for (int i = 0; i < rows; i++) {
				start += cols;
				if (s[start % len] == ' ') { start++; } // if we land on a space, set start to the first non-space forward
				else {
					while (start - 1 >= 0 && s[(start - 1) % len] != ' ') { start--; } // if we land in the middle of a word, backspace start until the previous char is a space
				}
			}
			return start / len;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
