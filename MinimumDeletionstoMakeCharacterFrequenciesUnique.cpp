#include "stdafx.h"

//A string s is called good if there are no two different characters in s that
//have the same frequency.
//Given a string s, return the minimum number of characters you need to delete to
//make s good.
//The frequency of a character in a string is the number of times it appears in
//the string. For example, in the string "aab", the frequency of 'a' is 2, while
//the frequency of 'b' is 1.
// 
//
//Example 1:
//Input: s = "aab"
//Output: 0
//Explanation: s is already good.
//
//Example 2:
//Input: s = "aaabbbcc"
//Output: 2
//Explanation: You can delete two 'b's resulting in the good string "aaabcc".
//Another way it to delete one 'b' and one 'c' resulting in the good string
//"aaabbc".
//
//Example 3:
//Input: s = "ceabaacb"
//Output: 2
//Explanation: You can delete both 'c's resulting in the good string "eabaab".
//
//Note that we only care about characters that are still in the string at the end
//(i.e. frequency of 0 is ignored).
// 
//Constraints:
//1 <= s.length <= 105
//s contains only lowercase English letters.

namespace Solution2022
{
	namespace MinimumDeletionstoMakeCharacterFrequenciesUnique
	{
		int minDeletions(string s) {
			vector<int> freq(26, 0);
			for (char c : s) { freq[c - 'a']++; }

			sort(freq.begin(), freq.end());
			int result = 0;
			for (int i = 24; i >= 0; i--) {
				if (freq[i] == 0) { break; }
				if (freq[i] >= freq[i + 1]) {
					int oldF = freq[i];
					freq[i] = max(0, freq[i + 1] - 1);
					result += oldF - freq[i];
				}
			}
			return result;
		}

		namespace MyMethod {
			int minDeletions(string s) {
				unordered_map<char, int> map;
				for (char c : s) { map[c] ++; }

				unordered_map<int, vector<char>> freq;
				for (auto [c, f] : map) { freq[f].push_back(c); }

				int result = 0;
				for (auto& [f, vc] : freq) {
					if (vc.size() == 1) { continue; }
					for (int i = 1; i < vc.size(); i++) {
						int t = f;
						while (t > 0 && freq.find(t) != freq.end()) { t--; result++; }
						if (t > 0) { freq[t] = { vc[i] }; }
					}
				}
				return result;

			}
		}

		void Main() {

			vector<int> test1 = { 1, 2 };
			for (int v : test1) {
				print(v);
				test1.push_back(v + 3);
			}
			print(test1);
		}
	}
}
