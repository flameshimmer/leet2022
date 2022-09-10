#include "stdafx.h"

//Given the root of a binary search tree and a node p in it, return the in-order
//successor of that node in the BST. If the given node has no in-order successor
//in the tree, return null.
//The successor of a node p is the node with the smallest key greater than p.val.
// 
//
//Example 1:
//Input: root = [2,1,3], p = 1
//Output: 2
//Explanation: 1's in-order successor node is 2. 
//Note that both p and the return
//value is of TreeNode type.
//
//Example 2:
//Input: root = [5,3,6,2,4,null,null,1], p = 6
//Output: null
//Explanation: There is no in-order successor of the current node, so the answer
//is null.
// 
//Constraints:
//The number of nodes in the tree is in the range [1, 104].
//-105 <= Node.val <= 105
//All Nodes will have unique values.

namespace Solution2022
{
	namespace InorderSuccessorinBST
	{
		/**
		 * Definition for a binary tree node.
		 * struct TreeNode {
		 *     int val;
		 *     TreeNode *left;
		 *     TreeNode *right;
		 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
		 * };
		 */
		TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
			if (!root) { return nullptr; }

			if (root->val <= p->val) {
				return inorderSuccessor(root->right, p);
			}
			else {
				TreeNode* left = inorderSuccessor(root->left, p);
				return left ? left : root;
			}
		}

		namespace Iterative {
			TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
				if (!root || !p) { return nullptr; }

				TreeNode* result = nullptr;
				while (root) {
					if (root->val <= p->val) { root = root->right; }
					else {
						result = root;
						root = root->left;
					}
				}
				return result;
			}
		}

		// This is to use the inorder traversal's previous node to find the next Tree node after target node
		namespace IterativeAnyTree {
			TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
				stack<TreeNode*> s;
				TreeNode* cur = root;
				TreeNode* result = nullptr;
				TreeNode* prev = nullptr;
				while (!s.empty() || cur) {
					if (cur) {
						s.push(cur);
						cur = cur->left;
					}
					else {
						TreeNode* top = s.top();
						s.pop();
						if (prev == p) { result = top; break; }
						else { prev = top; }
						cur = top->right;
					}
				}
				return result;
			}
		}

		namespace RecursiveAnyTree {
			bool helper(TreeNode* node, TreeNode* target, TreeNode*& result, bool& seen) {
				if (!node) { return false; }
				if (helper(node->left, target, result, seen)) { return true; }
				if (target == node && !seen) { seen = true; }
				else if (seen) { result = node; return true; }
				return helper(node->right, target, result, seen);
			}

			TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
				if (!root || !p) { return nullptr; }
				TreeNode* result = nullptr;
				bool seen = false;
				helper(root, p, result, seen);
				return result;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
