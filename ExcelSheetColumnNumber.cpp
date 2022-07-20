#include "stdafx.h"

//Given a string columnTitle that represents the column title as appears in an
//Excel sheet, return its corresponding column number.
//For example:
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28 
//...
// 
//
//Example 1:
//Input: columnTitle = "A"
//Output: 1
//
//Example 2:
//Input: columnTitle = "AB"
//Output: 28
//
//Example 3:
//Input: columnTitle = "ZY"
//Output: 701
// 
//Constraints:
//1 <= columnTitle.length <= 7
//columnTitle consists only of uppercase English letters.
//columnTitle is in the range ["A", "FXSHRXW"].

namespace Solution2022
{
	namespace ExcelSheetColumnNumber
	{
	    int titleToNumber(string columnTitle) {
			int result = 0;
			for (char c : columnTitle) {
				result = result * 26 + (c - 'A' + 1); // Note: A is 1, not 0! So need to add 1.
			}
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
