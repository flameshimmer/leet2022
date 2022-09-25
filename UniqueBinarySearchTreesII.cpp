#include "stdafx.h"

//Given an integer n, return all the structurally unique BST's (binary search
//trees), which has exactly n nodes of unique values from 1 to n. Return the
//answer in any order.
// 
//
//Example 1:
//Input: n = 3
//Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
//
//Example 2:
//Input: n = 1
//Output: [[1]]
// 
//Constraints:
//1 <= n <= 8

namespace Solution2022
{
	namespace UniqueBinarySearchTreesII
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
		TreeNode* deepCopyTree(TreeNode* root) {
			if (!root) { return nullptr; }
			TreeNode* newRoot = new TreeNode(root->val);
			newRoot->left = deepCopyTree(root->left);
			newRoot->right = deepCopyTree(root->right);
			return newRoot;
		}

		vector<TreeNode*> helper(int start, int end) {
			if (start > end) { return { nullptr }; }

			vector<TreeNode*> result;
			for (int i = start; i <= end; i++) {
				vector<TreeNode*> left = helper(start, i - 1);
				vector<TreeNode*> right = helper(i + 1, end);
				for (TreeNode* l : left) {
					for (TreeNode* r : right) {
						TreeNode* root = new TreeNode(i);
						root->left = deepCopyTree(l);
						root->right = deepCopyTree(r);
						result.push_back(root);
					}
				}
			}
			return result;
		}

		vector<TreeNode*> generateTrees(int n) {
			return helper(1, n);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
