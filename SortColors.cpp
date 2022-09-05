#include "stdafx.h"

//Given an array nums with n objects colored red, white, or blue, sort them
//in-place so that objects of the same color are adjacent, with the colors in the
//order red, white, and blue.
//We will use the integers 0, 1, and 2 to represent the color red, white, and
//blue, respectively.
//You must solve this problem without using the library's sort function.
// 
//
//Example 1:
//Input: nums = [2,0,2,1,1,0]
//Output: [0,0,1,1,2,2]
//
//Example 2:
//Input: nums = [2,0,1]
//Output: [0,1,2]
// 
//Constraints:
//n == nums.length
//1 <= n <= 300
//nums[i] is either 0, 1, or 2.
// 
//Follow up: Could you come up with a one-pass algorithm using only constant
//extra space?

namespace Solution2022
{
	namespace SortColors
	{
		void sortColors(vector<int>& nums) {
			int start = 0;
			int end = nums.size() - 1;
			for (int i = 0; i <= end; i++) { // ----> note i is <= end, and not < end. This is because end is the copy position, it has not been processed yet. 
				if (nums[i] == 0) {
					swap(nums[start], nums[i]);
					start++;
				}
				else if (nums[i] == 2) {
					swap(nums[i], nums[end]);
					end--;
					i--;  //----------> note that i-- is only needed when swapping with end!!!
					      //Why does start not need it? if start < i, it means it has to be 0, if start > i, we'll have to process it later anyway. 
						  //But for end, since i <= end,  we can't guarantee the end's data is processed. Thus need to i-- to ensure it is processed here. 
				}
			}
		}

		void Main() {
			vector<int> test = { 2,0,2,1,1,0 };
			sortColors(test);
		}
	}
}
