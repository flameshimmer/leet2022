#include "stdafx.h"

//You are given a nested list of integers nestedList. Each element is either an
//integer or a list whose elements may also be integers or other lists. Implement
//an iterator to flatten it.
//Implement the NestedIterator class:
//NestedIterator(List<NestedInteger> nestedList) Initializes the iterator with
//the nested list nestedList.
//int next() Returns the next integer in the nested list.
//boolean hasNext() Returns true if there are still some integers in the nested
//list and false otherwise.
//Your code will be tested with the following pseudocode:
//initialize iterator with nestedList
//res = []
//while iterator.hasNext()
//    append iterator.next() to the end of res
//return res
//If res matches the expected flattened list, then your code will be judged as
//correct.
// 
//
//Example 1:
//Input: nestedList = [[1,1],2,[1,1]]
//Output: [1,1,2,1,1]
//Explanation: By calling next repeatedly until hasNext returns false, the order
//of elements returned by next should be: [1,1,2,1,1].
//
//Example 2:
//Input: nestedList = [1,[4,[6]]]
//Output: [1,4,6]
//Explanation: By calling next repeatedly until hasNext returns false, the order
//of elements returned by next should be: [1,4,6].
// 
//Constraints:
//1 <= nestedList.length <= 500
//The values of the integers in the nested list is in the range [-106, 106].

namespace Solution2022
{
	namespace FlattenNestedListIterator
	{

		// This is the interface that allows for creating nested lists.
		// You should not implement it, or speculate about its implementation
		class NestedInteger {
		public:
			// Return true if this NestedInteger holds a single integer, rather than a nested list.
			bool isInteger() const { return true; }

			// Return the single integer that this NestedInteger holds, if it holds a single integer
			// The result is undefined if this NestedInteger holds a nested list
			int getInteger() const { return 0; }

			// Return the nested list that this NestedInteger holds, if it holds a nested list
			// The result is undefined if this NestedInteger holds a single integer
			const vector<NestedInteger>& getList() const { return {}; }
		};


		class NestedIterator {
		private:
			stack<NestedInteger> s;
		public:
			NestedIterator(vector<NestedInteger>& nestedList) {
				int len = nestedList.size();
				for (int i = len - 1; i >= 0; i--) {
					s.push(nestedList[i]);
				}
			}

			int next() {
				int result = s.top().getInteger();
				s.pop();
				return result;
			}

			bool hasNext() {
				while (!s.empty()) {
					NestedInteger top = s.top();

					if (top.isInteger()) { return true; }

					s.pop();

					auto list = top.getList();
					for (int i = list.size() - 1; i >= 0; i--) {
						s.push(list[i]);
					}
				}
				return false;
			}
		};
/*
		namespace IteratorOnly {
			typedef vector<NestedInteger>::iterator iter;
			class NestedIterator {
			private:
				stack<iter> begins;
				stack<iter> ends;

			public:
				NestedIterator(vector<NestedInteger>& nestedList) {
					begins.push(nestedList.begin());
					ends.push(nestedList.end());
				}

				int next() {
					hasNext();
					int result = begins.top()->getInteger();
					begins.top()++;
					return result;
				}

				bool hasNext() {
					while (!begins.empty()) {
						if (begins.top() == ends.top()) {
							begins.pop();
							ends.pop();
						}
						else {
							auto top = begins.top();
							if (top->isInteger()) { return true; }
							
							begins.top()++;
							begins.push(top->getList().begin());
							ends.push(top->getList().end());
						}					
					}
					return false;
				}
			};
		}
*/
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
