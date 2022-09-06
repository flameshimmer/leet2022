#include "stdafx.h"

//Given two integer arrays preorder and inorder where preorder is the preorder
//traversal of a binary tree and inorder is the inorder traversal of the same
//tree, construct and return the binary tree.
// 
//
//Example 1:
//Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//Output: [3,9,20,null,null,15,7]
//
//Example 2:
//Input: preorder = [-1], inorder = [-1]
//Output: [-1]
// 
//Constraints:
//1 <= preorder.length <= 3000
//inorder.length == preorder.length
//-3000 <= preorder[i], inorder[i] <= 3000
//preorder and inorder consist of unique values.
//Each value of inorder also appears in preorder.
//preorder is guaranteed to be the preorder traversal of the tree.
//inorder is guaranteed to be the inorder traversal of the tree.

namespace Solution2022
{
	namespace ConstructBinaryTreefromPreorderandInorderTraversal
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
		TreeNode* helper(vector<int>& preorder, int& rootIndex, vector<int>& inorder, int start, int end, unordered_map<int, int>& map) {
			if (start > end || rootIndex >= preorder.size()) { return nullptr; }

			int rootVal = preorder[rootIndex];
			TreeNode* newNode = new TreeNode(rootVal);
			rootIndex++;

			int i = map[rootVal];
			newNode->left = helper(preorder, rootIndex, inorder, start, i - 1, map);
			newNode->right = helper(preorder, rootIndex, inorder, i + 1, end, map);
			return newNode;
		}

		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			int len = preorder.size();
			if (len == 0) { return nullptr; }

			unordered_map<int, int> map;
			for (int i = 0; i < len; i++) {
				map[inorder[i]] = i;
			}


			int rootIndex = 0;
			return helper(preorder, rootIndex, inorder, 0, len, map);
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
