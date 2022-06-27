#include "stdafx.h"

//Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
// 
//
//Example 1:
//Input: x = 2.00000, n = 10
//Output: 1024.00000
//
//Example 2:
//Input: x = 2.10000, n = 3
//Output: 9.26100
//
//Example 3:
//Input: x = 2.00000, n = -2
//Output: 0.25000
//Explanation: 2-2 = 1/22 = 1/4 = 0.25
// 
//Constraints:
//-100.0 < x < 100.0
//-231 <= n <= 231-1
//-104 <= xn <= 104

namespace Solution2022
{
	namespace Pow
	{
		double myPowIterative(double x, int n) {
			double result = 1;
			long long n2 = n;
			if (n2 < 0) {
				n2 = -n2;
				x = 1 / x;
			}
			while (n2) {
				if (n2 % 2 == 1) { result *= x; }
				x *= x;
				n2 /= 2;
			}
			return result;
		}
		
		double myPow(double x, int n) {
			if (n == 0) { return 1; }
			long long n2 = n;
			if (n2 < 0) {
				x = 1 / x;
				n2 = -n2;
			}
			return (n2 % 2 == 0) ? myPow(x * x, n2 / 2) : x * myPow(x * x, n2 / 2);
	    }

		void Main() {
			print(myPow(2, 10));
		}
	}
}
