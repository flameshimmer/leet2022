#include "stdafx.h"

//Given two integers dividend and divisor, divide two integers without using
//multiplication, division, and mod operator.
//The integer division should truncate toward zero, which means losing its
//fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would
//be truncated to -2.
//Return the quotient after dividing dividend by divisor.
//
//Note: Assume we are dealing with an environment that could only store integers
//within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if
//the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the
//quotient is strictly less than -231, then return -231.
// 
//
//Example 1:
//Input: dividend = 10, divisor = 3
//Output: 3
//Explanation: 10/3 = 3.33333.. which is truncated to 3.
//
//Example 2:
//Input: dividend = 7, divisor = -3
//Output: -2
//Explanation: 7/-3 = -2.33333.. which is truncated to -2.
// 
//Constraints:
//-231 <= dividend, divisor <= 231 - 1
//divisor != 0

namespace Solution2022
{
	namespace DivideTwoIntegers
	{
	    int divide(int A, int B) {
			if (A == INT_MIN && B == -1) { return INT_MAX; }

			long long a = labs(A);
			long long b = labs(B);
			long long result = 0;
			int sign = (A > 0) ^ (B > 0) ? -1 : 1;

			while (a >= b) {
				long long tmp = b;
				long long m = 1; // Note that this should start from 1 instead of 0!
				while (a >= tmp << 1) {
					tmp <<= 1;
					m <<= 1;
				}
				a -= tmp;
				result += m;
			}
			return sign * result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
