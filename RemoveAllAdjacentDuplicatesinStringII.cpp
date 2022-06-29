#include "stdafx.h"

//You are given a string s and an integer k, a k duplicate removal consists of
//choosing k adjacent and equal letters from s and removing them, causing the
//left and the right side of the deleted substring to concatenate together.
//We repeatedly make k duplicate removals on s until we no longer can.
//Return the final string after all such duplicate removals have been made. It is
//guaranteed that the answer is unique.
// 
//
//Example 1:
//Input: s = "abcd", k = 2
//Output: "abcd"
//Explanation: There's nothing to delete.
//
//Example 2:
//Input: s = "deeedbbcccbdaa", k = 3
//Output: "aa"
//Explanation: 
//First delete "eee" and "ccc", get "ddbbbdaa"
//Then delete "bbb", get "dddaa"
//Finally delete "ddd", get "aa"
//
//Example 3:
//Input: s = "pbbcggttciiippooaais", k = 2
//Output: "ps"
// 
//Constraints:
//1 <= s.length <= 105
//2 <= k <= 104
//s only contains lower case English letters.

namespace Solution2022
{
	namespace RemoveAllAdjacentDuplicatesinStringII
	{
		namespace UseStack {
			string removeDuplicates(string str, int k) {
				stack<pair<char, int>> s;
				for (char c : str) {
					if (s.empty() || s.top().first != c) {
						s.push({ c, 1 });
					}
					else {
						s.top().second++;
						if (s.top().second == k) {
							s.pop();
						}
					}
				}

				string result = "";
				while (!s.empty()) {
					result = string(s.top().second, s.top().first) + result;
					s.pop();				
				}
				return result;
			}
		}
		
		string removeDuplicates(string s, int k) {
			vector<int> count(s.size(), 0);

			for (int i = 0; i < s.size(); i++) {
				if (i == 0 || s[i] != s[i - 1]) {
					count[i] = 1;
					continue;
				}
				count[i] = count[i-1] + 1;
				if (count[i] == k) {
					s = s.erase(i - k + 1, k);
					//s = s.substr(0, i + 1 - k) + s.substr(i + 1);
					i -= k;
				}
			}
			return s;
		}

		void Main() {
			string test = "tst test test";
			print(removeDuplicates("deeedbbcccbdaa", 3));
		}
	}
}
