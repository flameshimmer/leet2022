#include "stdafx.h"

//Given an array nums of n integers, return an array of all the unique
//quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
//0 <= a, b, c, d < n
//a, b, c, and d are distinct.
//nums[a] + nums[b] + nums[c] + nums[d] == target
//You may return the answer in any order.
// 
//
//Example 1:
//Input: nums = [1,0,-1,0,-2,2], target = 0
//Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
//
//Example 2:
//Input: nums = [2,2,2,2,2], target = 8
//Output: [[2,2,2,2]]
// 
//Constraints:
//1 <= nums.length <= 200
//-109 <= nums[i] <= 109
//-109 <= target <= 109

namespace Solution2022
{
	namespace FourSum
	{
	    vector<vector<int>> fourSum(vector<int>& nums, int target) {
			vector<vector<int>> result;
			int len = nums.size();
			if (len < 4) { return result; }

			sort(nums.begin(), nums.end());

			for (int d = len - 1; d >= 3; d--) {
				for (int c = d - 1; c >= 2; c--) {
					int a = 0;
					int b = c - 1;
					while (a < b) {
						long long sum = (long long)nums[a] + (long long)nums[b] + (long long)nums[c] + (long long)nums[d];
						if (sum == target) {
							result.push_back({nums[a], nums[b], nums[c], nums[d] });
							while (a < b && nums[a] == nums[a + 1]) { a++; }
							while (a < b && nums[b] == nums[b - 1]) { b--; }
							a++;
							b--;
						} 
						else if (sum < target) { a++; }
						else { b--; }
					}
					while (c >= 2 && nums[c] == nums[c - 1]) { c--; }				
				}
				while (d >= 3 && nums[d] == nums[d - 1]) { d--; }
			}
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
