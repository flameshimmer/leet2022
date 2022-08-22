#include "stdafx.h"

//Given the root of an n-ary tree, return the preorder traversal of its nodes'
//values.
//Nary-Tree input serialization is represented in their level order traversal.
//Each group of children is separated by the null value (See examples)
// 
//
//Example 1:
//Input: root = [1,null,3,2,4,null,5,6]
//Output: [1,3,5,6,2,4]
//
//Example 2:
//[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
//Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
// 
//Constraints:
//The number of nodes in the tree is in the range [0, 104].
//0 <= Node.val <= 104
//The height of the n-ary tree is less than or equal to 1000.
// 
//Follow up: Recursive solution is trivial, could you do it iteratively?

namespace Solution2022
{
	namespace NaryTreePreorderTraversal
	{
		/*
		// Definition for a Node.
		class Node {
			int val;
			vector<Node*> children;
		​
			Node() {}
		​
			Node(int _val) {
				val = _val;
			}
		​
			Node(int _val, vector<Node*> _children) {
				val = _val;
				children = _children;
			}
		*/

		namespace Iterative {
			vector<int> preorder(Node* root) {
				vector<int> result;
				if (!root) { return result; }

				stack<Node*> s;
				s.push(root);

				while (!s.empty()) {
					Node* top = s.top();
					s.pop();

					result.push_back(top->val);
					reverse(top->children.begin(), top->children.end());
					for (Node* child : top->children) {
						s.push(child);
					}
				}
				return result;
			}
		}

		namespace Recursion {
			void helper(Node* root, vector<int>& result) {
				if (!root) { return; }
				result.push_back(root->val);
				for (Node* child : root->children) {
					helper(child, result);
				}				
			}

			vector<int> preorder(Node* root) {
				vector<int> result;
				helper(root, result);
				return result;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
