#include "stdafx.h"

//Given an integer n, return true if it is a power of four. Otherwise, return
//false.
//An integer n is a power of four, if there exists an integer x such that n == 4x.
// 
//
//Example 1:
//Input: n = 16
//Output: true
//
//Example 2:
//Input: n = 5
//Output: false
//
//Example 3:
//Input: n = 1
//Output: true
// 
//Constraints:
//-231 <= n <= 231 - 1
// 
//Follow up: Could you solve it without loops/recursion?

namespace Solution2022
{
	namespace PowerofFour
	{
	    bool isPowerOfFour(int n) {
			double d = log10(n) / log10(4);
			return n > 0 && floor(d) == ceil(d);
	    }

		namespace Another {
			bool isPowerOfFour(int n) {
				return n > 0 && (n & n - 1) == 0 && (n & 0x55555555) != 0;
			}		
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
