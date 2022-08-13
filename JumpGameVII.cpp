#include "stdafx.h"

//You are given a 0-indexed binary string s and two integers minJump and maxJump.
//In the beginning, you are standing at index 0, which is equal to '0'. You can
//move from index i to index j if the following conditions are fulfilled:
//i + minJump <= j <= min(i + maxJump, s.length - 1), and
//s[j] == '0'.
//Return true if you can reach index s.length - 1 in s, or false otherwise.
// 
//
//Example 1:
//Input: s = "011010", minJump = 2, maxJump = 3
//Output: true
//Explanation:
//In the first step, move from index 0 to index 3. 
//In the second step, move from index 3 to index 5.
//
//Example 2:
//Input: s = "01101110", minJump = 2, maxJump = 3
//Output: false
// 
//Constraints:
//2 <= s.length <= 105
//s[i] is either '0' or '1'.
//s[0] == '0'
//1 <= minJump <= maxJump < s.length

namespace Solution2022
{
	namespace JumpGameVII
	{
	    bool canReach(string s, int minJump, int maxJump) {
			int len = s.size();
			if (s[0] != '0' || s[len - 1] != '0') { return false; }

			queue<int> q;
			q.push(0);
			int curMax = 0;

			while (!q.empty()) {
				int top = q.front();
				q.pop();
				
				if (top == len - 1) { return true; }

				for (int i = max(top + minJump, curMax); i <= min(top + maxJump, len - 1); i++) {
					if (s[i] == '0') {
						q.push(i);
					}
				}
				curMax = min(top + maxJump + 1, len); // will TLE if not use this optimization and use visited map to do BFS
			}
			return false;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
