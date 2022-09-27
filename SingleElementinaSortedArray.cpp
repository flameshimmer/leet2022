#include "stdafx.h"

//You are given a sorted array consisting of only integers where every element
//appears exactly twice, except for one element which appears exactly once.
//Return the single element that appears only once.
//Your solution must run in O(log n) time and O(1) space.
// 
//
//Example 1:
//Input: nums = [1,1,2,3,3,4,4,8,8]
//Output: 2
//
//Example 2:
//Input: nums = [3,3,7,7,10,11,11]
//Output: 10
// 
//Constraints:
//1 <= nums.length <= 105
//0 <= nums[i] <= 105

namespace Solution2022
{
	namespace SingleElementinaSortedArray
	{
		int singleNonDuplicate(vector<int>& nums) {
			int len = nums.size();
			int l = 0;
			int r = len - 1;
			while (l < r) {
				int mid = l + (r - l) / 2;
				// If it is the two condition where the single element doesn't show up in the left half of the vector
				if ((mid % 2 && nums[mid] == nums[mid - 1]) || (!(mid % 2) && nums[mid] == nums[mid + 1])) { l = mid + 1; }
				else { r = mid; }
			}
			return nums[l];
		}

		void Main() {
			vector<int> test = { 1,1,2,3,3,4,4,8,8 };
			print(singleNonDuplicate(test));
		}
	}
}
