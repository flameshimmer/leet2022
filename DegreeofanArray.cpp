#include "stdafx.h"

//Given a non-empty array of non-negative integers nums, the degree of this array
//is defined as the maximum frequency of any one of its elements.
//Your task is to find the smallest possible length of a (contiguous) subarray of
//nums, that has the same degree as nums.
// 
//
//Example 1:
//Input: nums = [1,2,2,3,1]
//Output: 2
//Explanation: 
//The input array has a degree of 2 because both elements 1 and 2 appear twice.
//Of the subarrays that have the same degree:
//[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
//The shortest length is 2. So return 2.
//
//Example 2:
//Input: nums = [1,2,2,3,1,4,2]
//Output: 6
//Explanation: 
//The degree is 3 because the element 2 is repeated 3 times.
//So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
// 
//Constraints:
//nums.length will be between 1 and 50,000.
//nums[i] will be an integer between 0 and 49,999.

namespace Solution2022
{
	namespace DegreeofanArray
	{
	    int findShortestSubArray(vector<int>& nums) {
			int len = nums.size();
			if (len < 2) { return len; }

			unordered_map<int, vector<int>> map;
			for (int i = 0; i < len; i++) { map[nums[i]].push_back(i); }

			int maxFreq = 0;
			int result = INT_MAX;
			for (auto& [val, arr] : map) {
				int freq = arr.size();
				int size = arr.back() - arr.front() + 1;
				if (freq > maxFreq) {
					maxFreq = freq;
					result = size;
				}
				else if (freq == maxFreq) {
					result = min(result, size);
				}
			}
			return result;
	    }

		void Main() {
			vector<int> test = {1,2,2,3,1};
			print(findShortestSubArray(test));
		}
	}
}
