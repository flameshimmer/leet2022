#include "stdafx.h"

//You are given a nested list of integers nestedList. Each element is either an
//integer or a list whose elements may also be integers or other lists.
//The depth of an integer is the number of lists that it is inside of. For
//example, the nested list [1,[2,2],[[3],2],1] has each integer's value set to
//its depth. Let maxDepth be the maximum depth of any integer.
//The weight of an integer is maxDepth - (the depth of the integer) + 1.
//Return the sum of each integer in nestedList multiplied by its weight.
// 
//
//Example 1:
//Input: nestedList = [[1,1],2,[1,1]]
//Output: 8
//Explanation: Four 1's with a weight of 1, one 2 with a weight of 2.
//1*1 + 1*1 + 2*2 + 1*1 + 1*1 = 8
//
//Example 2:
//Input: nestedList = [1,[4,[6]]]
//Output: 17
//Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1.
//1*3 + 4*2 + 6*1 = 17
// 
//Constraints:
//1 <= nestedList.length <= 50
//The values of the integers in the nested list is in the range [-100, 100].
//The maximum depth of any integer is less than or equal to 50.

namespace Solution2022
{
	namespace NestedListWeightSumII
	{

		// This is the interface that allows for creating nested lists.
		// You should not implement it, or speculate about its implementation
		class NestedInteger {
		public:
			// Constructor initializes an empty nested list.
			NestedInteger();

			// Constructor initializes a single integer.
			NestedInteger(int value) {}

			// Return true if this NestedInteger holds a single integer, rather than a nested list.
			bool isInteger() const { return false; }

			// Return the single integer that this NestedInteger holds, if it holds a single integer
			// The result is undefined if this NestedInteger holds a nested list
			int getInteger() const { return 0; }

			// Set this NestedInteger to hold a single integer.
			void setInteger(int value) { return; }

			// Set this NestedInteger to hold a nested list and adds a nested integer to it.
			void add(const NestedInteger& ni) { return; }

			// Return the nested list that this NestedInteger holds, if it holds a nested list
			// The result is undefined if this NestedInteger holds a single integer
			const vector<NestedInteger>& getList() const { return {}; }
		};

		namespace BFS {
			int depthSumInverse(vector<NestedInteger>& nestedList) {
				int len = nestedList.size();
				if (len == 0) { return 0; }

				vector<vector<int>> results;
				queue<NestedInteger> q;
				for (auto& nl : nestedList) { q.push(nl); }

				while (!q.empty()) {
					int sz = q.size();
					vector<int> level;
					while (sz) {
						sz--;
						
						NestedInteger top = q.front();
						q.pop();

						if (top.isInteger()) { level.push_back(top.getInteger()); }
						else {
							for (auto& nl : top.getList()) {
								q.push(nl);
							}						
						}
					}
					results.push_back(level);
				}

				int maxDepth = results.size();
				int result = 0;
				for (int i = 0; i < results.size(); i++) {
					result += (maxDepth - (i + 1) + 1) * accumulate(results[i].begin(), results[i].end(), 0);
				}
				return result;
			}
		}

		namespace TwoPass {
			void findMaxDepth(const vector<NestedInteger>& nestedList, int curDepth, int& maxDepth) {
				for (const NestedInteger& nl : nestedList) {
					if (nl.isInteger()) {
						maxDepth = max(maxDepth, curDepth);
					}
					else {
						findMaxDepth(nl.getList(), curDepth + 1, maxDepth);
					}
				}
			}

			void helper(const vector<NestedInteger>& nestedList, int curDepth, int maxDepth, int& result) {
				for (const auto& nl : nestedList) {
					if (nl.isInteger()) { result += nl.getInteger() * ((maxDepth - curDepth) + 1); }
					else {
						helper(nl.getList(), curDepth + 1, maxDepth, result);
					}
				}
			}

			int depthSumInverse(vector<NestedInteger>& nestedList) {
				int curDepth = 1;
				int maxDepth = 0;
				findMaxDepth(nestedList, curDepth, maxDepth);

				int result = 0;
				curDepth = 1;
				helper(nestedList, curDepth, maxDepth, result);
				return result;
			}
		}


		void Main() {
		}
	}
}
