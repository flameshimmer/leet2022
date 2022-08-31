#include "stdafx.h"

//Given two binary strings a and b, return their sum as a binary string.
// 
//
//Example 1:
//Input: a = "11", b = "1"
//Output: "100"
//
//Example 2:
//Input: a = "1010", b = "1011"
//Output: "10101"
// 
//Constraints:
//1 <= a.length, b.length <= 104
//a and b consist only of '0' or '1' characters.
//Each string does not contain leading zeros except for the zero itself.

namespace Solution2022
{
	namespace AddBinary
	{
	    string addBinary(string a, string b) {
			int i = a.size() - 1;
			int j = b.size() - 1;
			int carry = 0;
			string result = "";

			while (carry || i >= 0 || j >= 0) {
				int v1 = (i >= 0) ? a[i] - '0' : 0;
				int v2 = (j >= 0) ? b[j] - '0' : 0;
				int sum = v1 + v2 + carry;
				carry = sum / 2;
				result = to_string(sum % 2) + result;
				i--;
				j--;
			}
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
