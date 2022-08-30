#include "stdafx.h"

//Given an integer array nums and an integer k, return true if nums has a
//continuous subarray of size at least two whose elements sum up to a multiple of
//k, or false otherwise.
//An integer x is a multiple of k if there exists an integer n such that x = n *
//k. 0 is always a multiple of k.
// 
//
//Example 1:
//Input: nums = [23,2,4,6,7], k = 6
//Output: true
//Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to
//6.
//
//Example 2:
//Input: nums = [23,2,6,4,7], k = 6
//Output: true
//Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose
//elements sum up to 42.
//42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
//
//Example 3:
//Input: nums = [23,2,6,4,7], k = 13
//Output: false
// 
//Constraints:
//1 <= nums.length <= 105
//0 <= nums[i] <= 109
//0 <= sum(nums[i]) <= 231 - 1
//1 <= k <= 231 - 1

namespace Solution2022
{
	namespace ContinuousSubarraySum
	{
		/*
		Need (sum1 - sum2) % k = 0,
		which means sum1%k = sum2%k,
		and sum1 and sum2 must have length diff of at least 2*/

		namespace CheckIndexWithMap {
			bool checkSubarraySum(vector<int>& nums, int k) {
				int len = nums.size();
				int sum = 0;
				unordered_map<int, int> map;
				map[0] = -1; // Need this!!!!

				for (int i = 0; i < len; i++) {
					sum += nums[i];
					int mod = (k == 0) ? sum : sum % k;
					bool exists = map.find(mod) != map.end();
					if (exists && i - map[mod] > 1) { return true; }
					if (!exists) { map[mod] = i; }
				}
				return false;
			}
		}
		
		namespace UsingPrevMod {
			bool checkSubarraySum(vector<int>& nums, int k) {
				int sum = 0;
				int prevMod = 0;
				unordered_set<int> set;

				for (int v : nums) {
					sum += v;
					int mod = (k == 0) ? sum : sum % k;
					if (set.find(mod) != set.end()) { return true; }
					set.insert(prevMod);
					prevMod = mod;
				}
				return false;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
