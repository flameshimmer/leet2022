#include "stdafx.h"
#include <regex> // for regex

//Convert a non-negative integer num to its English words representation.
// 
//
//Example 1:
//Input: num = 123
//Output: "One Hundred Twenty Three"
//
//Example 2:
//Input: num = 12345
//Output: "Twelve Thousand Three Hundred Forty Five"
//
//Example 3:
//Input: num = 1234567
//Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
// 
//Constraints:
//0 <= num <= 231 - 1

namespace Solution2022
{
	namespace IntegertoEnglishWords
	{
		string lessThan20[20] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
		string tens[10] = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
		string unit[4] = { "", "Thousand", "Million", "Billion" };


		string helper(int num) {
			if (num == 0) { return ""; }
			if (num < 20) { return lessThan20[num] + " "; }
			else if (num < 100) { return tens[num / 10]  + " " + helper(num % 10); }
			else { return lessThan20[num / 100] + " Hundred " + helper(num % 100); }
		}

	    string numberToWords(int num) {
			if (num == 0) { return "Zero"; }
			
			string result = "";
			int i = 0; 
			while (num > 0) {
				if (num % 1000) {
					result = helper(num % 1000) + unit[i] + " " + result;
				}
				num /= 1000;
				i++;
			}
			result = regex_replace(result, regex("^ +| +$"), "");
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
