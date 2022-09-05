#include "stdafx.h"

//Given the root of a binary tree, return the zigzag level order traversal of its
//nodes' values. (i.e., from left to right, then right to left for the next level
//and alternate between).
// 
//
//Example 1:
//Input: root = [3,9,20,null,null,15,7]
//Output: [[3],[20,9],[15,7]]
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
//-100 <= Node.val <= 100

namespace Solution2022
{
	namespace BinaryTreeZigzagLevelOrderTraversal
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
	    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
			vector<vector<int>> results;
			if (!root) { return results; }

			queue<TreeNode*> q;
			q.push(root);

			bool ltr = true;
			while (!q.empty()) {
				int sz = q.size();
				vector<int> result(sz);
				for (int i = 0; i < sz; i++) {					
					TreeNode* top = q.front();
					q.pop();

					int index = ltr ? i : sz - 1 - i;
					result[index] = top->val;

					if (top->left) { q.push(top->left); }
					if (top->right) { q.push(top->right); }
				}
				ltr = !ltr;
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
