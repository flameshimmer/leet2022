#include "stdafx.h"

//Given an integer n, return a list of all possible full binary trees with n
//nodes. Each node of each tree in the answer must have Node.val == 0.
//Each element of the answer is the root node of one possible tree. You may
//return the final list of trees in any order.
//A full binary tree is a binary tree where each node has exactly 0 or 2 children.
// 
//
//Example 1:
//Input: n = 7
//[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
//
//Example 2:
//Input: n = 3
//Output: [[0,0,0]]
// 
//Constraints:
//1 <= n <= 20

namespace Solution2022
{
	namespace AllPossibleFullBinaryTrees
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
		TreeNode* clone(TreeNode* node) {
			TreeNode* newNode = new TreeNode(0);
			newNode->left = node->left ? clone(node->left) : nullptr;
			newNode->right = node->right ? clone(node->right) : nullptr;
			return newNode;
		}

		vector<TreeNode*> helper(int n, unordered_map<int, vector<TreeNode*>>& map) {
			vector<TreeNode*> result;

			if (n < 1 || n % 2 == 0) {return result;}
			if (map.find(n) != map.end()) { return map[n]; }
			if (n == 1) {
				result.push_back(new TreeNode(0));
				map[1] = result;
				return result;
			}

			for (int i = 1; i < n; i += 2) {
				vector<TreeNode*> l = helper(i, map);
				vector<TreeNode*> r = helper(n-1-i, map);

				for (int j = 0; j < l.size(); j++) {
					for (int k = 0; k < r.size(); k++) {
						TreeNode* node = new TreeNode(0);
						node->left = clone(l[j]);
						node->right = clone(r[k]);
						result.push_back(node);
					}
				}
			}
			map[n] = result;
			return result;
		}

	    vector<TreeNode*> allPossibleFBT(int n) {
			unordered_map<int, vector<TreeNode*>> map;
			return helper(n, map);
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
