#include "stdafx.h"

//Given two integers num1 and num2, return the sum of the two integers.
// 
//
//Example 1:
//Input: num1 = 12, num2 = 5
//Output: 17
//Explanation: num1 is 12, num2 is 5, and their sum is 12 + 5 = 17, so 17 is
//returned.
//
//Example 2:
//Input: num1 = -10, num2 = 4
//Output: -6
//Explanation: num1 + num2 = -6, so -6 is returned.
// 
//Constraints:
//-100 <= num1, num2 <= 100

namespace Solution2022
{
	namespace AddTwoIntegers
	{
		namespace BitManipulation {
			int sum(int x, int y) {
				if (y == 0)
					return x;
				else if (x < 0 && y < 0) {
					int sumVal = ~x ^ ~y;
					int carry = (~x & ~y) << 1;
					//负数的表现是反码加1
					return ~sum(sum(sumVal, carry), 1);
				}
				else {
					int sumVal = x ^ y;
					int carry = (x & y) << 1;
					return sum(sumVal, carry);
				}

			}
		}

		int sum(int num1, int num2) {
			return num1 + num2;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
