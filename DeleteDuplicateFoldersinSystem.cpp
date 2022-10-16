#include "stdafx.h"

//Due to a bug, there are many duplicate folders in a file system. You are given
//a 2D array paths, where paths[i] is an array representing an absolute path to
//the ith folder in the file system.
//For example, ["one", "two", "three"] represents the path "/one/two/three".
//Two folders (not necessarily on the same level) are identical if they contain
//the same non-empty set of identical subfolders and underlying subfolder
//structure. The folders do not need to be at the root level to be identical. If
//two or more folders are identical, then mark the folders as well as all their
//subfolders.
//For example, folders "/a" and "/b" in the file structure below are identical.
//They (as well as their subfolders) should all be marked:
///a
///a/x
///a/x/y
///a/z
///b
///b/x
///b/x/y
///b/z
//However, if the file structure also included the path "/b/w", then the folders
//"/a" and "/b" would not be identical. 
//Note that "/a/x" and "/b/x" would still
//be considered identical even with the added folder.
//Once all the identical folders and their subfolders have been marked, the file
//system will delete all of them. The file system only runs the deletion once, so
//any folders that become identical after the initial deletion are not deleted.
//Return the 2D array ans containing the paths of the remaining folders after
//deleting all the marked folders. The paths may be returned in any order.
// 
//
//Example 1:
//Input: paths = [["a"],["c"],["d"],["a","b"],["c","b"],["d","a"]]
//Output: [["d"],["d","a"]]
//Explanation: The file structure is as shown.
//Folders "/a" and "/c" (and their subfolders) are marked for deletion because
//they both contain an empty
//folder named "b".
//
//Example 2:
//[["a"],["c"],["a","b"],["c","b"],["a","b","x"],["a","b","x","y"],["w"],["w","y"]]
//Output: [["c"],["c","b"],["a"],["a","b"]]
//Explanation: The file structure is as shown. 
//Folders "/a/b/x" and "/w" (and their subfolders) are marked for deletion
//because they both contain an empty folder named "y".
//
//Note that folders "/a" and "/c" are identical after the deletion, but they are
//not deleted because they were not marked beforehand.
//
//Example 3:
//Input: paths = [["a","b"],["c","d"],["c"],["a"]]
//Output: [["c"],["c","d"],["a"],["a","b"]]
//Explanation: All folders are unique in the file system.
//
//Note that the returned array can be in a different order as the order does not
//matter.
// 
//Constraints:
//1 <= paths.length <= 2 * 104
//1 <= paths[i].length <= 500
//1 <= paths[i][j].length <= 10
//1 <= sum(paths[i][j].length) <= 2 * 105
//path[i][j] consists of lowercase English letters.
//No two paths lead to the same folder.
//For any folder not at the root level, its parent folder will also be in the
//input.

namespace Solution2022
{

	//Build Tree: Build a folder tree based on the paths. The process is similar to
	//the Trie building process.

	//Dedupe: Use post-order traversal to visit all the nodes. If we've seen the
	//subfolder structure before, mark the node as deleted.

	//Generate Paths: DFS to generate the output. We skip the nodes that have been
	//deleted.

	//Update 1: To ensure we visit the subfolders in the same order, changed
	//Node::next to unordered_map to map. 
	//(Testcase:  [["a"],["a","a"],["a","b"],["a","b","a"],["b"],["b","a"],["b","a","a"],["b","b"]])

	//Update 2: To ensure the subfolder structure string only map to a unique tree
	//structure, changed the encoding to use parenthesis instead, e.g. 
	//(root(firstChild)(secondChild)...). (Testcase: [["r","x"],["r","x",
	//"b"],["r","x","b","a"],["r", "y"],["r","y", "a"],["r","y", "b"],["r"]].)

	//Complexity Analysis
	//Assume N is the number of folders, W is the maximum length of folder name, D is
	//the deepest folder depth, and C is the maximum number of direct child folders.
	//Build Tree: We need to add all the N folders, each of which takes O(DWlogC)
	//time. So overall it takes O(NDWlogC) time, and O(NW) space.
	//Dedupe: We traverse the N folders in post-order. The maximum length of
	//subfolder structure string is roughly O(NW), so each node visit need O(NW) time
	//to check if it's a duplicate. The overall time complexity is O(N^2 * W) and the
	//space complexity is O(N^2 * W).
	//Generate Paths: In the worst case we traverse the N nodes again. Each visit
	//takes O(W) time to update the current path and O(DW) time to update the answer.
	//So overall the time complexity is O(NDW) and space complexity is O(DW) for the

	//temporary path.
	namespace DeleteDuplicateFoldersinSystem
	{
		struct Node {
			string name;
			map<string, Node*> children;
			bool del = false;
			Node(string n = "") : name(n) {}

		};

		void addPath(Node* node, vector<string>& path) {
			for (string& n : path) {
				if (node->children.count(n) == 0) { node->children[n] = new Node(n); }
				node = node->children[n];
			}
		}


		string dedup(Node* node, unordered_map<string, Node*>& seen) {
			string result;
			for (auto& [name, child] : node->children) {
				result += dedup(child, seen);
			}
			if (!result.empty()) {
				if (seen.find(result) != seen.end()) {
					node->del = true;
					seen[result]->del = true;
				}
				else {
					seen[result] = node;
				}
			}
			return "(" + node->name + result + ")";
		}

		void getPath(Node* node, vector<string>& result, vector<vector<string>>& results) {
			if (node->del) { return; }
			result.push_back(node->name);
			results.push_back(result);
			for (auto& [name, child] : node->children) {
				getPath(child, result, results);
			}
			result.pop_back();
		}

		vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
			Node root;
			for (vector<string>& p : paths) {
				addPath(&root, p);
			}

			unordered_map<string, Node*> seen;
			dedup(&root, seen);

			vector<string> result;
			vector<vector<string>> results;
			for (auto& [name, child] : root.children) {
				getPath(child, result, results);
			}
			return results;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
