#include "stdafx.h"

//Given an array of integers nums containing n + 1 integers where each integer is
//in the range [1, n] inclusive.
//There is only one repeated number in nums, return this repeated number.
//You must solve the problem without modifying the array nums and uses only
//constant extra space.
// 
//
//Example 1:
//Input: nums = [1,3,4,2,2]
//Output: 2
//
//Example 2:
//Input: nums = [3,1,3,4,2]
//Output: 3
// 
//Constraints:
//1 <= n <= 105
//nums.length == n + 1
//1 <= nums[i] <= n
//All the integers in nums appear only once except for precisely one integer
//which appears two or more times.
// 
//Follow up:
//How can we prove that at least one duplicate number must exist in nums?
//Can you solve the problem in linear runtime complexity?

namespace Solution2022
{
	namespace FindtheDuplicateNumber
	{
		namespace CircleInLinkedList {
			/*index is from node, value is to node.
			When two index with the same value, then this creates a loop in the linked list*/
			int findDuplicate(vector<int>& nums) {
				int len = nums.size();
				if (len < 2) { return -1; }

				int slow = nums[0];
				int fast = nums[nums[0]];
				while (slow != fast) {
					slow = nums[slow];
					fast = nums[nums[fast]];
				}

				fast = 0;
				while (slow != fast) {
					slow = nums[slow];
					fast = nums[fast];
				}
				return fast;
			}
		}

		namespace NegativeMarking {
			int findDuplicate(vector<int>& nums) {
				int duplicate = -1;
				for (int i = 0; i < nums.size(); i++) {
					int cur = abs(nums[i]);
					if (nums[cur] < 0) {
						duplicate = cur;
						break;
					}
					nums[cur] *= -1;
				}

				// Restore numbers
				for (auto& num : nums)
					num = abs(num);

				return duplicate;
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
