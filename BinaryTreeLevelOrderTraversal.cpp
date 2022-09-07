#include "stdafx.h"

//Given the root of a binary tree, return the level order traversal of its nodes'
//values. (i.e., from left to right, level by level).
// 
//
//Example 1:
//Input: root = [3,9,20,null,null,15,7]
//Output: [[3],[9,20],[15,7]]
//
//Example 2:
//Input: root = [1]
//Output: [[1]]
//
//Example 3:
//Input: root = []
//Output: []
// 
//Constraints:
//The number of nodes in the tree is in the range [0, 2000].
//-1000 <= Node.val <= 1000

namespace Solution2022
{
	namespace BinaryTreeLevelOrderTraversal
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
	    vector<vector<int>> levelOrder(TreeNode* root) {
			vector<vector<int>> results;
			if (!root) { return results; }

			queue<TreeNode*> q;
			q.push(root);
			while (!q.empty()) {
				int sz = q.size();
				vector<int> result;
				while (sz) {
					sz--;
					
					TreeNode* top = q.front();
					q.pop();
					result.push_back(top->val);

					if (top->left) { q.push(top->left); }
					if (top->right) { q.push(top->right); }
				}
				results.push_back(result);
			}
			return results;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
