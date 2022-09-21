#include "stdafx.h"

//Given two integers left and right that represent the range [left, right],
//return the bitwise AND of all numbers in this range, inclusive.
// 
//
//Example 1:
//Input: left = 5, right = 7
//Output: 4
//
//Example 2:
//Input: left = 0, right = 0
//Output: 0
//
//Example 3:
//Input: left = 1, right = 2147483647
//Output: 0
// 
//Constraints:
//0 <= left <= right <= 231 - 1

namespace Solution2022
{
	namespace BitwiseANDofNumbersRange
	{
		// https://www.youtube.com/watch?v=CY1tnj53L_k
		int rangeBitwiseAnd(int left, int right) {
			int count = 0;
			while (left != right) {
				// as long as the left is not equal to right, the last digit of left and right must include both 1 and 0
				left >>= 1;
				right >>= 1;
				count++;
			}
			return left << count;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
