#include "stdafx.h"

//You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with
//a number on it represented by an array nums. You are asked to burst all the
//balloons.
//If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1]
//coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if
//there is a balloon with a 1 painted on it.
//Return the maximum coins you can collect by bursting the balloons wisely.
// 
//
//Example 1:
//Input: nums = [3,1,5,8]
//Output: 167
//Explanation:
//nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
//coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
//
//Example 2:
//Input: nums = [1,5]
//Output: 10
// 
//Constraints:
//n == nums.length
//1 <= n <= 300
//0 <= nums[i] <= 100

namespace Solution2022
{
	namespace BurstBalloons
	{
		int helper(vector<int>& nums, int i, int j, vector<vector<int>>& m) {
			if (i > j) { return 0; }
			if (m[i][j] != -1) { return m[i][j]; }

			int result = 0;
			for (int k = i; k <= j; k++) {
				int prev = i - 1 >= 0 ? nums[i - 1] : 1;
				int next = j + 1 < nums.size() ? nums[j + 1] : 1;
				result = max(result, prev * nums[k] * next + helper(nums, i, k - 1, m) + helper(nums, k + 1, j, m));
			}
			m[i][j] = result;
			return result;
		}

		int maxCoins(vector<int>& nums) {
			int len = nums.size();
			vector<vector<int>> m(len, vector<int>(len, -1));
			return helper(nums, 0, len - 1, m);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
