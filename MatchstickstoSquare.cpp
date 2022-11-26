#include "stdafx.h"

//You are given an integer array matchsticks where matchsticks[i] is the length
//of the ith matchstick. You want to use all the matchsticks to make one square.
//You should not break any stick, but you can link them up, and each matchstick
//must be used exactly one time.
//Return true if you can make this square and false otherwise.
// 
//
//Example 1:
//Input: matchsticks = [1,1,2,2,2]
//Output: true
//Explanation: You can form a square with length 2, one side of the square came
//two sticks with length 1.
//
//Example 2:
//Input: matchsticks = [3,3,3,3,4]
//Output: false
//Explanation: You cannot find a way to form a square with all the matchsticks.
// 
//Constraints:
//1 <= matchsticks.length <= 15
//1 <= matchsticks[i] <= 108

namespace Solution2022
{
	namespace MatchstickstoSquare
	{
		bool helper(int curSum, int targetSum, int k, int startPos, vector<int>& nums, vector<bool>& visited) {
			if (k == 0) { return true; }
			if (curSum == targetSum) { return helper(0, targetSum, k - 1, 0, nums, visited); }

			int len = nums.size();
			for (int i = startPos; i < len; i++) {
				if (visited[i] || curSum + nums[i] > targetSum) { continue; }
				visited[i] = true;
				if (helper(curSum + nums[i], targetSum, k, startPos + 1, nums, visited)) { return true; }
				visited[i] = false;

				while (i + 1 < len && nums[i] == nums[i + 1]) { i++; }
			}
			return false;
		}

		bool makesquare(vector<int>& nums) {
			int len = nums.size();
			if (len < 4) { return false; }

			int sum = accumulate(nums.begin(), nums.end(), 0);
			if (sum % 4 != 0) { return false; }

			sort(nums.begin(), nums.end());
			vector<bool> visited(len, false);
			return helper(0, sum / 4, 4, 0, nums, visited);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}

	}
}
