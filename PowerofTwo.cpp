#include "stdafx.h"

//Given an integer n, return true if it is a power of two. Otherwise, return
//false.
//An integer n is a power of two, if there exists an integer x such that n == 2x.
// 
//
//Example 1:
//Input: n = 1
//Output: true
//Explanation: 20 = 1
//
//Example 2:
//Input: n = 16
//Output: true
//Explanation: 24 = 16
//
//Example 3:
//Input: n = 3
//Output: false
// 
//Constraints:
//-231 <= n <= 231 - 1
// 
//Follow up: Could you solve it without loops/recursion?

namespace Solution2022
{
	namespace PowerofTwo
	{
		bool isPowerOfTwo(int n) {
			return (n > 0) && (n & (n - 1)) == 0;
		}

		bool isPowerOfTwoLog(int n) {
			double d = log10(n) / log10(2);
			return n > 0 && floor(d) == ceil(d);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
