#include "stdafx.h"

//A message containing letters from A-Z can be encoded into numbers using the
//following mapping:
//'A' -> "1"
//'B' -> "2"
//...
//'Z' -> "26"
//To decode an encoded message, all the digits must be grouped then mapped back
//into letters using the reverse of the mapping above (there may be multiple
//ways). For example, "11106" can be mapped into:
//"AAJF" with the grouping (1 1 10 6)
//"KJF" with the grouping (11 10 6)
//
//Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into
//'F' since "6" is different from "06".
//Given a string s containing only digits, return the number of ways to decode it.
//The test cases are generated so that the answer fits in a 32-bit integer.
// 
//
//Example 1:
//Input: s = "12"
//Output: 2
//Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
//
//Example 2:
//Input: s = "226"
//Output: 3
//Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
//6).
//
//Example 3:
//Input: s = "06"
//Output: 0
//Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is
//different from "06").
// 
//Constraints:
//1 <= s.length <= 100
//s contains only digits and may contain leading zero(s).

namespace Solution2022
{
	namespace DecodeWays
	{
		namespace DP {

			//dp[-1] = 1;
			//dp[i] = 
			//	1. 0, if s[i] and s[i-1][i] are invalid
			//	2. dp[i-1] + dp[i-2], if s[i] and s[i - 1][i] are valid
			//	3. dp[i-1], if s[i] is valid
			//	4. dp[i-2], if s[i-1]s[i] is valid

			//s[i] is valid: if s[i] != '0'
			//s[i-1]s[i] is valid: if 10 <= s[i-1][i] <= 26

			int numDecodings(string s) {
				int len = s.size();
				if (len == 0 || s[0] == '0') { return 0; }
				
				int r1 = 1;
				int r2 = 1;

				for (int i = 1; i < len; i++) {
					int r = 0;
					if (s[i] != '0') { r += r1; }
					if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) { r += r2; }
					r2 = r1;
					r1 = r;
				}
				return r1;
			}
		}
		
		
		namespace RecursionWithMemorization {
			// Without memorization the problem will TLE
			void helper(string& s, int start, int len, int& result, vector<int>& M) {
				if (start == len) { result++; }
				if (start >= len) { return; }

				if (M[start] != -1) { 
					result += M[start];  
					return; 
				}

				if (s[start] == '0') { return; }

				int oldResult = result;
				helper(s, start + 1, len, result, M);

				if (s[start] == '1' || s[start] == '2' && start + 1 < len && s[start + 1] <= '6') {
					helper(s, start + 2, len, result, M);
				}
				M[start] = result - oldResult;
			}

			int numDecodings(string s) {
				int len = s.size();
				int result = 0;
				vector<int> M(len, -1);
				helper(s, 0, len, result, M);
				return result;
			}
		}
	    
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
