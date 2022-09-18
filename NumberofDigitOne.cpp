#include "stdafx.h"

//Given an integer n, count the total number of digit 1 appearing in all
//non-negative integers less than or equal to n.
// 
//
//Example 1:
//Input: n = 13
//Output: 6
//
//Example 2:
//Input: n = 0
//Output: 0
// 
//Constraints:
//0 <= n <= 109

namespace Solution2022
{
	namespace NumberofDigitOne
	{
		// https://www.youtube.com/watch?v=QlMyXlhI3Ic
		int countDigitOne(int n) {
			string s = to_string(n);
			int len = s.size();
			int count = 0;

			for (int i = 1; i <= len; i++) {
				long a = n / pow(10, i);
				count += a * pow(10, i - 1);

				int digit = s[len - i] - '0';
				if (digit > 1) {
					count += pow(10, i - 1);
				}
				else if (digit == 1) {
					count += n % (int)pow(10, i - 1) + 1;
				}
			}
			return count;
		}

		void Main() {
			string test = "tst test test";
			print(countDigitOne(0));
		}
	}
}
