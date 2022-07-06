#include "stdafx.h"

//Given the root node of a binary search tree and two integers low and high,
//return the sum of values of all nodes with a value in the inclusive range [low,
//high].
// 
//
//Example 1:
//Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
//Output: 32
//Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
//
//Example 2:
//Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
//Output: 23
//Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
// 
//Constraints:
//The number of nodes in the tree is in the range [1, 2 * 104].
//1 <= Node.val <= 105
//1 <= low <= high <= 105
//All Node.val are unique.

namespace Solution2022
{
	namespace RangeSumofBST
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
			int rangeSumBST(TreeNode* root, int low, int high) {
				if (!root) { return 0; }
				int result = 0;
				if (root->val >= low && root->val <= high) { result += root->val; }
				if (root->val > low) { result += rangeSumBST(root->left, low, high); }
				if (root->val < high) { result += rangeSumBST(root->right, low, high); }
				return result;
			}

		}
		namespace Iterative {
			int rangeSumBST(TreeNode* root, int low, int high) {
				if (!root) { return 0; }
				
				stack<TreeNode*> s;
				s.push(root);
				int result = 0;
				
				while (!s.empty()) {
					TreeNode* top = s.top();
					s.pop();
					if (top->val >= low && top->val <= high) { result += top->val; }
					if (top->val > low && top->left) { s.push(top->left); }
					if (top->val < high && top->right) { s.push(top->right); }				
				}
				return result;
			}

		}
	
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
