#include "stdafx.h"

//Serialization is the process of converting a data structure or object into a
//sequence of bits so that it can be stored in a file or memory buffer, or
//transmitted across a network connection link to be reconstructed later in the
//same or another computer environment.
//Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree
//is a rooted tree in which each node has no more than N children. There is no
//restriction on how your serialization/deserialization algorithm should work.
//You just need to ensure that an N-ary tree can be serialized to a string and
//this string can be deserialized to the original tree structure.
//For example, you may serialize the following 3-ary tree
// 
//as [1 [3[5 6] 2 4]]. 
//Note that this is just an example, you do not necessarily
//need to follow this format.
//Or you can follow LeetCode's level order traversal serialization format, where
//each group of children is separated by the null value.
// 
//[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14].
//You do not necessarily need to follow the above-suggested formats, there are
//many more different formats that work so please be creative and come up with
//different approaches yourself.
// 
//
//Example 1:
//[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
//[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
//
//Example 2:
//Input: root = [1,null,3,2,4,null,5,6]
//Output: [1,null,3,2,4,null,5,6]
//
//Example 3:
//Input: root = []
//Output: []
// 
//Constraints:
//The number of nodes in the tree is in the range [0, 104].
//0 <= Node.val <= 104
//The height of the n-ary tree is less than or equal to 1000
//Do not use class member/global/static variables to store states. Your encode
//and decode algorithms should be stateless.

namespace Solution2022
{
	namespace SerializeandDeserializeNaryTree
	{
		
		// Definition for a Node.
		class Node {
		public:
			int val;
			vector<Node*> children;

			Node() {}

			Node(int _val) {
				val = _val;
			}

			Node(int _val, vector<Node*> _children) {
				val = _val;
				children = _children;
			}
		};
		
		namespace EncodeValueAndChildCount {
			class Codec {
			public:
				void serializeHelper(Node* node, string& result) {
					if (!node) { return; }
					result += " " + to_string(node->val) + " " + to_string(node->children.size());
					for (Node* child : node->children) {
						serializeHelper(child, result);
					}
				}

				// Encodes a tree to a single string.
				string serialize(Node* root) {
					string result = "";
					serializeHelper(root, result);
					return result;
				}

				Node* deserializeHelper(istringstream& ss) {
					ss.peek();
					if (ss.eof()) { return nullptr; } // checking whehter the stream has reach to an end

					Node* newNode = new Node();
					int childCount = 0;
					ss >> newNode->val >> childCount; // istringstream directly piped into int!
					for (int i = 0; i < childCount; i++) {
						newNode->children.push_back(deserializeHelper(ss));
					}
					return newNode;
				}
				// Decodes your encoded data to tree.
				Node* deserialize(string data) {
					istringstream ss(data);
					return deserializeHelper(ss);
				}
			};
		}

		namespace encodeWithBracket {
			class Codec {
			public:
				// Encodes a tree to a single string.
				string serialize(Node* root) {					
					if (!root) { return ""; }

					string result = to_string(root->val);
					if (root->children.empty()) { return result; }

					result += "[";
					for (Node* child : root->children) {
						result += serialize(child) + " ";
					}
					result.pop_back();
					
					result += "]";
					return result;
				}

				// Decodes your encoded data to tree.
				Node* deserialize(string data) {
					if (data.empty()) { return nullptr; }

					stack<Node*> s;
					for (int i = 0; i < data.size(); i++) {
						if (isdigit(data[i])) {
							int val = 0;
							while (isdigit(data[i])) {
								val = val * 10 + data[i] - '0';
								i++;
							}
							i--;
							s.push(new Node(val, vector<Node*>()));
						}
						else if (data[i] == '[') { s.push(nullptr); }
						else if (data[i] == ']') {
							stack <Node*> tmp;
							while (s.top() != nullptr) {
								tmp.push(s.top());
								s.pop();
							}
							s.pop();
							while(!tmp.empty()) {
								s.top()->children.push_back(tmp.top());
								tmp.pop();
							}
						}
					}
					return s.top();
				}
			};
		}


		// Your Codec object will be instantiated and called as such:
		// Codec codec;
		// codec.deserialize(codec.serialize(root));

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
