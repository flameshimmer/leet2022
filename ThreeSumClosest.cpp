#include "stdafx.h"

//Given an integer array nums of length n and an integer target, find three
//integers in nums such that the sum is closest to target.
//Return the sum of the three integers.
//You may assume that each input would have exactly one solution.
// 
//
//Example 1:
//Input: nums = [-1,2,1,-4], target = 1
//Output: 2
//Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//Example 2:
//Input: nums = [0,0,0], target = 1
//Output: 0
// 
//Constraints:
//3 <= nums.length <= 1000
//-1000 <= nums[i] <= 1000
//-104 <= target <= 104

namespace Solution2022
{
	namespace ThreeSumClosest
	{
	    int threeSumClosest(vector<int>& nums, int target) {
			int len = nums.size();
			if (len < 3) { return 0; }

			sort(nums.begin(), nums.end());

			int result = nums[0] + nums[1] + nums[2];
			int minDiff = abs(target - result);
			for (int k = len - 1; k >= 2; k--) {
				int i = 0;
				int j = k - 1;
				while (i < j) {
					int sum = nums[i] + nums[j] + nums[k];
					int curDiff = abs(target - sum);
					if (curDiff == 0) { return target; }

					if (curDiff < minDiff) {
						minDiff = curDiff;
						result = sum;
					}

					if (sum < target) { i++; }
					else { j--; }
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
