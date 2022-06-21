  #include "stdafx.h"

//Write a function to find the longest common prefix string amongst an array of
//strings.
//If there is no common prefix, return an empty string "".
// 
//
//Example 1:
//Input: strs = ["flower","flow","flight"]
//Output: "fl"
//
//Example 2:
//Input: strs = ["dog","racecar","car"]
//Output: ""
//Explanation: There is no common prefix among the input strings.
// 
//Constraints:
//1 <= strs.length <= 200
//0 <= strs[i].length <= 200
//strs[i] consists of only lower-case English letters.

namespace Solution2022
{
	namespace LongestCommonPrefix
	{
	    string longestCommonPrefix(vector<string>& strs) {
			int len = strs.size();
			if (len == 0) { return ""; }
			if (len == 1) { return strs[0]; }

			int minLen = INT_MAX;
			for (string& s : strs) { minLen = min(minLen, (int)s.size()); }


			string result = "";
			for (int i = 0; i<minLen; i++){
				for (int j = 0; j < len-1; j++) {
					if (strs[j][i] != strs[j+1][i]) { return result; }
				}
				result.push_back(strs[0][i]);
			}
			return result;
		}

		void Main() {
			vector<string> test = { "flower","flow","flight" };
			print(longestCommonPrefix(test));
		}
	}
}
