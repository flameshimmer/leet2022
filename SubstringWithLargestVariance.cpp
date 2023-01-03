#include "stdafx.h"

//The variance of a string is defined as the largest difference between the
//number of occurrences of any 2 characters present in the string. 
//Note the two
//characters may or may not be the same.
//Given a string s consisting of lowercase English letters only, return the
//largest variance possible among all substrings of s.
//A substring is a contiguous sequence of characters within a string.
// 
//
//Example 1:
//Input: s = "aababbb"
//Output: 3
//Explanation:
//All possible variances along with their respective substrings are listed below:
//- Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb",
//and "bbb".
//- Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb",
//and "bab".
//- Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
//- Variance 3 for substring "babbb".
//Since the largest possible variance is 3, we return it.
//
//Example 2:
//Input: s = "abcde"
//Output: 0
//Explanation:
//No letter occurs more than once in s, so the variance of every substring is 0.
// 
//Constraints:
//1 <= s.length <= 104
//s consists of lowercase English letters.

namespace Solution2022
{
	namespace SubstringWithLargestVariance
	{
		int largestVariance(string s) {
			int result = 0;
			for (char c1 = 'a'; c1 <= 'z'; c1++) {
				for (char c2 = 'a'; c2 <= 'z'; c2++) {
					if (c1 == c2) { continue; }
					int n1 = 0;
					int n2 = 0;
					bool canExtend = false;

					for (char c : s) {
						n1 += c == c1;
						n2 += c == c2;

						if (n2 > 0) { result = max(result, n1 - n2); }
						else if (canExtend) { result = max(result, n1 - 1); }

						if (n1 < n2) {
							n1 = 0;
							n2 = 0;
							canExtend = true;
						}
					}
				}
			}
			return result;
		}

		namespace Another {
			int largestVariance(string s) {
				int result = 0;
				vector<int> freq(26, 0);
				for (char c : s) { freq[c - 'a']++; }

				for (char c1 = 'a'; c1 <= 'z'; c1++) {
					for (char c2 = 'a'; c2 <= 'z'; c2++) {
						if (c1 == c2 || freq[c1 - 'a'] == 0 || freq[c2 - 'a'] == 0) { continue; }
						for (int i = 0; i < 2; i++) {
							int n1 = 0;
							int n2 = 0;
							for (char c : s) {
								n1 += c == c1;
								n2 += c == c2;
								if (n1 < n2) {
									n1 = 0;
									n2 = 0;
								}
								if (n1 > 0 && n2 > 0) {
									result = max(result, n1 - n2);
								}
							}
							reverse(s.begin(), s.end());
						}
					}
				}
				return result;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
