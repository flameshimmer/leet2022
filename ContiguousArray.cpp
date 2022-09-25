#include "stdafx.h"

//Given a binary array nums, return the maximum length of a contiguous subarray
//with an equal number of 0 and 1.
// 
//
//Example 1:
//Input: nums = [0,1]
//Output: 2
//Explanation: [0, 1] is the longest contiguous subarray with an equal number of
//0 and 1.
//
//Example 2:
//Input: nums = [0,1,0]
//Output: 2
//Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
//number of 0 and 1.
// 
//Constraints:
//1 <= nums.length <= 105
//nums[i] is either 0 or 1.

namespace Solution2022
{
	namespace ContiguousArray
	{
		int findMaxLength(vector<int>& nums) {
			int len = nums.size();
			if (len == 0) { return 0; }

			unordered_map<int, int> map;
			int sum = 0;
			int result = 0;

			for (int i = 0; i < len; i++) {
				sum += (nums[i] == 0) ? -1 : 1;
				if (sum == 0) { result = i + 1; }
				else if (map.find(sum) != map.end()) { result = max(result, i - (map[sum] + 1) + 1); }
				else { map[sum] = i; }
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
