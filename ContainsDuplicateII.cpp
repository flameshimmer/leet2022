#include "stdafx.h"

//Given an integer array nums and an integer k, return true if there are two
//distinct indices i and j in the array such that nums[i] == nums[j] and abs(i -
//j) <= k.
// 
//
//Example 1:
//Input: nums = [1,2,3,1], k = 3
//Output: true
//
//Example 2:
//Input: nums = [1,0,1,1], k = 1
//Output: true
//
//Example 3:
//Input: nums = [1,2,3,1,2,3], k = 2
//Output: false
// 
//Constraints:
//1 <= nums.length <= 105
//-109 <= nums[i] <= 109
//0 <= k <= 105

namespace Solution2022
{
	namespace ContainsDuplicateII
	{
	    bool containsNearbyDuplicate(vector<int>& nums, int k) {
			int len = nums.size();
			unordered_map<int, int> map;
			for (int i = 0; i < nums.size(); i++) {
				int v = nums[i];
				if (map.find(v) == map.end()) { map[v] = i; }
				else {
					if (i - map[v] <= k) { return true; }
					map[v] = i;
				}
			}
			return false;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
