#include "stdafx.h"

//You are given a 0-indexed integer array nums and a target element target.
//A target index is an index i such that nums[i] == target.
//Return a list of the target indices of nums after sorting nums in
//non-decreasing order. If there are no target indices, return an empty list. The
//returned list must be sorted in increasing order.
// 
//
//Example 1:
//Input: nums = [1,2,5,2,3], target = 2
//Output: [1,2]
//Explanation: After sorting, nums is [1,2,2,3,5].
//The indices where nums[i] == 2 are 1 and 2.
//
//Example 2:
//Input: nums = [1,2,5,2,3], target = 3
//Output: [3]
//Explanation: After sorting, nums is [1,2,2,3,5].
//The index where nums[i] == 3 is 3.
//
//Example 3:
//Input: nums = [1,2,5,2,3], target = 5
//Output: [4]
//Explanation: After sorting, nums is [1,2,2,3,5].
//The index where nums[i] == 5 is 4.
// 
//Constraints:
//1 <= nums.length <= 100
//1 <= nums[i], target <= 100

namespace Solution2022
{
	namespace FindTargetIndicesAfterSortingArray
	{

		namespace ON {
			// count the number of num that is smaller and equal
			vector<int> targetIndices(vector<int>& nums, int target) {
				int smallerCount = 0;
				int count = 0;

				for (int v : nums) {
					count += v == target;
					smallerCount += v < target;
				}

				vector<int> result;
				for (int i = smallerCount; i < smallerCount + count; i++) { result.push_back(i); }
				return result;
			}
		}

		namespace ONLogN {
			vector<int> targetIndices(vector<int>& nums, int target) {
				vector<int> result;
				int len = nums.size();
				if (len == 0) { return result; }
				sort(nums.begin(), nums.end());
				auto it = lower_bound(nums.begin(), nums.end(), target);
				if (it == nums.end()) { return result; }

				while (it != nums.end() && *it == target) { result.push_back(it - nums.begin()); it++; }
				return result;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
