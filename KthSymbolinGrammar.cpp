#include "stdafx.h"

//We build a table of n rows (1-indexed). We start by writing 0 in the 1st row.
//Now in every subsequent row, we look at the previous row and replace each
//occurrence of 0 with 01, and each occurrence of 1 with 10.
//For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is
//0110.
//Given two integer n and k, return the kth (1-indexed) symbol in the nth row of
//a table of n rows.
// 
//
//Example 1:
//Input: n = 1, k = 1
//Output: 0
//Explanation: row 1: 0
//
//Example 2:
//Input: n = 2, k = 1
//Output: 0
//Explanation: 
//row 1: 0
//row 2: 01
//
//Example 3:
//Input: n = 2, k = 2
//Output: 1
//Explanation: 
//row 1: 0
//row 2: 01
// 
//Constraints:
//1 <= n <= 30
//1 <= k <= 2n - 1

namespace Solution2022
{
	namespace KthSymbolinGrammar
	{
		//The whole structure can be viewed a binary tree, when a node is 0, their two
		//children nodes are 0 and 1, similarly, when a node is 1, two children nodes are
		//1 and 0. We can know whether the position of K is a left node or a right node
		//by dividing 2. If K is even, current node is right child, and its parent is the
		//(K/2)th node in previous row; else if K is odd, current node is left child and
		//its parent is the ((K+1)/2)th node in previous row.
		//The value of current node depends on its parent node, without knowing its
		//parent node value, we still cannot determine current node value. That's why we
		//need recursion, we keep going previous row to find the parent node until reach
		//the first row. Then all the parent node value will be determined after the
		//recursion function returns.

	    int kthGrammar(int n, int k) {
			if (n == 1) { return 0; }
			if (k % 2 == 0) { // cur node is the right child
				return kthGrammar(n - 1, k / 2) ? 0 : 1;
			}
			else { // cur node is the left child
				return kthGrammar(n - 1, (k + 1) / 2) ? 1 : 0;
			}
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
