#include "stdafx.h"

//Given a binary string s, return the number of non-empty substrings that have
//the same number of 0's and 1's, and all the 0's and all the 1's in these
//substrings are grouped consecutively.
//Substrings that occur multiple times are counted the number of times they occur.
// 
//
//Example 1:
//Input: s = "00110011"
//Output: 6
//Explanation: There are 6 substrings that have equal number of consecutive 1's
//and 0's: "0011", "01", "1100", "10", "0011", and "01".
//Notice that some of these substrings repeat and are counted the number of times
//they occur.
//Also, "00110011" is not a valid substring because all the 0's (and 1's) are not
//grouped together.
//
//Example 2:
//Input: s = "10101"
//Output: 4
//Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal
//number of consecutive 1's and 0's.
// 
//Constraints:
//1 <= s.length <= 105
//s[i] is either '0' or '1'.

namespace Solution2022
{
	namespace CountBinarySubstrings
	{
		int countBinarySubstrings(string s) {
			int len = s.size();
			if (len == 0) { return 0; }

			int front = 0;
			int back = 0;
			int curCount = 1; // Note the curCount should always start with 1
			int prevCount = 0; // Note prevCount is 0, since the first iteration of for loopi s not expected to add any thing

			int result = 0;
			for (int i = 1; i < len; i++) {
				if (s[i] == s[i - 1]) { curCount++; }
				else {
					result += min(prevCount, curCount);
					prevCount = curCount;
					curCount = 1;
				}
			}
			result += min(prevCount, curCount);
			return result;
		}

		namespace SumLater {
			int countBinarySubstrings(string s) {
				int len = s.size();
				if (len == 0) { return 0; }

				int back = 0;
				int front = 0;
				vector<pair<char, int>> group;
				while (front < len) {
					while (front < len && s[front] == s[back]) { front++; } // Note: let front only be increased here!
					group.push_back({ s[back], front - back });
					back = front;
				}


				int result = 0;
				for (int i = 0; i < group.size() - 1; i++) {
					result += min(group[i].second, group[i + 1].second);
				}
				return result;
			}
		}


		void Main() {
			print(countBinarySubstrings("00110011"));
			print(countBinarySubstrings("10101"));
		}
	}
}
