#include "stdafx.h"

//Two strings X and Y are similar if we can swap two letters (in different
//positions) of X, so that it equals Y. Also two strings X and Y are similar if
//they are equal.
//For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and
//"rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or
//"arts".
//Together, these form two connected groups by similarity: {"tars", "rats",
//"arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even
//though they are not similar.  Formally, each group is such that a word is in
//the group if and only if it is similar to at least one other word in the group.
//We are given a list strs of strings where every string in strs is an anagram of
//every other string in strs. How many groups are there?
// 
//
//Example 1:
//Input: strs = ["tars","rats","arts","star"]
//Output: 2
//
//Example 2:
//Input: strs = ["omv","ovm"]
//Output: 1
// 
//Constraints:
//1 <= strs.length <= 300
//1 <= strs[i].length <= 300
//strs[i] consists of lowercase letters only.
//All words in strs have the same length and are anagrams of each other.

namespace Solution2022
{
	namespace SimilarStringGroups
	{
		class UnionFindSet {
		private:
			vector<int> parent;
			int size;
		public:
			UnionFindSet(int n) {
				parent.resize(n);
				iota(parent.begin(), parent.end(), 0);
				size = n;
			}


			int find(int i) {
				while (parent[i] != i) {
					i = parent[i];
				}
				return i;
			}

			void join(int i, int j) {
				int pi = find(i);
				int pj = find(j);
				if (pi != pj) { 
					parent[pi] = pj; // Note! This is parent[pi] = pj; Not parent[i] = pj!!! 
					size--;
				}
			}

			int getSize() { return size; }
		};

		bool similar(string& a, string& b) {
			int diff = 0;
			for (int i = 0; i < a.size(); i++) {
				if (a[i] != b[i]) {
					diff++;
					if (diff > 2) { return false; }
				}
			}
			return true;
		}

	    int numSimilarGroups(vector<string>& strs) {
			int len = strs.size();
			UnionFindSet uf(len);

			for (int i = 0; i < len; i++) {
				for (int j = i + 1; j < len; j++) {
					if (similar(strs[i], strs[j])) { uf.join(i, j); }
				}
			}
			return uf.getSize();
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
