#include "stdafx.h"

//Given two non-negative integers low and high. Return the count of odd numbers
//between low and high (inclusive).
// 
//
//Example 1:
//Input: low = 3, high = 7
//Output: 3
//Explanation: The odd numbers between 3 and 7 are [3,5,7].
//
//Example 2:
//Input: low = 8, high = 10
//Output: 1
//Explanation: The odd numbers between 8 and 10 are [9].
// 
//Constraints:
//0 <= low <= high <= 10^9

namespace Solution2022
{
	namespace CountOddNumbersinanIntervalRange
	{
		// The number of odds between [0 .. n) is n/2;
		// The number of odds between [a, b] is the odds in range [0 .. b+1) minus the odds in range [0 .. a)
		int countOdds(int low, int high) {
			return (high + 1) / 2 - low / 2;
		}

		namespace Another {
			int countOdds(int low, int high) {
				int len = high - low + 1;
				int result = len / 2;
				if (len % 2) {
					result += low % 2 ? 1 : 0;
				}
				return result;
			}
		}
	    

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
