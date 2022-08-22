#include "stdafx.h"

//Given the root of a binary tree, return the postorder traversal of its nodes'
//values.
// 
//
//Example 1:
//Input: root = [1,null,2,3]
//Output: [3,2,1]
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
//The number of the nodes in the tree is in the range [0, 100].
//-100 <= Node.val <= 100
// 
//Follow up: Recursive solution is trivial, could you do it iteratively?

namespace Solution2022
{
	namespace BinaryTreePostorderTraversal
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
			vector<int> postorderTraversal(TreeNode* root) {
				vector<int> result;
				if (!root) { return result; }

				TreeNode* cur = root;
				TreeNode* prev = nullptr;
				stack<TreeNode*> s;

				while (!s.empty() || cur) {
					if (cur) { 
						s.push(cur); 
						cur = cur->left;
					}
					else {
						TreeNode* top = s.top();
						if (top->right && top->right != prev) {
							cur = top->right;
						}else {
							s.pop();
							result.push_back(top->val);
							prev = top;
						}
					}				
				}
				return result;
			}
		}

		namespace recursive {
			void helper(TreeNode* node, vector<int>& result) {
				if (!node) { return; }
				helper(node->left, result);
				helper(node->right, result);
				result.push_back(node->val);
			}

			vector<int> postorderTraversal(TreeNode* root) {
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
