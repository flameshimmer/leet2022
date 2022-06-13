#include "stdafx.h"

//Given the root of a binary search tree, a target value, and an integer k,
//return the k values in the BST that are closest to the target. You may return
//the answer in any order.
//You are guaranteed to have only one unique set of k values in the BST that are
//closest to the target.
// 
//
//Example 1:
//Input: root = [4,2,5,1,3], target = 3.714286, k = 2
//Output: [4,3]
//
//Example 2:
//Input: root = [1], target = 0.000000, k = 1
//Output: [1]
// 
//Constraints:
//The number of nodes in the tree is n.
//1 <= k <= n <= 104.
//0 <= Node.val <= 109
//-109 <= target <= 109
// 
//Follow up: Assume that the BST is balanced. Could you solve it in less than
//O(n) runtime (where n = total nodes)?

namespace Solution2022
{
	namespace ClosestBinarySearchTreeValueII
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
	    vector<int> closestKValues(TreeNode* root, double target, int k) {
	        
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
