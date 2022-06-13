#include "stdafx.h"

//You are given two strings firstString and secondString that are 0-indexed and
//consist only of lowercase English letters. Count the number of index quadruples
//(i,j,a,b) that satisfy the following conditions:
//0 <= i <= j < firstString.length
//0 <= a <= b < secondString.length
//The substring of firstString that starts at the ith character and ends at the
//jth character (inclusive) is equal to the substring of secondString that starts
//at the ath character and ends at the bth character (inclusive).
//j - a is the minimum possible value among all quadruples that satisfy the
//previous conditions.
//Return the number of such quadruples.
// 
//
//Example 1:
//Input: firstString = "abcd", secondString = "bccda"
//Output: 1
//Explanation: The quadruple (0,0,4,4) is the only one that satisfies all the
//conditions and minimizes j - a.
//
//Example 2:
//Input: firstString = "ab", secondString = "cd"
//Output: 0
//Explanation: There are no quadruples satisfying all the conditions.
// 
//Constraints:
//1 <= firstString.length, secondString.length <= 2 * 105
//Both strings consist only of lowercase English letters.

namespace Solution2022
{
	namespace CountPairsofEqualSubstringsWithMinimumDifference
	{
/*
	    int countQuadruples(string firstString, string secondString) {
	        
	    }

*/

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
