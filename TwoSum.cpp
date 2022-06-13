#include "stdafx.h"

//Given an array of integers nums and an integer target, return indices of the
//two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not
//use the same element twice.
//You can return the answer in any order.
// 
//
//Example 1:
//Input: nums = [2,7,11,15], target = 9
//Output: [0,1]
//Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
//
//Example 2:
//Input: nums = [3,2,4], target = 6
//Output: [1,2]
//
//Example 3:
//Input: nums = [3,3], target = 6
//Output: [0,1]
// 
//Constraints:
//2 <= nums.length <= 104
//-109 <= nums[i] <= 109
//-109 <= target <= 109
//Only one valid answer exists.
// 
//Follow-up: Can you come up with an algorithm that is less than O(n2) time
//complexity?

namespace Solution2022
{
	namespace TwoSum
	{
		vector<int> twoSumWithHash(vector<int>& nums, int target) {
			int len = nums.size();
			unordered_map<int, int> map;
			for (int i = 0; i < len; i++) {
				if (map.find(target - nums[i]) != map.end()) {
					return { map[target - nums[i]], i };
				}
				map[nums[i]] = i;
			}
			return {};
		}

	    vector<int> twoSumWithSort(vector<int>& nums, int target) {
			int len = nums.size();
			vector<int> result;

			vector<pair<int, int>> n;
			for (int i = 0; i < len; i++) {
				n.push_back({nums[i], i});
			}
			sort(n.begin(), n.end());
		
			int start = 0;
			int end = len - 1;
			while (start < end) {
				int sum = n[start].first + n[end].first;
				if (sum == target) {
					result.push_back(n[start].second);
					result.push_back(n[end].second);
					return result;
				}
				else if (sum < target) {
					start++;
				}
				else {
					end--;
				}
			}
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
