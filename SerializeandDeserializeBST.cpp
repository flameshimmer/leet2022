#include "stdafx.h"

//Serialization is converting a data structure or object into a sequence of bits
//so that it can be stored in a file or memory buffer, or transmitted across a
//network connection link to be reconstructed later in the same or another
//computer environment.
//Design an algorithm to serialize and deserialize a binary search tree. There is
//no restriction on how your serialization/deserialization algorithm should work.
//You need to ensure that a binary search tree can be serialized to a string, and
//this string can be deserialized to the original tree structure.
//The encoded string should be as compact as possible.
// 
//
//Example 1:
//Input: root = [2,1,3]
//Output: [2,1,3]
//
//Example 2:
//Input: root = []
//Output: []
// 
//Constraints:
//The number of nodes in the tree is in the range [0, 104].
//0 <= Node.val <= 104
//The input tree is guaranteed to be a binary search tree.

namespace Solution2022
{
	namespace SerializeandDeserializeBST
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
			void serializeHelper(TreeNode* node, string& result) {
				if (!node) { return; }
				result += to_string(node->val) + " ";
				serializeHelper(node->left, result);
				serializeHelper(node->right, result);
			}

			TreeNode* deserializeHelper(vector<int>& data, int& pos, int minV, int maxV) {
				if (pos >= data.size()) { return nullptr; } // Note: need this check to ensure the value is not out of bound!!!
				int val = data[pos];
				if (val < minV || val > maxV) { 
					return nullptr; 
				}
				pos++;

				TreeNode* newNode = new TreeNode(val);
				newNode->left = deserializeHelper(data, pos, minV, val);
				newNode->right = deserializeHelper(data, pos, val, maxV);
				return newNode;
			}

		public:
			// Encodes a tree to a single string.
			string serialize(TreeNode* root) {
				string result;
				serializeHelper(root, result);
				return result;
			}

			// Decodes your encoded data to tree.
			TreeNode* deserialize(string data) {
				vector<int> d;
				istringstream ss(data);
				int val;
				while (ss >> val) { d.push_back(val); }

				int pos = 0;
				return deserializeHelper(d, pos, INT_MIN, INT_MAX);
			}
		};



		namespace useBinaryStream {
			class Codec {
			private:
				void serializeHelper(TreeNode* node, string& s) {
					if (!node) { return; }
					s.append(reinterpret_cast<const char*>(&node->val), sizeof(node->val));
					serializeHelper(node->left, s);
					serializeHelper(node->right, s);
				}

				TreeNode* deserializeHelper(string& s, int& pos, int minV, int maxV) {
					if (pos >= s.size()) { return nullptr; }

					int val = *reinterpret_cast<const int*>(s.data() + pos);
					if (val < minV || val > maxV) { return nullptr; }

					pos += sizeof(val);
					TreeNode* newNode = new TreeNode(val);
					newNode->left = deserializeHelper(s, pos, minV, val);
					newNode->right = deserializeHelper(s, pos, val, maxV);
					return newNode;
				}

			public:
				// Encodes a tree to a single string.
				string serialize(TreeNode* root) {
					string s;
					serializeHelper(root, s);
					return s;
				}

				// Decodes your encoded data to tree.
				TreeNode* deserialize(string data) {
					int pos = 0;
					return deserializeHelper(data, pos, INT_MIN, INT_MAX);
				}
			};

		}
		
		void Main() {
			TreeNode* root = new TreeNode(2);
			root->left = new TreeNode(1);
			root->right = new TreeNode(3);

			Codec* ser = new Codec();
			Codec* deser = new Codec();
			string tree = ser->serialize(root);
			TreeNode* ans = deser->deserialize(tree);
			
		}
	}
}
