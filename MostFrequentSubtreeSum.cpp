#include "stdafx.h"

//Given the root of a binary tree, return the most frequent subtree sum. If there
//is a tie, return all the values with the highest frequency in any order.
//The subtree sum of a node is defined as the sum of all the node values formed
//by the subtree rooted at that node (including the node itself).
// 
//
//Example 1:
//Input: root = [5,2,-3]
//Output: [2,-3,4]
//
//Example 2:
//Input: root = [5,2,-5]
//Output: [2]
// 
//Constraints:
//The number of nodes in the tree is in the range [1, 104].
//-105 <= Node.val <= 105

namespace Solution2022
{
	namespace MostFrequentSubtreeSum
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

		int helper(TreeNode* root, int& maxFreq, unordered_map<int, int>& map) {
			if (!root) { return 0; }
			int sum = root->val + helper(root->left, maxFreq, map) + helper(root->right, maxFreq, map);
			map[sum]++;
			maxFreq = max(maxFreq, map[sum]);
			return sum;
		}

		vector<int> findFrequentTreeSum(TreeNode* root) {
			unordered_map<int, int> map;
			int maxFreq = 0;

			helper(root, maxFreq, map);
			vector<int> result;
			for (auto [sum, freq] : map) {
				if (freq == maxFreq) { result.push_back(sum); }
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
