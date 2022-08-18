#include "stdafx.h"

//A confusing number is a number that when rotated 180 degrees becomes a
//different number with each digit valid.
//We can rotate digits of a number by 180 degrees to form new digits.
//When 0, 1, 6, 8, and 9 are rotated 180 degrees, they become 0, 1, 9, 8, and 6
//respectively.
//When 2, 3, 4, 5, and 7 are rotated 180 degrees, they become invalid.
//
//Note that after rotating a number, we can ignore leading zeros.
//For example, after rotating 8000, we have 0008 which is considered as just 8.
//Given an integer n, return true if it is a confusing number, or false otherwise.
// 
//
//Example 1:
//Input: n = 6
//Output: true
//Explanation: We get 9 after rotating 6, 9 is a valid number, and 9 != 6.
//
//Example 2:
//Input: n = 89
//Output: true
//Explanation: We get 68 after rotating 89, 68 is a valid number and 68 != 89.
//
//Example 3:
//Input: n = 11
//Output: false
//Explanation: We get 11 after rotating 11, 11 is a valid number but the value
//remains the same, thus 11 is not a confusing number
// 
//Constraints:
//0 <= n <= 109

namespace Solution2022
{
	namespace ConfusingNumber
	{
		bool confusingNumber(int n) {
			int N = n;
			int reversed = 0;

			while (n) {
				int remain = n % 10;
				if (remain == 2 || remain == 3 || remain == 4 || remain == 5 || remain == 7) { return false; }
				else if (remain == 6) { remain = 9; }
				else if (remain == 9) { remain = 6; }
				reversed = reversed * 10 + remain;
				n /= 10;
			}
			return reversed != N;
		}


		namespace UseString {
			bool confusingNumber(int n) {
				if (n == 0) { return false; } // Need to take care of 0 as a special case!!!
				string s = to_string(n);
				reverse(s.begin(), s.end());
				s = s.substr(s.find_first_not_of('0'));

				string s2 = "";
				for (char c : s) {
					if (c == '2' || c == '3' || c == '4' || c == '5' || c == '7') { return false; }
					else if (c == '6') { c = '9'; }
					else if (c == '9') { c = '6'; }
					s2.push_back(c);
				}
				return s2 != to_string(n);
			}
		}

		void Main() {
			print(confusingNumber(9));
		}
	}
}
