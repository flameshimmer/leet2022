#include "stdafx.h"

//Given two non-negative integers, num1 and num2 represented as string, return
//the sum of num1 and num2 as a string.
//You must solve the problem without using any built-in library for handling
//large integers (such as BigInteger). You must also not convert the inputs to
//integers directly.
// 
//
//Example 1:
//Input: num1 = "11", num2 = "123"
//Output: "134"
//
//Example 2:
//Input: num1 = "456", num2 = "77"
//Output: "533"
//
//Example 3:
//Input: num1 = "0", num2 = "0"
//Output: "0"
// 
//Constraints:
//1 <= num1.length, num2.length <= 104
//num1 and num2 consist of only digits.
//num1 and num2 don't have any leading zeros except for the zero itself.

namespace Solution2022
{
	namespace AddStrings
	{
	    string addStrings(string num1, string num2) {
			int len1 = num1.size();
			int len2 = num2.size();
			if (!len1 || !len2) { return len1 ? num1 : num2; }

			int i = len1 - 1;
			int j = len2 - 1;
			int carry = 0;
			string result = "";
			while (i >= 0 || j >= 0 || carry) {
				int v1 = i >= 0 ? num1[i] - '0' : 0;
				int v2 = j >= 0 ? num2[j] - '0' : 0;
				int sum = v1 + v2 + carry;
				result = to_string(sum % 10) + result;
				carry = sum / 10;
				i--; // Note: don't forget to update indexes!!!
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
