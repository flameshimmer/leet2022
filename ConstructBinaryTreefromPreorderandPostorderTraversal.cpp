#include "stdafx.h"

//Given two integer arrays, preorder and postorder where preorder is the preorder
//traversal of a binary tree of distinct values and postorder is the postorder
//traversal of the same tree, reconstruct and return the binary tree.
//If there exist multiple answers, you can return any of them.
// 
//
//Example 1:
//Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
//Output: [1,2,3,4,5,6,7]
//
//Example 2:
//Input: preorder = [1], postorder = [1]
//Output: [1]
// 
//Constraints:
//1 <= preorder.length <= 30
//1 <= preorder[i] <= preorder.length
//All the values of preorder are unique.
//postorder.length == preorder.length
//1 <= postorder[i] <= postorder.length
//All the values of postorder are unique.
//It is guaranteed that preorder and postorder are the preorder traversal and
//postorder traversal of the same binary tree.

namespace Solution2022
{
	namespace ConstructBinaryTreefromPreorderandPostorderTraversal
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

		TreeNode* helper(vector<int>& pre, int preStart, int preEnd, vector<int>& post, int postStart, int postEnd, unordered_map<int, int>& map) {
			if (preStart > preEnd) { return nullptr; }

			TreeNode* root = new TreeNode(pre[preStart]);
			if (preStart == preEnd) { return root; }

			int index = map[pre[preStart + 1]];
			int offset = index - postStart;
			root->left = helper(pre, preStart + 1, preStart + 1 + offset, post, postStart, index, map);
			root->right = helper(pre, preStart + 1 + offset + 1, preEnd, post, index + 1, postEnd, map);
			return root;
		}

		TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
			int len = pre.size();
			unordered_map<int, int> map;
			for (int i = 0; i < len; i++) {
				map[post[i]] = i;
			}
			return helper(pre, 0, len - 1, post, 0, len - 1, map);
		}


		namespace Another {
			TreeNode* helper(vector<int>& pre, int& preIndex, vector<int>& post, int& postIndex) {
				TreeNode* root = new TreeNode(pre[preIndex]);
				preIndex++;
				if (root->val != post[postIndex]) {
					root->left = helper(pre, preIndex, post, postIndex);
				}
				if (root->val != post[postIndex]) {
					root->right = helper(pre, preIndex, post, postIndex);
				}
				postIndex++;
				return root;
			}

			TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
				int preIndex = 0;
				int postIndex = 0;
				return helper(pre, preIndex, post, postIndex);
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
