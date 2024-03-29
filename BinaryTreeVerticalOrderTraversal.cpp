#include "stdafx.h"

//Given the root of a binary tree, return the vertical order traversal of its
//nodes' values. (i.e., from top to bottom, column by column).
//If two nodes are in the same row and column, the order should be from left to
//right.
// 
//
//Example 1:
//Input: root = [3,9,20,null,null,15,7]
//Output: [[9],[3,15],[20],[7]]
//
//Example 2:
//Input: root = [3,9,8,4,0,1,7]
//Output: [[4],[9],[3,0,1],[8],[7]]
//
//Example 3:
//Input: root = [3,9,8,4,0,1,7,null,null,null,2,5]
//Output: [[4],[9,5],[3,0,1],[8,2],[7]]
// 
//Constraints:
//The number of nodes in the tree is in the range [0, 100].
//-100 <= Node.val <= 100

namespace Solution2022
{
	namespace BinaryTreeVerticalOrderTraversal
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


		vector<vector<int>> verticalOrder(TreeNode* root) {
			vector<vector<int>> result;

			if (!root) { return result; }

			queue<pair<TreeNode*, int>> q;
			q.push({ root, 0 }); // if root node is at column 0;
			map<int, vector<int>> map;

			while (!q.empty()) {
				TreeNode* top = q.front().first;
				int v = q.front().second;
				q.pop();

				map[v].push_back(top->val);
				if (top->left) {
					q.push({ top->left, v - 1 });
				}
				if (top->right) {
					q.push({ top->right, v + 1 });
				}
			}

			for (const auto& v : map) {
				result.push_back(v.second);
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
