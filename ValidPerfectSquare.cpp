#include "stdafx.h"

//Given a positive integer num, write a function which returns True if num is a
//perfect square else False.
//Follow up: Do not use any built-in library function such as sqrt.
// 
//
//Example 1:
//Input: num = 16
//Output: true
//
//Example 2:
//Input: num = 14
//Output: false
// 
//Constraints:
//1 <= num <= 2^31 - 1

namespace Solution2022
{
	namespace ValidPerfectSquare
	{
		/*1 = 1
		1 + 3 = 4
		1 + 3 + 5 = 9
		1 + 3 + 5 + 7 = 16
		and so on ..............*/
		bool isPerfectSquare(int num) {
			int a = 1;
			while (num > 0) {
				num -= a;
				a += 2;
			}
			return num == 0;
		}

		namespace BinarySearch {
			bool isPerfectSquare(int num) {
				long long l = 1;
				long long r = (num / 2) + 1;

				while (l <= r) {
					long long mid = l + (r - l) / 2; // NOTE: use long long since two int multiplication might be outside of int boundary
					long long v = mid * mid;
					if (v == num) { return true; }
					else if (v < num) { l = mid + 1; }
					else { r = mid - 1; }
				}
				return false;
			}

		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
