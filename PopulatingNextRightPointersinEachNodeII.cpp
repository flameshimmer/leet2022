#include "stdafx.h"

//Given a binary tree
//struct Node {
//  int val;
//  Node *left;
//  Node *right;
//  Node *next;
//}
//Populate each next pointer to point to its next right node. If there is no next
//right node, the next pointer should be set to NULL.
//Initially, all next pointers are set to NULL.
// 
//
//Example 1:
//Input: root = [1,2,3,4,5,null,7]
//Output: [1,#,2,3,#,4,5,7,#]
//Explanation: Given the above binary tree (Figure A), your function should
//populate each next pointer to point to its next right node, just like in Figure
//B. The serialized output is in level order as connected by the next pointers,
//with '#' signifying the end of each level.
//
//Example 2:
//Input: root = []
//Output: []
// 
//Constraints:
//The number of nodes in the tree is in the range [0, 6000].
//-100 <= Node.val <= 100
// 
//Follow-up:
//You may only use constant extra space.
//The recursive approach is fine. You may assume implicit stack space does not
//count as extra space for this problem.

namespace Solution2022
{
	namespace PopulatingNextRightPointersinEachNodeII
	{

		// Definition for a Node.
		class Node {
		public:
			int val;
			Node* left;
			Node* right;
			Node* next;

			Node() : val(0), left(NULL), right(NULL), next(NULL) {}

			Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

			Node(int _val, Node* _left, Node* _right, Node* _next)
				: val(_val), left(_left), right(_right), next(_next) {}
		};

		namespace Recursive {
			Node* connectRecursive(Node* root) {
				if (!root) { return nullptr; }
				Node* result = root;
				Node* child = nullptr;
				if (root->left) { root->left->next = root->right; child = root->left; }
				if (root->right) { child = root->right; }

				if (child) {
					Node* cur = root->next;
					while (cur) {
						if (cur->left) { child->next = cur->left; break; }
						if (cur->right) { child->next = cur->right; break; }
						cur = cur->next;
					}
				}
				connectRecursive(root->right); // right first!
				connectRecursive(root->left);
				return result;
			}
		}

		namespace Iterative {
			Node* connect(Node* root) {
				Node* result = root;
				Node* cur = root;
				while (cur) {
					Node* prev = nullptr; // prev from the same level
					Node* next = nullptr; // next fromt the next level

					while (cur) {
						if (cur->left) {
							if (!prev) { prev = cur->left; }
							else { prev->next = cur->left; prev = prev->next; }
							if (!next) { next = cur->left; }
						}

						if (cur->right) {
							if (!prev) { prev = cur->right; }
							else { prev->next = cur->right; prev = prev->next; }
							if (!next) { next = cur->right; }
						}
						cur = cur->next;
					}
					cur = next;
				}
				return result;
			}
		}

		namespace BFS {
			Node* connect(Node* root) {
				if (!root) { return root; }

				queue<Node*> q;
				q.push(root);

				while (!q.empty()) {
					int sz = q.size();
					Node* cur = nullptr;
					while (sz) {
						sz--;
						cur = q.front();
						q.pop();
						cur->next = q.front();
						if (cur->left) { q.push(cur->left); }
						if (cur->right) { q.push(cur->right); }
					}
					cur->next = nullptr;
				}
				return root;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
