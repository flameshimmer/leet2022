#include "stdafx.h"

//You are given an integer n. We reorder the digits in any order (including the
//original order) such that the leading digit is not zero.
//Return true if and only if we can do this so that the resulting number is a
//power of two.
// 
//
//Example 1:
//Input: n = 1
//Output: true
//
//Example 2:
//Input: n = 10
//Output: false
// 
//Constraints:
//1 <= n <= 109

namespace Solution2022
{
	namespace ReorderedPowerofTwo
	{
		vector<int> getDigitCounts(long long N) {
			vector<int> result(10);
			while (N) {
				result[N % 10]++;
				N /= 10;
			}
			return result;
		}

		bool reorderedPowerOf2(int N) {
			vector<int> count = getDigitCounts(N);
			for (int i = 0; i < 31; i++) { // shifting 30 times instead of 31 times since the highest bits is for sign
				if (getDigitCounts(1 << i) == count) { return true; }
			}
			return false;
		}

		namespace Another {
			/*counter will counter the number of digits 9876543210 in the given number.
			Then I just compare counter(N) with all counter(power of 2).
			1 <= N <= 10 ^ 9, so up to 8 same digits.
			If N > 10 ^ 9, we can use a hash map.*/

			long counter(int N) {
				long res = 0;
				for (; N; N /= 10) {
					res += pow(10, N % 10);
				}
				return res;
			}

			bool reorderedPowerOf2(int N) {
				long c = counter(N);
				for (int i = 0; i < 32; i++)
					if (counter(1 << i) == c) return true;
				return false;
			}
		}

		void Main() {
			print(reorderedPowerOf2(10));
		}
	}
}
