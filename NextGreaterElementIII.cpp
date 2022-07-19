#include "stdafx.h"

//Given a positive integer n, find the smallest integer which has exactly the
//same digits existing in the integer n and is greater in value than n. If no
//such positive integer exists, return -1.
//
//Note that the returned integer should fit in 32-bit integer, if there is a
//valid answer but it does not fit in 32-bit integer, return -1.
// 
//
//Example 1:
//Input: n = 12
//Output: 21
//
//Example 2:
//Input: n = 21
//Output: -1
// 
//Constraints:
//1 <= n <= 231 - 1

namespace Solution2022
{
	namespace NextGreaterElementIII
	{
		bool helper(string& s) {
			int len = s.size();

			int i = len - 1;
			while (i - 1 >= 0 && s[i - 1] >= s[i]) { i--; }
			if (i == 0) { return false; }


			int j = len - 1;
			while (s[j] <= s[i - 1]) { j--; }
			swap(s[i - 1], s[j]);
			reverse(s.begin() + i, s.end());
			return true;
		}


	    int nextGreaterElement(int n) {
			string s = to_string(n);
			if (!helper(s)) { return -1; }

			long long result = stoll(s);
			if (result > INT_MAX || result <= n) { return -1; }
			return (int)result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
