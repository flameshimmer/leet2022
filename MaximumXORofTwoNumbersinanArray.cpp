#include "stdafx.h"

//Given an integer array nums, return the maximum result of nums[i] XOR nums[j],
//where 0 <= i <= j < n.
// 
//
//Example 1:
//Input: nums = [3,10,5,25,2,8]
//Output: 28
//Explanation: The maximum result is 5 XOR 25 = 28.
//
//Example 2:
//Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
//Output: 127
// 
//Constraints:
//1 <= nums.length <= 2 * 105
//0 <= nums[i] <= 231 - 1

namespace Solution2022
{
	namespace MaximumXORofTwoNumbersinanArray
	{
		// https://www.youtube.com/watch?v=ZHtZfkAcPKc
		int findMaximumXOR(vector<int>& nums) {
			int mask = 0;
			int result = 0;
			unordered_set<int> set;

			for (int i = 31; i >= 0; i--) {
				mask |= (1 << i);
				int temp = result | (1 << i);
				for (int v : nums) {
					int maskedV = v & mask;
					if (set.find(temp ^ maskedV) != set.end()) {
						result = temp;
						break;
					}
					set.insert(maskedV);
				}
				set.clear();
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
