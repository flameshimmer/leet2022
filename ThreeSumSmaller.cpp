#include "stdafx.h"

//Given an array of n integers nums and an integer target, find the number of
//index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition
//nums[i] + nums[j] + nums[k] < target.
// 
//
//Example 1:
//Input: nums = [-2,0,1,3], target = 2
//Output: 2
//Explanation: Because there are two triplets which sums are less than 2:
//[-2,0,1]
//[-2,0,3]
//
//Example 2:
//Input: nums = [], target = 0
//Output: 0
//
//Example 3:
//Input: nums = [0], target = 0
//Output: 0
// 
//Constraints:
//n == nums.length
//0 <= n <= 3500
//-100 <= nums[i] <= 100
//-100 <= target <= 100

namespace Solution2022
{
	namespace ThreeSumSmaller
	{
	    int threeSumSmaller(vector<int>& nums, int target) {			
			int len = nums.size();
			if (len < 3) { return 0; }

			int result = 0;
			sort(nums.begin(), nums.end());
			for (int k = len - 1; k >= 2; k--) {
				int i = 0;
				int j = k - 1;
				while (i < j) {
					int sum = nums[i] + nums[j] + nums[k];
					if (sum < target) {
						result += j - i;
						i++;
					}
					else {
						j--;
					}
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
