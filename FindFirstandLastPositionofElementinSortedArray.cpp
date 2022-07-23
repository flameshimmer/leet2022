#include "stdafx.h"

//Given an array of integers nums sorted in non-decreasing order, find the
//starting and ending position of a given target value.
//If target is not found in the array, return [-1, -1].
//You must write an algorithm with O(log n) runtime complexity.
// 
//
//Example 1:
//Input: nums = [5,7,7,8,8,10], target = 8
//Output: [3,4]
//
//Example 2:
//Input: nums = [5,7,7,8,8,10], target = 6
//Output: [-1,-1]
//
//Example 3:
//Input: nums = [], target = 0
//Output: [-1,-1]
// 
//Constraints:
//0 <= nums.length <= 105
//-109 <= nums[i] <= 109
//nums is a non-decreasing array.
//-109 <= target <= 109

namespace Solution2022
{
	namespace FindFirstandLastPositionofElementinSortedArray
	{
		namespace UseBinarySearch {
			int findLower(vector<int>& nums, int target) {
				int start = 0;
				int end = nums.size() - 1;
				while (start < end) {
					int mid = start + (end - start) / 2;
					if (target <= nums[mid]) {
						end = mid;
					}
					else {
						start = mid+1;
					}
				}
				return nums[start] == target ? start : -1;
			}

			int findUpper(vector<int>& nums, int target) {
				int start = 0;
				int end = nums.size() - 1;
				while (start < end) {
					int mid = start + (end - start) / 2 + 1;
					if (target >= nums[mid]) {
						start = mid;
					}
					else {
						end = mid -1;
					}
				}
				return nums[start] == target ? start : -1;
			}



			vector<int> searchRange(vector<int>& nums, int target) {
				int len = nums.size();
				if (len == 0) { return {-1, -1}; }
				return { findLower(nums, target), findUpper(nums, target)};
			}		
		}

		namespace UseStdLib {
			vector<int> searchRange(vector<int>& nums, int target) {
				auto lower = lower_bound(nums.begin(), nums.end(), target);
				if (lower == nums.end() || *lower != target) { return { -1, -1 }; }

				auto upper = upper_bound(nums.begin(), nums.end(), target);
				return { (int)(lower - nums.begin()), (int)(upper - 1 - nums.begin()) };
			}
		}
	    

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
