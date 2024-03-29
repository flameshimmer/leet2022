#include "stdafx.h"

//You are asked to design a file system that allows you to create new paths and
//associate them with different values.
//The format of a path is one or more concatenated strings of the form: /
//followed by one or more lowercase English letters. For example, "/leetcode" and
//"/leetcode/problems" are valid paths while an empty string "" and "/" are not.
//Implement the FileSystem class:
//bool createPath(string path, int value) Creates a new path and associates a
//value to it if possible and returns true. Returns false if the path already
//exists or its parent path doesn't exist.
//int get(string path) Returns the value associated with path or returns -1 if
//the path doesn't exist.
// 
//
//Example 1:
//Input: 
//["FileSystem","createPath","get"]
//[[],["/a",1],["/a"]]
//Output: 
//[null,true,1]
//Explanation: 
//FileSystem fileSystem = new FileSystem();
//fileSystem.createPath("/a", 1); // return true
//fileSystem.get("/a"); // return 1
//
//Example 2:
//Input: 
//["FileSystem","createPath","createPath","get","createPath","get"]
//[[],["/leet",1],["/leet/code",2],["/leet/code"],["/c/d",1],["/c"]]
//Output: 
//[null,true,true,2,false,-1]
//Explanation: 
//FileSystem fileSystem = new FileSystem();
//fileSystem.createPath("/leet", 1); // return true
//fileSystem.createPath("/leet/code", 2); // return true
//fileSystem.get("/leet/code"); // return 2
//fileSystem.createPath("/c/d", 1); // return false because the parent path "/c"
//doesn't exist.
//fileSystem.get("/c"); // return -1 because this path doesn't exist.
// 
//Constraints:
//The number of calls to the two functions is less than or equal to 104 in total.
//2 <= path.length <= 100
//1 <= value <= 109

namespace Solution2022
{
	namespace DesignFileSystem
	{
		class FileSystem {
		private:
			class Node {
			public: 
				int val;
				unordered_map<string, Node*> children;
				Node(int v) : val(v) {};
			};

			Node* root;

			vector<string> getPathStrings(string& s) {
				istringstream ss(s);
				string cur;
				vector<string> result;
				while (getline(ss, cur, '/')) {
					if (!cur.empty()) {
						result.push_back(cur);
					}
				}
				return result;
			}

		public:
			FileSystem() {
				root = new Node(0);
			}

			bool createPath(string path, int value) {
				vector<string> paths = getPathStrings(path);
				Node* cur = root;
				for (int i = 0; i < paths.size() - 1; i++) {
					string& p = paths[i];
					if (cur->children.find(p) == cur->children.end()) { return false; }
					cur = cur->children[p]; // Don't forget to move forward!!!
				}
				if (cur->children.find(paths.back()) != cur->children.end()) { return false; }
				cur->children[paths.back()] = new Node(value);
				return true;
			}

			int get(string path) {
				vector<string> paths = getPathStrings(path);
				Node* cur = root;
				for (string& p : paths) {
					if (cur->children.find(p) == cur->children.end()) { return -1; }
					cur = cur->children[p];
				}
				return cur->val;
			}
		};


		void Main() {
			FileSystem* obj = new FileSystem();
			print(obj->createPath("/leet", 1));
			print(obj->createPath("/leet/code", 2));
			print(obj->get("/leet/code"));
			print(obj->createPath("/c/d", 1));
			print(obj->get("/c"));
		}
	}
}
