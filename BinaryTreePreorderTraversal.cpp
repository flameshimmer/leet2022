#include "stdafx.h"

//Given the root of a binary tree, return the preorder traversal of its nodes'
//values.
// 
//
//Example 1:
//Input: root = [1,null,2,3]
//Output: [1,2,3]
//
//Example 2:
//Input: root = []
//Output: []
//
//Example 3:
//Input: root = [1]
//Output: [1]
// 
//Constraints:
//The number of nodes in the tree is in the range [0, 100].
//-100 <= Node.val <= 100
// 
//Follow up: Recursive solution is trivial, could you do it iteratively?

namespace Solution2022
{
	namespace BinaryTreePreorderTraversal
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
		namespace Iterative {		
			vector<int> preorderTraversal(TreeNode* root) {
				vector<int> result;
				if (!root) { return result; }

				stack<TreeNode*> s;
				s.push(root);

				while (!s.empty()) {
					TreeNode* top = s.top();
					s.pop();

					result.push_back(top->val);
					if (top->right) { s.push(top->right); }
					if (top->left) { s.push(top->left); }
				}
				return result;
			}
		}

		namespace Recursion {
			void helper(TreeNode* root, vector<int>& result) {
				if (!root) { return; }
				result.push_back(root->val);
				helper(root->left, result);
				helper(root->right, result);
			}

			vector<int> preorderTraversal(TreeNode* root) {
				vector<int> result;
				helper(root, result);
				return result;
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
