#include "stdafx.h"

//Given the root of a binary search tree, and an integer k, return the kth
//smallest value (1-indexed) of all the values of the nodes in the tree.
// 
//
//Example 1:
//Input: root = [3,1,4,null,2], k = 1
//Output: 1
//
//Example 2:
//Input: root = [5,3,6,2,4,null,null,1], k = 3
//Output: 3
// 
//Constraints:
//The number of nodes in the tree is n.
//1 <= k <= n <= 104
//0 <= Node.val <= 104
// 
//Follow up: If the BST is modified often (i.e., we can do insert and delete
//operations) and you need to find the kth smallest frequently, how would you
//optimize?

namespace Solution2022
{
	namespace KthSmallestElementinaBST
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
		namespace Recursive {
			bool helper(TreeNode* node, int& k, int& result) {
				if (!node) { return false; }

				if (helper(node->left, k, result)) { return true; }
				k--;
				if (k == 0) { result = node->val; return true; }
				return helper(node->right, k, result);
			}


			int kthSmallest(TreeNode* root, int k) {
				int result = 0;
				helper(root, k, result);
				return result;
			}
		}

		namespace Iterative {
			
			int kthSmallest(TreeNode* root, int k) {
				if (!root) { return 0; }

				stack<TreeNode*> s;
				int count = 0;
				TreeNode* cur = root;

				while (cur || !s.empty()) {
					if (cur) {
						s.push(cur);
						cur = cur->left;
					}
					else {
						TreeNode* top = s.top();
						s.pop();
						count++;
						if (count == k) { return top->val; }
						if (top->right) { cur = top->right; }
					}				
				}
				return 0;
			}		
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
