#include "stdafx.h"

//Given the root of a binary tree, flatten the tree into a "linked list":
//The "linked list" should use the same TreeNode class where the right child
//pointer points to the next node in the list and the left child pointer is
//always null.
//The "linked list" should be in the same order as a pre-order traversal of the
//binary tree.
// 
//
//Example 1:
//Input: root = [1,2,5,3,4,null,6]
//Output: [1,null,2,null,3,null,4,null,5,null,6]
//
//Example 2:
//Input: root = []
//Output: []
//
//Example 3:
//Input: root = [0]
//Output: [0]
// 
//Constraints:
//The number of nodes in the tree is in the range [0, 2000].
//-100 <= Node.val <= 100
// 
//Follow up: Can you flatten the tree in-place (with O(1) extra space)?

namespace Solution2022
{
	namespace FlattenBinaryTreetoLinkedList
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

			void helper(TreeNode* node, TreeNode*& prev) {
				if (!node) { return; }
				helper(node->right, prev);
				helper(node->left, prev);
				node->left = nullptr;
				node->right = prev;
				prev = node;
			}

			void flatten(TreeNode* root) {
				TreeNode* prev = nullptr;
				helper(root, prev);
			}
		}

		namespace Recursive {
			void flatten(TreeNode* root) {
				if (!root) { return; }
				while (root) {
					if (root->left && root->right) {
						TreeNode* l = root->left;
						while (l->right) { l = l->right; }
						l->right = root->right;
					}
					if (root->left) {
						root->right = root->left;
						root->left = nullptr;
					}
					root = root->right;
				}
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
