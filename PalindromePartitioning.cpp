#include "stdafx.h"

//Given a string s, partition s such that every substring of the partition is a
//palindrome. Return all possible palindrome partitioning of s.
//A palindrome string is a string that reads the same backward as forward.
// 
//
//Example 1:
//Input: s = "aab"
//Output: [["a","a","b"],["aa","b"]]
//
//Example 2:
//Input: s = "a"
//Output: [["a"]]
// 
//Constraints:
//1 <= s.length <= 16
//s contains only lowercase English letters.

namespace Solution2022
{
	namespace PalindromePartitioning
	{
		bool isValidPalindrome(string& s, int start, int end) {
			while (start < end) {
				if (s[start] != s[end]) { return false; }
				start++;
				end--;
			}
			return true;
		}

		void helper(int start, int len, string& s, vector<string>& result, vector<vector<string>>& results) {
			if (start == len) { results.push_back(result); }

			for (int i = start; i < len; i++) {
				if (isValidPalindrome(s, start, i)) {
					string cur = s.substr(start, i - start + 1);
					result.push_back(cur);
					helper(i + 1, len, s, result, results);
					result.pop_back();
				}
			}
		}

		vector<vector<string>> partition(string s) {
			vector<vector<string>> results;
			int len = s.size();
			if (len == 0) { return results; }

			vector<string> result;
			helper(0, len, s, result, results);
			return results;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
