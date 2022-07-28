#include "stdafx.h"

//You are given a 0-indexed string s that you must perform k replacement
//operations on. The replacement operations are given as three 0-indexed parallel
//arrays, indices, sources, and targets, all of length k.
//To complete the ith replacement operation:
//Check if the substring sources[i] occurs at index indices[i] in the original
//string s.
//If it does not occur, do nothing.
//Otherwise if it does occur, replace that substring with targets[i].
//For example, if s = "abcd", indices[i] = 0, sources[i] = "ab", and targets[i] =
//"eee", then the result of this replacement will be "eeecd".
//All replacement operations must occur simultaneously, meaning the replacement
//operations should not affect the indexing of each other. The testcases will be
//generated such that the replacements will not overlap.
//For example, a testcase with s = "abc", indices = [0, 1], and sources =
//["ab","bc"] will not be generated because the "ab" and "bc" replacements
//overlap.
//Return the resulting string after performing all replacement operations on s.
//A substring is a contiguous sequence of characters in a string.
// 
//
//Example 1:
//Input: s = "abcd", indices = [0, 2], sources = ["a", "cd"], targets = ["eee",
//"ffff"]
//Output: "eeebffff"
//Explanation:
//"a" occurs at index 0 in s, so we replace it with "eee".
//"cd" occurs at index 2 in s, so we replace it with "ffff".
//
//Example 2:
//Input: s = "abcd", indices = [0, 2], sources = ["ab","ec"], targets =
//["eee","ffff"]
//Output: "eeecd"
//Explanation:
//"ab" occurs at index 0 in s, so we replace it with "eee".
//"ec" does not occur at index 2 in s, so we do nothing.
// 
//Constraints:
//1 <= s.length <= 1000
//k == indices.length == sources.length == targets.length
//1 <= k <= 100
//0 <= indexes[i] < s.length
//1 <= sources[i].length, targets[i].length <= 50
//s consists of only lowercase English letters.
//sources[i] and targets[i] consist of only lowercase English letters.

namespace Solution2022
{
	namespace FindAndReplaceinString
	{
	    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
			vector<pair<int, int>> sorted;
			for (int i = 0; i < indices.size(); i++) {
				sorted.push_back({ indices[i], i }); // Note: need to replace from the back to the front to avoid index
			}

			// same as sort(sorted.begin(), sorted.end(), greater<pair<int, int>>());
			sort(sorted.rbegin(), sorted.rend());

			string result = s;
			for (auto& [i1, i2] : sorted) {
				string& s1 = sources[i2];
				string& s2 = targets[i2];
				int len1 = s1.size();
				
				if (s.substr(i1, len1) != s1) { continue; }
				result = result.substr(0, i1) + s2 + result.substr(i1 + len1);			
			}
			return result;
	    }

		void Main() {
			vector<int> v1 = { 0, 2 };
			vector<string> v2 = { "a", "cd" };
			vector<string> v3 = { "eee", "ffff" };

			print(findReplaceString("abcd", v1, v2, v3));
		}
	}
}
