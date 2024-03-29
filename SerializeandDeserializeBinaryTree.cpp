#include "stdafx.h"

//Serialization is the process of converting a data structure or object into a
//sequence of bits so that it can be stored in a file or memory buffer, or
//transmitted across a network connection link to be reconstructed later in the
//same or another computer environment.
//Design an algorithm to serialize and deserialize a binary tree. There is no
//restriction on how your serialization/deserialization algorithm should work.
//You just need to ensure that a binary tree can be serialized to a string and
//this string can be deserialized to the original tree structure.
//Clarification: The input/output format is the same as how LeetCode serializes a
//binary tree. You do not necessarily need to follow this format, so please be
//creative and come up with different approaches yourself.
// 
//
//Example 1:
//Input: root = [1,2,3,null,null,4,5]
//Output: [1,2,3,null,null,4,5]
//
//Example 2:
//Input: root = []
//Output: []
// 
//Constraints:
//The number of nodes in the tree is in the range [0, 104].
//-1000 <= Node.val <= 1000

namespace Solution2022
{
	namespace SerializeandDeserializeBinaryTree
	{
		//Definition for a binary tree node.
		struct TreeNode {
			int val;
			TreeNode* left;
			TreeNode* right;
			TreeNode(int x) : val(x), left(NULL), right(NULL) {}
		};

		class Codec {
		private:
			void serializeHelper(TreeNode* node, ostringstream& out) {
				if (!node) {
					out << "# ";
					return;
				}
				out << node->val << " ";
				serializeHelper(node->left, out);
				serializeHelper(node->right, out);
			}

			TreeNode* deserializeHelper(istringstream& in) {
				string val;
				in >> val;
				if (val == "#") { return nullptr; }

				TreeNode* newNode = new TreeNode(stoi(val));
				newNode->left = deserializeHelper(in);
				newNode->right = deserializeHelper(in);
				return newNode;
			}

		public:
			// Encodes a tree to a single string.
			string serialize(TreeNode* root) {
				ostringstream out;
				serializeHelper(root, out);
				return out.str();
			}

			// Decodes your encoded data to tree.
			TreeNode* deserialize(string data) {
				istringstream in(data);
				return deserializeHelper(in);
			}
		};


		// Your Codec object will be instantiated and called as such:
		// Codec ser, deser;
		// TreeNode* ans = deser.deserialize(ser.serialize(root));

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
