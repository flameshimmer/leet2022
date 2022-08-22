#include "stdafx.h"

//Given an n-ary tree, return the level order traversal of its nodes' values.
//Nary-Tree input serialization is represented in their level order traversal,
//each group of children is separated by the null value (See examples).
// 
//
//Example 1:
//Input: root = [1,null,3,2,4,null,5,6]
//Output: [[1],[3,2,4],[5,6]]
//
//Example 2:
//[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
//Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
// 
//Constraints:
//The height of the n-ary tree is less than or equal to 1000
//The total number of nodes is between [0, 104]

namespace Solution2022
{
	namespace NaryTreeLevelOrderTraversal
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

		vector<vector<int>> levelOrder(Node* root) {
			vector<vector<int>> results;
			if (!root) { return results; }
			queue<Node*> q;
			q.push(root);

			while (!q.empty()) {
				int sz = q.size();
				vector<int> result;
				while (sz) {
					sz--;
					
					Node* top = q.front();
					q.pop();
					
					result.push_back(top->val);
					for (Node* child : top->children) {
						q.push(child);						
					}
				}
				if (!result.empty()) {
					results.push_back(result);
				}				
			}
			return results;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
