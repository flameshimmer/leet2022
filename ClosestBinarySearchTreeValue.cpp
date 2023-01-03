#include "stdafx.h"

//Given the root of a binary search tree and a target value, return the value in
//the BST that is closest to the target.
// 
//
//Example 1:
//Input: root = [4,2,5,1,3], target = 3.714286
//Output: 4
//
//Example 2:
//Input: root = [1], target = 4.428571
//Output: 1
// 
//Constraints:
//The number of nodes in the tree is in the range [1, 104].
//0 <= Node.val <= 109
//-109 <= target <= 109

namespace Solution2022
{
	namespace ClosestBinarySearchTreeValue
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

		void helper(TreeNode* node, double target, double& minDist, int& result) {
			if (!node) { return; }
			double curDist = abs(node->val - target);
			if (curDist < minDist) {
				minDist = curDist;
				result = node->val;
			}
			if (target < node->val) { helper(node->left, target, minDist, result); }
			else if (target > node->val) { helper(node->right, target, minDist, result); }
		}

		int closestValue(TreeNode* root, double target) {
			if (!root) { return -1; }

			double minDist = DBL_MAX;
			int result = -1;
			helper(root, target, minDist, result);
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
