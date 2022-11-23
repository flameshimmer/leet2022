#include "stdafx.h"

//Given two non-negative integers num1 and num2 represented as strings, return
//the product of num1 and num2, also represented as a string.
//
//Note: You must not use any built-in BigInteger library or convert the inputs to
//integer directly.
// 
//
//Example 1:
//Input: num1 = "2", num2 = "3"
//Output: "6"
//
//Example 2:
//Input: num1 = "123", num2 = "456"
//Output: "56088"
// 
//Constraints:
//1 <= num1.length, num2.length <= 200
//num1 and num2 consist of digits only.
//Both num1 and num2 do not contain any leading zero, except the number 0 itself.

namespace Solution2022
{
	namespace MultiplyStrings
	{

		string multiply(string num1, string num2) {
			int len1 = num1.size();
			int len2 = num2.size();
			string result(len1 + len2, '0');

			for (int i = len1 - 1; i >= 0; i--) {
				int carry = 0;
				for (int j = len2 - 1; j >= 0; j--) {
					int sum = (num1[i] - '0') * (num2[j] - '0') + carry + (result[i + j + 1] - '0');
					carry = sum / 10;
					result[i + j + 1] = sum % 10 + '0';
				}
				if (carry > 0) { result[i] += carry; }
			}

			size_t pos = result.find_first_not_of('0');
			if (pos != string::npos) { return result.substr(pos); }
			return "0";
		}

		void Main() {
			print(multiply("2", "3"));
		}
	}
}
