#include "stdafx.h"

//Given the root of a binary tree, determine if it is a complete binary tree.
//In a complete binary tree, every level, except possibly the last, is completely
//filled, and all nodes in the last level are as far left as possible. It can
//have between 1 and 2h nodes inclusive at the last level h.
// 
//
//Example 1:
//Input: root = [1,2,3,4,5,6]
//Output: true
//Explanation: Every level before the last is full (ie. levels with node-values
//{1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as
//possible.
//
//Example 2:
//Input: root = [1,2,3,4,5,null,7]
//Output: false
//Explanation: The node with value 7 isn't as far left as possible.
// 
//Constraints:
//The number of nodes in the tree is in the range [1, 100].
//1 <= Node.val <= 1000

namespace Solution2022
{
	namespace CheckCompletenessofaBinaryTree
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

		namespace LevelOrderTraversal {
			bool isCompleteTree(TreeNode* root) {
				queue<TreeNode*> q;
				q.push(root);
				bool seenNull = false;

				while (!q.empty()) {
					TreeNode* top = q.front();
					q.pop();
					if (top == nullptr) { seenNull = true; }
					else {
						if (seenNull) { return false; } // when level order traversal, once seen null, all following can only be null
						q.push(top->left);
						q.push(top->right);
					}
				}
				return true;
			}
		}

		namespace BFS {
			bool isCompleteTree(TreeNode* root) {
				vector<TreeNode*> bfs;
				bfs.push_back(root);
				int i = 0;
				while (bfs[i]) {
					bfs.push_back(bfs[i]->left);
					bfs.push_back(bfs[i]->right);
					i++; // NOTE: don't forget to forward the i!!!
				}
				while (i < bfs.size() && !bfs[i]) { i++; } // once run into nullptr, we expect the rest should be nullptr;
				return i == bfs.size();
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
