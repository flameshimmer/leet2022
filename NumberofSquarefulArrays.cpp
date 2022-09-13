#include "stdafx.h"

//An array is squareful if the sum of every pair of adjacent elements is a
//perfect square.
//Given an integer array nums, return the number of permutations of nums that are
//squareful.
//Two permutations perm1 and perm2 are different if there is some index i such
//that perm1[i] != perm2[i].
// 
//
//Example 1:
//Input: nums = [1,17,8]
//Output: 2
//Explanation: [1,8,17] and [17,8,1] are the valid permutations.
//
//Example 2:
//Input: nums = [2,2,2]
//Output: 1
// 
//Constraints:
//1 <= nums.length <= 12
//0 <= nums[i] <= 109

namespace Solution2022
{
	namespace NumberofSquarefulArrays
	{
		void helper(int v, int level, int len, unordered_map<int, int>& count, unordered_map<int, unordered_set<int>>& candidates, int& result) {
			if (level == len) { result++; return; }
			count[v]--;
			for (int c : candidates[v]) {
				if (count[c] > 0) {
					helper(c, level + 1, len, count, candidates, result);
				}
			}
			count[v]++;
		}

		int numSquarefulPerms(vector<int>& nums) {
			int len = nums.size();
			unordered_map<int, int> count;
			for (int v : nums) { count[v]++; }

			unordered_map<int, unordered_set<int>> candidates;
			for (auto& p1 : count) {
				for (auto& p2 : count) { // the count[c] > 0 check will ensure the usage will fit into the resource. So don't worry about p1 == p2 case here. 
					int x = p1.first;
					int y = p2.first;
					int s = sqrt(x + y);
					if (s * s == x + y) { candidates[x].insert(y); }
				}
			}

			int result = 0;
			for (auto& p : count) {
				helper(p.first, 1, len, count, candidates, result); // Note: the start level is 1 instead of 0!!!!
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
