#include "stdafx.h"

//A valid IP address consists of exactly four integers separated by single dots.
//Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
//For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but
//"0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
//Given a string s containing only digits, return all possible valid IP addresses
//that can be formed by inserting dots into s. You are not allowed to reorder or
//remove any digits in s. You may return the valid IP addresses in any order.
// 
//
//Example 1:
//Input: s = "25525511135"
//Output: ["255.255.11.135","255.255.111.35"]
//
//Example 2:
//Input: s = "0000"
//Output: ["0.0.0.0"]
//
//Example 3:
//Input: s = "101023"
//Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
// 
//Constraints:
//1 <= s.length <= 20
//s consists of digits only.

namespace Solution2022
{
	namespace RestoreIPAddresses
	{

		void helper(string& s, int start, int len, int level, string result, vector<string>& results) {
			if (start == len) {
				if (level == 0) {
					result.pop_back();
					results.push_back(result);
				}
				return; // Note: don't forget to return from here!!!
			}
			if (len - start < level || len - start > 3 * level) { return; }

			int possibleLen = s[start] == '0' ? 1 : 3;
			for (int i = 1; i <= possibleLen; i++) {
				string tmp = s.substr(start, i);
				if (stoi(tmp) > 255) { break; }
				helper(s, start + i, len, level - 1, result + tmp + '.', results);
			}
		}

		vector<string> restoreIpAddresses(string s) {
			int len = s.size();
			vector<string> results;
			string result;
			helper(s, 0, len, 4, result, results);
			return results;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
