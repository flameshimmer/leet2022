#include "stdafx.h"

//Given an array of integers nums and an integer k, return the total number of
//subarrays whose sum equals to k.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//
//Example 1:
//Input: nums = [1,1,1], k = 2
//Output: 2
//
//Example 2:
//Input: nums = [1,2,3], k = 3
//Output: 2
// 
//Constraints:
//1 <= nums.length <= 2 * 104
//-1000 <= nums[i] <= 1000
//-107 <= k <= 107

namespace Solution2022
{
	namespace SubarraySumEqualsK
	{
	    int subarraySum(vector<int>& nums, int k) {
			unordered_map<int, int> map;
			int curSum = 0;
			int result = 0;
			map[0] = 1;

			for (int v : nums) {
				curSum += v;
				int toBeFound = curSum - k;
				if (map.find(toBeFound) != map.end()) {
					result += map[toBeFound];
				}
				map[curSum] ++;
			}
			return result;
	    }

		void Main() {
			vector<int> test = { 1,2,3 };
			print(subarraySum(test, 3));
		}
	}
}
