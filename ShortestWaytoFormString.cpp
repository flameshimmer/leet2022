#include "stdafx.h"

//A subsequence of a string is a new string that is formed from the original
//string by deleting some (can be none) of the characters without disturbing the
//relative positions of the remaining characters. (i.e., "ace" is a subsequence
//of "abcde" while "aec" is not).
//Given two strings source and target, return the minimum number of subsequences
//of source such that their concatenation equals target. If the task is
//impossible, return -1.
// 
//
//Example 1:
//Input: source = "abc", target = "abcbc"
//Output: 2
//Explanation: The target "abcbc" can be formed by "abc" and "bc", which are
//subsequences of source "abc".
//
//Example 2:
//Input: source = "abc", target = "acdbc"
//Output: -1
//Explanation: The target string cannot be constructed from the subsequences of
//source string due to the character "d" in target string.
//
//Example 3:
//Input: source = "xyz", target = "xzyxz"
//Output: 3
//Explanation: The target string can be constructed as follows "xz" + "y" + "xz".
// 
//Constraints:
//1 <= source.length, target.length <= 1000
//source and target consist of lowercase English letters.

namespace Solution2022
{
	namespace ShortestWaytoFormString
	{
	    int shortestWay(string source, string target) {
			int len = source.size();
			vector<vector<int>> map(len, vector<int>(26, -1));

			map[len - 1][source[len - 1] - 'a'] = len - 1;
			for (int i = len - 2; i >= 0; i--) {
				map[i] = map[i + 1];
				map[i][source[i] - 'a'] = i;
			}

			int result = 1;
			int i = 0;
			for (char c : target) {
				int t = c - 'a';
				if (map[0][t] == -1) { return -1; }

				if (i == len || map[i][t] == -1) {
					result++;
					i = map[0][t] + 1;
				}
				else {
					i = map[i][t] + 1;
				}			
			}
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
