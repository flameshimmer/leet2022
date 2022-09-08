#include "stdafx.h"

//Given two integers a and b, return the sum of the two integers without using
//the operators + and -.
// 
//
//Example 1:
//Input: a = 1, b = 2
//Output: 3
//
//Example 2:
//Input: a = 2, b = 3
//Output: 5
// 
//Constraints:
//-1000 <= a, b <= 1000

namespace Solution2022
{
	namespace SumofTwoIntegers
	{
		int getSum(int a, int b) {
			long long carry; // 64-bit. Why use long long? Otherwise when left shift in line 27 will run into trying to left shift INT_MIN and report undefined behavior error. 
			while (b != 0) {
				carry = a & b;
				a = a ^ b;
				b = ((carry & 0xffffffff) << 1); // limited to 32 bits to cast back into int
			}
			return a;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
