#include "stdafx.h"

//Given two integer arrays inorder and postorder where inorder is the inorder
//traversal of a binary tree and postorder is the postorder traversal of the same
//tree, construct and return the binary tree.
// 
//
//Example 1:
//Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
//Output: [3,9,20,null,null,15,7]
//
//Example 2:
//Input: inorder = [-1], postorder = [-1]
//Output: [-1]
// 
//Constraints:
//1 <= inorder.length <= 3000
//postorder.length == inorder.length
//-3000 <= inorder[i], postorder[i] <= 3000
//inorder and postorder consist of unique values.
//Each value of postorder also appears in inorder.
//inorder is guaranteed to be the inorder traversal of the tree.
//postorder is guaranteed to be the postorder traversal of the tree.

namespace Solution2022
{
	namespace ConstructBinaryTreefromInorderandPostorderTraversal
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
		TreeNode* helper(vector<int>& postorder, int& rootIndex, vector<int>& inorder, int start, int end, unordered_map<int, int>& map) {
			if (rootIndex >= postorder.size() || start > end) { return nullptr; }

			int rootVal = postorder[rootIndex];
			TreeNode* newNode = new TreeNode(rootVal);
			rootIndex--;

			int i = map[rootVal];
			newNode->right = helper(postorder, rootIndex, inorder, i + 1, end, map);
			newNode->left = helper(postorder, rootIndex, inorder, start, i - 1, map);
			return newNode;
		}

		TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
			int len = inorder.size();
			if (len == 0) { return nullptr; }

			unordered_map<int, int> map;
			for (int i = 0; i < len; i++) { map[inorder[i]] = i; }

			int rootIndex = len - 1;
			return helper(postorder, rootIndex, inorder, 0, len - 1, map);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
