#include "stdafx.h"

//Given an integer n, return the nth digit of the infinite integer sequence [1,
//2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].
// 
//
//Example 1:
//Input: n = 3
//Output: 3
//
//Example 2:
//Input: n = 11
//Output: 0
//Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
//... is a 0, which is part of the number 10.
// 
//Constraints:
//1 <= n <= 231 - 1

namespace Solution2022
{
	namespace NthDigit
	{
	    int findNthDigit(int n) {
			int numLen = 1;
			long long numCount = 9;
			int startNum = 1;

			while (n > numCount * numLen) {
				n -= numCount * numLen;
				numLen++;
				numCount *= 10;
				startNum *= 10;
			}

			startNum += (n - 1) / numLen;
			string num = to_string(startNum);
			return num[(n - 1) % numLen] - '0';
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
