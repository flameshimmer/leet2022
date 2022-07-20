#include "stdafx.h"

//Given an unsorted array of integers nums, return the length of the longest
//consecutive elements sequence.
//You must write an algorithm that runs in O(n) time.
// 
//
//Example 1:
//Input: nums = [100,4,200,1,3,2]
//Output: 4
//Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
//Therefore its length is 4.
//
//Example 2:
//Input: nums = [0,3,7,2,5,8,4,6,0,1]
//Output: 9
// 
//Constraints:
//0 <= nums.length <= 105
//-109 <= nums[i] <= 109

namespace Solution2022
{
	namespace LongestConsecutiveSequence
	{
	    int longestConsecutive(vector<int>& nums) {
			int len = nums.size();
			if (len < 2) { return len; }

			int result = 0;
			unordered_set<int> set(nums.begin(), nums.end());
			for (int v : nums) {
				if (set.find(v) == set.end()) { continue; }
				set.erase(v);

				int start = v - 1;
				int end = v + 1;
				while (set.find(start) != set.end()) { set.erase(start); start--; }
				while (set.find(end) != set.end()) { set.erase(end); end++; }
				result = max(result, end - start - 1);
			}
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
