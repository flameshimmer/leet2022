#include "stdafx.h"

//Given a string s, return the number of different non-empty palindromic
//subsequences in s. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence of a string is obtained by deleting zero or more characters from
//the string.
//A sequence is palindromic if it is equal to the sequence reversed.
//Two sequences a1, a2, ... and b1, b2, ... are different if there is some i for
//which ai != bi.
// 
//
//Example 1:
//Input: s = "bccb"
//Output: 6
//Explanation: The 6 different non-empty palindromic subsequences are 'b', 'c',
//'bb', 'cc', 'bcb', 'bccb'.
//
//Note that 'bcb' is counted only once, even though it occurs twice.
//
//Example 2:
//Input: s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"
//Output: 104860361
//Explanation: There are 3104860382 different non-empty palindromic subsequences,
//which is 104860361 modulo 109 + 7.
// 
//Constraints:
//1 <= s.length <= 1000
//s[i] is either 'a', 'b', 'c', or 'd'.

namespace Solution2022
{
	namespace CountDifferentPalindromicSubsequences
	{
		//https://www.youtube.com/watch?v=UjiFFYU3EKM

		namespace Recursion {
			vector<int> m;
			long long kMod = 1e9 + 7;

			long long count(string& S, int s, int e) {
				if (s > e) { return 0; }
				if (s == e) { return 1; }
				int key = s * S.size() + e;
				if (m[key] > 0) { return m[key]; }

				long long result = 0;
				if (S[s] == S[e]) {
					int l = s + 1;
					int r = e - 1;
					while (l <= r && S[l] != S[s]) { l++; }
					while (l <= r && S[r] != S[e]) { r--; }
					if (l > r) { result = count(S, s + 1, e - 1) * 2 + 2; }
					else if (l == r) { result = count(S, s + 1, e - 1) * 2 + 1; }
					else { result = count(S, s + 1, e - 1) * 2 - count(S, l + 1, r - 1); }
				}
				else {
					result = count(S, s, e - 1) + count(S, s + 1, e) - count(S, s + 1, e - 1);
				}
				m[key] = (result + kMod) % kMod;
				return m[key];
			}

			int countPalindromicSubsequences(string s) {
				int len = s.size();
				m = vector<int>(len * (len + 1) + 1, 0);
				return count(s, 0, len - 1);
			}
		}


		namespace DP {
			int countPalindromicSubsequences(string s) {
				int len = s.size();
				vector<vector<int>> dp(len, vector<int>(len, 0));
				for (int i = 0; i < len; i++) { dp[i][i] = 1; }

				long long kMod = 1e9 + 7;
				for (int curLen = 1; curLen <= len; curLen++) {
					for (int i = 0; i < len - curLen; i++) {
						int j = i + curLen;
						if (s[i] == s[j]) {
							dp[i][j] = dp[i + 1][j - 1] * 2;
							int l = i + 1;
							int r = j - 1;
							while (l <= r && s[l] != s[i]) { l++; }
							while (l <= r && s[r] != s[j]) { r--; }
							if (l > r) { dp[i][j] += 2; }
							else if (l == r) { dp[i][j] += 1; }
							else { dp[i][j] -= dp[l + 1][r - 1]; }
						}
						else {
							dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
						}
						dp[i][j] = (dp[i][j] + kMod) % kMod;
					}
				}
				return dp[0][len - 1];
			}
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
