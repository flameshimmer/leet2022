#include "stdafx.h"

//Given the root of a binary tree, the value of a target node target, and an
//integer k, return an array of the values of all nodes that have a distance k
//from the target node.
//You can return the answer in any order.
// 
//
//Example 1:
//Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
//Output: [7,4,1]
//Explanation: The nodes that are a distance 2 from the target node (with value
//5) have values 7, 4, and 1.
//
//Example 2:
//Input: root = [1], target = 1, k = 3
//Output: []
// 
//Constraints:
//The number of nodes in the tree is in the range [1, 500].
//0 <= Node.val <= 500
//All the values Node.val are unique.
//target is the value of one of the nodes in the tree.
//0 <= k <= 1000

namespace Solution2022
{
	namespace AllNodesDistanceKinBinaryTree
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
		void findParent(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent) {
			if (node->left) {
				parent[node->left] = node;
				findParent(node->left, parent);
			}

			if (node->right) {
				parent[node->right] = node;
				findParent(node->right, parent);
			}
		}

		void helper(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent, unordered_set<TreeNode*>& visited, int k, vector<int>& result) {
			if (!node || visited.find(node) != visited.end()) { return; }
			if (k == 0) { result.push_back(node->val); return; }
			visited.insert(node);

			helper(parent[node], parent, visited, k - 1, result);
			helper(node->left, parent, visited, k - 1, result);
			helper(node->right, parent, visited, k - 1, result);
		}


		vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
			if (!root || !target) { return {}; }

			unordered_map<TreeNode*, TreeNode*> parent;
			findParent(root, parent);

			unordered_set<TreeNode*> visited;
			vector<int> result;
			helper(target, parent, visited, k, result);
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
