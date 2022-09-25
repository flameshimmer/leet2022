#include "stdafx.h"

//Given an array nums of n integers where nums[i] is in the range [1, n], return
//an array of all the integers in the range [1, n] that do not appear in nums.
// 
//
//Example 1:
//Input: nums = [4,3,2,7,8,2,3,1]
//Output: [5,6]
//
//Example 2:
//Input: nums = [1,1]
//Output: [2]
// 
//Constraints:
//n == nums.length
//1 <= n <= 105
//1 <= nums[i] <= n
// 
//Follow up: Could you do it without extra space and in O(n) runtime? You may
//assume the returned list does not count as extra space.

namespace Solution2022
{
	namespace FindAllNumbersDisappearedinanArray
	{
		vector<int> findDisappearedNumbers(vector<int>& nums) {
			int len = nums.size();
			for (int v : nums) {
				int index = abs(v) - 1; // NOTE: this should be abs(v) instead of v, since v can be a negative number!!!
				if (nums[index] > 0) { nums[index] *= -1; }
			}
			vector<int> result;
			for (int i = 0; i < len; i++) {
				if (nums[i] > 0) { result.push_back(i + 1); }
			}
			return result;
		}

		void Main() {
			vector<int> test = { 4,3,2,7,8,2,3,1 };
			print(findDisappearedNumbers(test));
		}
	}
}
