#include "stdafx.h"

//Given the root of a binary tree, collect a tree's nodes as if you were doing
//this:
//Collect all the leaf nodes.
//Remove all the leaf nodes.
//Repeat until the tree is empty.
// 
//
//Example 1:
//Input: root = [1,2,3,4,5]
//Output: [[4,5,3],[2],[1]]
//Explanation:
//[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers
//since per each level it does not matter the order on which elements are
//returned.
//
//Example 2:
//Input: root = [1]
//Output: [[1]]
// 
//Constraints:
//The number of nodes in the tree is in the range [1, 100].
//-100 <= Node.val <= 100

namespace Solution2022
{
	namespace FindLeavesofBinaryTree
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
		
		int helper(TreeNode* root, vector<vector<int>>& result) {
			if (!root) { return -1; }

			int curLevel = max(helper(root->left, result), helper(root->right, result)) + 1;
			if (curLevel + 1 > result.size()) {
				result.push_back({});
			}
			result[curLevel].push_back(root->val);
			return curLevel;
		}

	    vector<vector<int>> findLeaves(TreeNode* root) {
			vector<vector<int>> result;
			helper(root, result);
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
