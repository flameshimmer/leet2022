#include "stdafx.h"

//Given an array nums, return true if the array was originally sorted in
//non-decreasing order, then rotated some number of positions (including zero).
//Otherwise, return false.
//There may be duplicates in the original array.
//
//Note: An array A rotated by x positions results in an array B of the same
//length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.
// 
//
//Example 1:
//Input: nums = [3,4,5,1,2]
//Output: true
//Explanation: [1,2,3,4,5] is the original sorted array.
//You can rotate the array by x = 3 positions to begin on the the element of
//value 3: [3,4,5,1,2].
//
//Example 2:
//Input: nums = [2,1,3,4]
//Output: false
//Explanation: There is no sorted array once rotated that can make nums.
//
//Example 3:
//Input: nums = [1,2,3]
//Output: true
//Explanation: [1,2,3] is the original sorted array.
//You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
// 
//Constraints:
//1 <= nums.length <= 100
//1 <= nums[i] <= 100

namespace Solution2022
{
	namespace CheckifArrayIsSortedandRotated
	{
		bool check(vector<int>& nums) {
			int len = nums.size();
			if (len < 2) { return true; }

			int decCount = 0;
			for (int i = 1; i < len; i++) {
				if (nums[i] < nums[i - 1]) { decCount++; }
			}
			if (nums[len - 1] > nums[0]) { decCount++; }
			return decCount <= 1;
		}

		namespace ModifyArray {
			bool check(vector<int>& nums) {
				int len = nums.size();
				if (len < 2) { return true; }

				int i = 1;
				for (; i < len; i++) {
					if (nums[i] < nums[i - 1]) { break; }
				}
				if (i == len) { return true; }

				for (int j = 0; j < i; j++) { nums.push_back(nums[j]); }
				return is_sorted(nums.begin() + i, nums.end());
			}
		}

		void Main() {
			vector<int> test = { 1, 3,2 };
			print(check(test));
		}
	}
}
