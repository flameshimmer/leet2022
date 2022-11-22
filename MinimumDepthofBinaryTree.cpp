#include "stdafx.h"

//Given a binary tree, find its minimum depth.
//The minimum depth is the number of nodes along the shortest path from the root
//node down to the nearest leaf node.
//
//Note: A leaf is a node with no children.
// 
//
//Example 1:
//Input: root = [3,9,20,null,null,15,7]
//Output: 2
//
//Example 2:
//Input: root = [2,null,3,null,4,null,5,null,6]
//Output: 5
// 
//Constraints:
//The number of nodes in the tree is in the range [0, 105].
//-1000 <= Node.val <= 1000

namespace Solution2022
{
	namespace MinimumDepthofBinaryTree
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

		void helper(TreeNode* node, int curLevel, int& result) {
			if (!node) { return; }
			if (!node->left && !node->right) { result = min(result, curLevel); }
			helper(node->left, curLevel + 1, result);
			helper(node->right, curLevel + 1, result);
		}

	    int minDepth(TreeNode* root) {
			if (!root) { return 0; }
			int result = INT_MAX;
			helper(root, 1, result);
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
