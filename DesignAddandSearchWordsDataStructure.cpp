#include "stdafx.h"

//Design a data structure that supports adding new words and finding if a string
//matches any previously added string.
//Implement the WordDictionary class:
//WordDictionary() Initializes the object.
//void addWord(word) Adds word to the data structure, it can be matched later.
//bool search(word) Returns true if there is any string in the data structure
//that matches word or false otherwise. word may contain dots '.' where dots can
//be matched with any letter.
// 
//
//Example:
//Input
//["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
//[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
//Output
//[null,null,null,null,false,true,true,true]
//Explanation
//WordDictionary wordDictionary = new WordDictionary();
//wordDictionary.addWord("bad");
//wordDictionary.addWord("dad");
//wordDictionary.addWord("mad");
//wordDictionary.search("pad"); // return False
//wordDictionary.search("bad"); // return True
//wordDictionary.search(".ad"); // return True
//wordDictionary.search("b.."); // return True
// 
//Constraints:
//1 <= word.length <= 25
//word in addWord consists of lowercase English letters.
//word in search consist of '.' or lowercase English letters.
//There will be at most 3 dots in word for search queries.
//At most 104 calls will be made to addWord and search.

namespace Solution2022
{
	namespace DesignAddandSearchWordsDataStructure
	{
		class WordDictionary {
		private:
			class Node {
			public:
				vector<Node*> children;
				bool isEnd;
				Node() {
					isEnd = false;
					children.resize(26, nullptr);
				}
			};

			Node* root;

		public:
			WordDictionary() {
				root = new Node();
			}

			void addWord(string word) {
				Node* cur = root;
				for (char c : word) {
					if (!cur->children[c - 'a']) {
						cur->children[c - 'a'] = new Node();
					}
					cur = cur->children[c - 'a'];
				}
				cur->isEnd = true;
			}

			bool helper(string& s, int start, Node* node) {
				if (start == s.size()) { return node->isEnd; }
				if (s[start] != '.') {
					return node->children[s[start] - 'a'] && helper(s, start + 1, node->children[s[start] - 'a']);
				}
				else {
					for (int i = 0; i < 26; i++) {
						if (node->children[i]) {
							if (helper(s, start + 1, node->children[i])) { return true; }
						}
					}
				}
				return false;
			}

			bool search(string word) {
				return helper(word, 0, root);
			}
		};

		/**
		 * Your WordDictionary object will be instantiated and called as such:
		 * WordDictionary* obj = new WordDictionary();
		 * obj->addWord(word);
		 * bool param_2 = obj->search(word);
		 */

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
