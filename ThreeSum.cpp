#include "stdafx.h"

//Given an integer array nums, return all the triplets [nums[i], nums[j],
//nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k]
//== 0.
//Notice that the solution set must not contain duplicate triplets.
// 
//
//Example 1:
//Input: nums = [-1,0,1,2,-1,-4]
//Output: [[-1,-1,2],[-1,0,1]]
//
//Example 2:
//Input: nums = []
//Output: []
//
//Example 3:
//Input: nums = [0]
//Output: []
// 
//Constraints:
//0 <= nums.length <= 3000
//-105 <= nums[i] <= 105

namespace Solution2022
{
	namespace ThreeSum
	{
	    vector<vector<int>> threeSum(vector<int>& nums) {
			vector<vector<int>> result;
			int len = nums.size();
			if (len == 0) { return result; }
			sort(nums.begin(), nums.end());

			for (int k = len - 1; k >= 2; k--) {
				int i = 0;
				int j = k - 1;
				while (i < j) {
					int sum = nums[i] + nums[j] + nums[k];
					if (sum == 0) {
						while (i < j && nums[i] == nums[i + 1]) { i++; }
						while (i < j && nums[j] == nums[j - 1]) { j--; }
						result.push_back({nums[i], nums[j], nums[k]});
						i++;
						j--;
					}
					else if (sum < 0) { i++; }
					else { j--; }
				}
				while (k >= 2 && nums[k] == nums[k - 1]) {
					k--;
				}
			}
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
