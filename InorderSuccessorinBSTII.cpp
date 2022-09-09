#include "stdafx.h"

//Given a node in a binary search tree, return the in-order successor of that
//node in the BST. If that node has no in-order successor, return null.
//The successor of a node is the node with the smallest key greater than node.val.
//You will have direct access to the node but not to the root of the tree. Each
//node will have a reference to its parent node. Below is the definition for Node:
//class Node {
//    public int val;
//    public Node left;
//    public Node right;
//    public Node parent;
//}
// 
//
//Example 1:
//Input: tree = [2,1,3], node = 1
//Output: 2
//Explanation: 1's in-order successor node is 2. 
//Note that both the node and the
//return value is of Node type.
//
//Example 2:
//Input: tree = [5,3,6,2,4,null,null,1], node = 6
//Output: null
//Explanation: There is no in-order successor of the current node, so the answer
//is null.
// 
//Constraints:
//The number of nodes in the tree is in the range [1, 104].
//-105 <= Node.val <= 105
//All Nodes will have unique values.
// 
//Follow up: Could you solve it without looking up any of the node's values?

namespace Solution2022
{
	namespace InorderSuccessorinBSTII
	{
	
		// Definition for a Node.
		class Node {
		public:
			int val;
			Node* left;
			Node* right;
			Node* parent;
		};

		Node* inorderSuccessor(Node* node) {
			if (!node) { return nullptr; }

			if (node->right) {
				node = node->right;
				while (node->left) { 
					node = node->left; 
				}
				return node;
			}

			while (node->parent && node == node->parent->right) { node = node->parent; }
			return node->parent;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
