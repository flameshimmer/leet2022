#include "stdafx.h"

//Given a n-ary tree, find its maximum depth.
//The maximum depth is the number of nodes along the longest path from the root
//node down to the farthest leaf node.
//Nary-Tree input serialization is represented in their level order traversal,
//each group of children is separated by the null value (See examples).
// 
//
//Example 1:
//Input: root = [1,null,3,2,4,null,5,6]
//Output: 3
//
//Example 2:
//[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
//Output: 5
// 
//Constraints:
//The total number of nodes is in the range [0, 104].
//The depth of the n-ary tree is less than or equal to 1000.

namespace Solution2022
{
	namespace MaximumDepthofNaryTree
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

		int maxDepth(Node* root) {
			if (!root) { return 0; }

			int maxD = 0;
			for (Node* n : root->children) {
				maxD = max(maxD, maxDepth(n));
			}
			return maxD + 1;
		}

		namespace BFS {
			int maxDepth(Node* root) {
				if (!root) { return 0; }
				queue<Node*> q;
				q.push(root);

				int result = 0;
				while (!q.empty()) {
					int sz = q.size();
					while (sz) {
						sz--;
						Node* n = q.front();
						q.pop();
						for (Node* child : n->children) {
							q.push(child);
						}
					}
					result++;
				}
				return result;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
