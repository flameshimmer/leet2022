#include "stdafx.h"

//If the depth of a tree is smaller than 5, then this tree can be represented by
//an array of three-digit integers. For each integer in this array:
//The hundreds digit represents the depth d of this node where 1 <= d <= 4.
//The tens digit represents the position p of this node in the level it belongs
//to where 1 <= p <= 8. The position is the same as that in a full binary tree.
//The units digit represents the value v of this node where 0 <= v <= 9.
//Given an array of ascending three-digit integers nums representing a binary
//tree with a depth smaller than 5, return the sum of all paths from the root
//towards the leaves.
//It is guaranteed that the given array represents a valid connected binary tree.
// 
//
//Example 1:
//Input: nums = [113,215,221]
//Output: 12
//Explanation: The tree that the list represents is shown.
//The path sum is (3 + 5) + (3 + 1) = 12.
//
//Example 2:
//Input: nums = [113,221]
//Output: 4
//Explanation: The tree that the list represents is shown. 
//The path sum is (3 + 1) = 4.
// 
//Constraints:
//1 <= nums.length <= 15
//110 <= nums[i] <= 489
//nums represents a valid binary tree with depth less than 5.

namespace Solution2022
{
	namespace PathSumIV
	{
		void helper(int node, int curSum, unordered_map<int, int>& map, int& result) {
			if (map.find(node) == map.end()) { return; }

			int curLevel = node / 10;
			int curPos = node % 10;
			int leftChild = (curLevel + 1) * 10 + curPos * 2 - 1;
			int rightChild = (curLevel + 1) * 10 + curPos * 2;
			bool hasLeftChild = map.find(leftChild) != map.end();
			bool hasRightChild = map.find(rightChild) != map.end();

			curSum += map[node];
			if (!hasLeftChild && !hasRightChild) {
				result += curSum;
				return;
			}

			if (hasLeftChild) { helper(leftChild, curSum, map, result); }
			if (hasRightChild) { helper(rightChild, curSum, map, result); }
		}

		int pathSum(vector<int>& nums) {
			unordered_map<int, int> map;
			for (int v : nums) {
				map[v / 10] = v % 10;
			}

			int result = 0;
			helper(11, 0, map, result);
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
