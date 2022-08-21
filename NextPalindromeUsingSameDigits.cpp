#include "stdafx.h"

//You are given a numeric string num, representing a very large palindrome.
//Return the smallest palindrome larger than num that can be created by
//rearranging its digits. If no such palindrome exists, return an empty string "".
//A palindrome is a number that reads the same backward as forward.
// 
//
//Example 1:
//Input: num = "1221"
//Output: "2112"
//Explanation: The next palindrome larger than "1221" is "2112".
//
//Example 2:
//Input: num = "32123"
//Output: ""
//Explanation: No palindromes larger than "32123" can be made by rearranging the
//digits.
//
//Example 3:
//Input: num = "45544554"
//Output: "54455445"
//Explanation: The next palindrome larger than "45544554" is "54455445".
// 
//Constraints:
//1 <= num.length <= 105
//num is a palindrome.

namespace Solution2022
{
	namespace NextPalindromeUsingSameDigits
	{
		string nextPalindrome(string s) {
			int len = s.size();
			string firstHalf = s.substr(0, len / 2);
			string mid = string(len % 2, s[len / 2]);
			if (!next_permutation(firstHalf.begin(), firstHalf.end())) { return ""; }
			return firstHalf + mid + string(firstHalf.rbegin(), firstHalf.rend());
		}

		namespace ManuallyImplementNextPermutation {
			string nextPalindrome(string s) {
				int len = s.size();
				int j = -1;
				int k = -1;
				for (int i = 1; i < len / 2; i++) {
					if (s[i] > s[i - 1]) { j = i - 1; }
					if (j != -1 && s[i] > s[j]) { k = i; }
				}

				if (j == -1) { return ""; }
				swap(s[j], s[k]);
				sort(s.begin() + j + 1, s.begin() + len / 2);
				return s.substr(0, (len + 1) / 2) + string(s.rbegin() + (len + 1) / 2, s.rend());
			}

		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
