#include "stdafx.h"

//Given an integer array nums and two integers k and t, return true if there are
//two distinct indices i and j in the array such that abs(nums[i] - nums[j]) <= t
//and abs(i - j) <= k.
// 
//
//Example 1:
//Input: nums = [1,2,3,1], k = 3, t = 0
//Output: true
//
//Example 2:
//Input: nums = [1,0,1,1], k = 1, t = 2
//Output: true
//
//Example 3:
//Input: nums = [1,5,9,1,5,9], k = 2, t = 3
//Output: false
// 
//Constraints:
//1 <= nums.length <= 2 * 104
//-231 <= nums[i] <= 231 - 1
//0 <= k <= 104
//0 <= t <= 231 - 1

namespace Solution2022
{
	namespace ContainsDuplicateIII
	{	
		//Should we use a multi-set? 
		//No. You assume that we could have duplicates in the window that we try to maintain
		//along the way. However, this situation will never happen. Think about it, if we
		//try to insert a duplicate into the window, it means that we've already found
		//the target pair that satisfies the requirement of the problem.
		//Since we already have a duplicate number in the current window, so the absolute
		//difference is 0, must be smaller or equal to t.
		//The distance between the duplicate number that shares the same value with the
		//current value must be smaller than k.
		//Therefore, this program will return true before the situation that you have
		//described even becomes true.

	    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
			set<int> window;
			for (int i = 0; i < nums.size(); i++) {
				if (i > k) { window.erase(nums[i - k - 1]); } // Note: erase nums[i-k-1], not erase i-k-1!!!
				auto it = window.lower_bound(nums[i]);
				if (it != window.end() && *it - nums[i] <= t) { return true; }
				if (it != window.begin() && nums[i] - *prev(it) <= t) { return true; }
				window.insert(nums[i]);
			}
			return false;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
