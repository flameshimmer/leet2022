#include "stdafx.h"

//Given an array of n integers nums, a 132 pattern is a subsequence of three
//integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k]
//< nums[j].
//Return true if there is a 132 pattern in nums, otherwise, return false.
// 
//
//Example 1:
//Input: nums = [1,2,3,4]
//Output: false
//Explanation: There is no 132 pattern in the sequence.
//
//Example 2:
//Input: nums = [3,1,4,2]
//Output: true
//Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
//
//Example 3:
//Input: nums = [-1,3,2,0]
//Output: true
//Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3,
//0] and [-1, 2, 0].
// 
//Constraints:
//n == nums.length
//1 <= n <= 2 * 105
//-109 <= nums[i] <= 109

namespace Solution2022
{
	namespace OneThreeTwoPattern
	{
		bool find132pattern(vector<int>& nums) {
			int s2 = INT_MIN;
			stack<int> s;
			for (int i = nums.size() - 1; i >= 0; i--) {
				if (nums[i] < s2) { return true; }

				while (!s.empty() && nums[i] > s.top()) { // Note: this is > instead of >=, since we want the logic only invoked in 3..2 situation. 
					s2 = s.top();
					s.pop();
				}
				s.push(nums[i]);
			}
			return false;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
