#include "stdafx.h"

//Given the root of a binary tree, check whether it is a mirror of itself (i.e.,
//symmetric around its center).
// 
//
//Example 1:
//Input: root = [1,2,2,3,4,4,3]
//Output: true
//
//Example 2:
//Input: root = [1,2,2,null,3,null,3]
//Output: false
// 
//Constraints:
//The number of nodes in the tree is in the range [1, 1000].
//-100 <= Node.val <= 100
// 
//Follow up: Could you solve it both recursively and iteratively?

namespace Solution2022
{
	namespace SymmetricTree
	{

		//Definition for a binary tree node.
		struct TreeNode {
			int val;
			TreeNode* left;
			TreeNode* right;
			TreeNode() : val(0), left(nullptr), right(nullptr) {}
			TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
			TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
		};

		namespace Recursive {
			bool helper(TreeNode* l, TreeNode* r) {
				if (!l && !r) { return true; }
				if (!l || !r) { return false; }
				if (l->val != r->val) { return false; }
				return helper(l->right, r->left) && helper(l->left, r->right);
			}

			bool isSymmetric(TreeNode* root) {
				if (!root) { return true; }
				return helper(root->left, root->right);
			}
		}


		namespace Iterative {
			bool isSymmetric(TreeNode* root) {
				if (!root) { return true; }
				queue<TreeNode*> q;
				q.push(root);
				q.push(root);
				while (!q.empty()) {
					TreeNode* n1 = q.front();
					q.pop();
					TreeNode* n2 = q.front();
					q.pop();
					if (!n1 && !n2) { continue; }
					if (!n1 || !n2 || n1->val != n2->val) { return false; }
					q.push(n1->left);
					q.push(n2->right);
					q.push(n1->right);
					q.push(n2->left);
				}
				return true;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
