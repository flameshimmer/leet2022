#include "stdafx.h"

//Given an integer array nums and an integer k, return the maximum length of a
//subarray that sums to k. If there is not one, return 0 instead.
// 
//
//Example 1:
//Input: nums = [1,-1,5,-2,3], k = 3
//Output: 4
//Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
//
//Example 2:
//Input: nums = [-2,-1,2,1], k = 1
//Output: 2
//Explanation: The subarray [-1, 2] sums to 1 and is the longest.
// 
//Constraints:
//1 <= nums.length <= 2 * 105
//-104 <= nums[i] <= 104
//-109 <= k <= 109

namespace Solution2022
{
	namespace MaximumSizeSubarraySumEqualsk
	{
	    int maxSubArrayLen(vector<int>& nums, int k) {
			unordered_map<int, int> map;
			long long sum = 0; // Note: need to initialize to 0!!!
			int result = 0;

			for (int i = 0; i < nums.size(); i++) {
				sum += nums[i];
				if (sum == k) { result = i + 1; }
				else if (map.find(sum - k) != map.end()) { result = max(result, i - map[sum - k]); }
				if (map.find(sum) == map.end()) { map[sum] = i; }
			}
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
