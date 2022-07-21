#include "stdafx.h"

//Given an array of integers nums and an integer k, return the number of unique
//k-diff pairs in the array.
//A k-diff pair is an integer pair (nums[i], nums[j]), where the following are
//true:
//0 <= i, j < nums.length
//i != j
//nums[i] - nums[j] == k
//Notice that |val| denotes the absolute value of val.
// 
//
//Example 1:
//Input: nums = [3,1,4,1,5], k = 2
//Output: 2
//Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
//Although we have two 1s in the input, we should only return the number of
//unique pairs.
//
//Example 2:
//Input: nums = [1,2,3,4,5], k = 1
//Output: 4
//Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4)
//and (4, 5).
//
//Example 3:
//Input: nums = [1,3,1,5,4], k = 0
//Output: 1
//Explanation: There is one 0-diff pair in the array, (1, 1).
// 
//Constraints:
//1 <= nums.length <= 104
//-107 <= nums[i] <= 107
//0 <= k <= 107

namespace Solution2022
{
	namespace KdiffPairsinanArray
	{
		namespace UseMap {
			int findPairs(vector<int>& nums, int k) {
				if (k < 0) { return 0; }

				unordered_map<int, int> map;
				for (int v : nums) { map[v]++; }

				int result = 0;
				for (auto& [key, count] : map) {
					int target = key + k;
					if (target == key && count > 1) { result++; }
					else if (target != key && map.find(target) != map.end()) { result++; }
				}
				return result;
			}
		}

		namespace UseSlidingWindow {
			int findPairs(vector<int>& nums, int k) {
				if (k < 0) { return 0; }

				sort(nums.begin(), nums.end());

				int len = nums.size();
				int start = 0;
				int end = 0;
				int result = 0;

				while (start < len) {
					int target = nums[start] + k;
					end = start + 1;
					while (end < len && nums[end] < target) { end++; }
					if (end < len && nums[end] == target) { result++; }
					while (start + 1 < len && nums[start] == nums[start + 1]) { start++; }
					start++;
				}
				return result;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
