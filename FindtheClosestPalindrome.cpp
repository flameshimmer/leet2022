#include "stdafx.h"

//Given a string n representing an integer, return the closest integer (not
//including itself), which is a palindrome. If there is a tie, return the smaller
//one.
//The closest is defined as the absolute difference minimized between two
//integers.
// 
//
//Example 1:
//Input: n = "123"
//Output: "121"
//
//Example 2:
//Input: n = "1"
//Output: "0"
//Explanation: 0 and 2 are the closest palindromes but we return the smallest
//which is 0.
// 
//Constraints:
//1 <= n.length <= 18
//n consists of only digits.
//n does not have leading zeros.
//n is representing an integer in the range [1, 1018 - 1].

namespace Solution2022
{
	namespace FindtheClosestPalindrome
	{
		//For any possible number, there is 5 cases:
		//Say the number is 4723

		//	Case 1. The next closest palidrome has one digit extra : So here it will be 10001
		//	Case 2. The next closest palindrome has one digit less : So here it will be 999
		//	Case 3. The next closest palidrome has the same number of digits
		//	For case 3 there are 3 subcases:
		//		-The middle digit remains same.Postfix is the mirror image of prefix.So here 47(prefix)74(postfix)-- > 4774
		//		- The middle digit increases by 1.Postfix is the mirror image of prefix.So here 4884
		//		- The middle digit decreases by 1.Postfix is the mirror image of prefix.So here 4664
		//Among these 5 candidates:
		//The candidate having the least absolute difference from the original number is the answer.In this case it is 4774.

	    string nearestPalindromic(string n) {
			int len = n.size();
			if (len == 1) { return to_string(stoi(n) - 1); }

			vector<long long> candidates;			
			candidates.push_back(pow(10, len) + 1); // case 1
			candidates.push_back(pow(10, len - 1) - 1); // case 2

			int mid = (len + 1) / 2;
			long long prefix = stol(n.substr(0, mid));
			vector<long long> v = { prefix, prefix + 1, prefix - 1 }; // case 3
			for (long long i : v) {
				string postfix = to_string(i);
				if (len % 2 == 1) { postfix.pop_back(); }
				reverse(postfix.begin(), postfix.end());
				string c = to_string(i) + postfix;
				candidates.push_back(stol(c));
			}

			long long minDiff = LONG_MAX;
			long long result;
			long num = stol(n);

			for (long long c : candidates) {
				long long diff = abs(c - num);
				if (c != num && diff < minDiff) {
					minDiff = diff;
					result = c;
				}
				else if (diff == minDiff) {
					result = min(result, c);
				}
			}
			return to_string(result);
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
