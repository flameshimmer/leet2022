#include "stdafx.h"

//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of
//rows like this: (you may want to display this pattern in a fixed font for
//better legibility)
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number
//of rows:
//string convert(string s, int numRows);
// 
//
//Example 1:
//Input: s = "PAYPALISHIRING", numRows = 3
//Output: "PAHNAPLSIIGYIR"
//
//Example 2:
//Input: s = "PAYPALISHIRING", numRows = 4
//Output: "PINALSIGYAHRPI"
//Explanation:
//P     I    N
//A   L S  I G
//Y A   H R
//P     I
//
//Example 3:
//Input: s = "A", numRows = 1
//Output: "A"
// 
//Constraints:
//1 <= s.length <= 1000
//s consists of English letters (lower-case and upper-case), ',' and '.'.
//1 <= numRows <= 1000

namespace Solution2022
{
	namespace ZigzagConversion
	{
	    string convert(string s, int numRows) {
			if (numRows <= 1) { return s; }

			vector<string> results(numRows, "");
			int step = 1;

			int curRow = 0;
			for (char c : s) {
				results[curRow].push_back(c);
				if (curRow == 0) { step = 1; }
				else if (curRow == numRows - 1) { step = -1; }
				curRow += step;
			}

			string result = "";
			for (string& s : results) {
				result += s;
			}
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
