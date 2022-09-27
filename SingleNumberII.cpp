#include "stdafx.h"

//Given an integer array nums where every element appears three times except for
//one, which appears exactly once. Find the single element and return it.
//You must implement a solution with a linear runtime complexity and use only
//constant extra space.
// 
//
//Example 1:
//Input: nums = [2,2,3,2]
//Output: 3
//
//Example 2:
//Input: nums = [0,1,0,1,0,1,99]
//Output: 99
// 
//Constraints:
//1 <= nums.length <= 3 * 104
//-231 <= nums[i] <= 231 - 1
//Each element in nums appears exactly three times except for one element which
//appears once.

namespace Solution2022
{
	namespace SingleNumberII
	{
		int singleNumber(vector<int>& nums) {
			if (nums.size() == 1) { return nums[0]; }

			int result = 0;
			for (int i = 0; i < 32; i++) {
				int count = 0;
				for (int v : nums) {
					count += (v >> i) & 1;
				}
				count %= 3;
				result = result | (count << i);
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
