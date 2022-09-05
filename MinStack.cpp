#include "stdafx.h"

//Design a stack that supports push, pop, top, and retrieving the minimum element
//in constant time.
//Implement the MinStack class:
//MinStack() initializes the stack object.
//void push(int val) pushes the element val onto the stack.
//void pop() removes the element on the top of the stack.
//int top() gets the top element of the stack.
//int getMin() retrieves the minimum element in the stack.
// 
//
//Example 1:
//Input
//["MinStack","push","push","push","getMin","pop","top","getMin"]
//[[],[-2],[0],[-3],[],[],[],[]]
//Output
//[null,null,null,null,-3,null,0,-2]
//Explanation
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin(); // return -3
//minStack.pop();
//minStack.top();    // return 0
//minStack.getMin(); // return -2
// 
//Constraints:
//-231 <= val <= 231 - 1
//Methods pop, top and getMin operations will always be called on non-empty
//stacks.
//At most 3 * 104 calls will be made to push, pop, top, and getMin.

namespace Solution2022
{
	namespace MinStack
	{
		namespace UseVector {
		
			class MinStack {
			private:
				vector<pair<int, int>> s;
			public:
				MinStack() {

				}

				void push(int val) {
					if (s.empty()) { s.push_back({val, val}); }
					else {
						s.push_back({val, min(val, s.back().second)});
					}
				}

				void pop() {
					if (!s.empty()) { s.pop_back(); }
				}

				int top() {
					return s.back().first;
				}

				int getMin() {
					return s.back().second;
				}
			};
		
		}

		namespace UseTwoStacks {
			class MinStack {
			private:
				stack<int> s1;
				stack<int> s2;
			public:
				MinStack() {

				}

				void push(int val) {
					s1.push(val);
					if (s2.empty() || s2.top() >= val) { s2.push(val); }
				}

				void pop() {
					if (s1.top() == s2.top()) { s2.pop(); }
					s1.pop();
				}

				int top() {
					return s1.top();
				}

				int getMin() {
					return s2.top();
				}
			};		
		}


		/**
		 * Your MinStack object will be instantiated and called as such:
		 * MinStack* obj = new MinStack();
		 * obj->push(val);
		 * obj->pop();
		 * int param_3 = obj->top();
		 * int param_4 = obj->getMin();
		 */

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
