#include "stdafx.h"

//Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] <
//nums[3]....
//You may assume the input array always has a valid answer.
// 
//
//Example 1:
//Input: nums = [1,5,1,1,6,4]
//Output: [1,6,1,5,1,4]
//Explanation: [1,4,1,5,1,6] is also accepted.
//
//Example 2:
//Input: nums = [1,3,2,2,3,1]
//Output: [2,3,1,3,1,2]
// 
//Constraints:
//1 <= nums.length <= 5 * 104
//0 <= nums[i] <= 5000
//It is guaranteed that there will be an answer for the given input nums.
// 
//Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?

namespace Solution2022
{
	namespace WiggleSortII
	{
		void wiggleSort(vector<int>& nums) {
			vector<int> sorted = nums;
			sort(sorted.begin(), sorted.end());

			int len = nums.size();
			int i1 = 0;
			// if lenght is odd, then we need smaller section to be one more than larger section
			// if length is even, then we need the smaller section to be the same as larger section. 
			int i2 = (len - 1) / 2 + 1;

			for (int i = len - 1; i >= 0; i--) { // fill from the back to ensure equal number are not placed together. 
				if (i % 2 == 0) {
					nums[i] = sorted[i1];
					i1++;
				}
				else {
					nums[i] = sorted[i2];
					i2++;
				}
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
