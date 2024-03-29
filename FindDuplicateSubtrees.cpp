#include "stdafx.h"

//Given the root of a binary tree, return all duplicate subtrees.
//For each kind of duplicate subtrees, you only need to return the root node of
//any one of them.
//Two trees are duplicate if they have the same structure with the same node
//values.
// 
//
//Example 1:
//Input: root = [1,2,3,4,null,2,4,null,null,4]
//Output: [[2,4],[4]]
//
//Example 2:
//Input: root = [2,1,1]
//Output: [[1]]
//
//Example 3:
//Input: root = [2,2,2,3,null,3,null]
//Output: [[2,3],[3]]
// 
//Constraints:
//The number of the nodes in the tree will be in the range [1, 10^4]
//-200 <= Node.val <= 200

namespace Solution2022
{
	namespace FindDuplicateSubtrees
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

		string helper(TreeNode* root, unordered_map<string, int>& map, vector<TreeNode*>& result) {
			if (!root) { return ""; }
			string s = to_string(root->val) + "[" + helper(root->left, map, result) + " " + helper(root->right, map, result) + "]";
			map[s] ++;
			if (map[s] == 2) { result.push_back(root); }
			return s;
		}

		vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
			unordered_map<string, int> map;
			vector<TreeNode*> result;
			helper(root, map, result);
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
