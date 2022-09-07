#include "stdafx.h"

//Given an integer array nums where the elements are sorted in ascending order,
//convert it to a height-balanced binary search tree.
//A height-balanced binary tree is a binary tree in which the depth of the two
//subtrees of every node never differs by more than one.
// 
//
//Example 1:
//Input: nums = [-10,-3,0,5,9]
//Output: [0,-3,9,-10,null,5]
//Explanation: [0,-10,5,null,-3,null,9] is also accepted:
//
//Example 2:
//Input: nums = [1,3]
//Output: [3,1]
//Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
// 
//Constraints:
//1 <= nums.length <= 104
//-104 <= nums[i] <= 104
//nums is sorted in a strictly increasing order.

namespace Solution2022
{
	namespace ConvertSortedArraytoBinarySearchTree
	{
	/**
	 * Definition for a binary tree node.
	 * struct TreeNode {
	 *     int val;
	 *     TreeNode *left;
	 *     TreeNode *right;
	 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
	 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	 * };
	 */
		TreeNode* helper(vector<int>& nums, int start, int end) {
			if (start > end) { return nullptr; }
			
			int mid = start + (end - start) / 2;
			TreeNode* newNode = new TreeNode(nums[mid]);
			newNode->left = helper(nums, start, mid - 1);
			newNode->right = helper(nums, mid + 1, end);

			return newNode;
		}

	    TreeNode* sortedArrayToBST(vector<int>& nums) {
			int len = nums.size();
			if (len == 0) { return nullptr; }

			return helper(nums, 0, len - 1);
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
