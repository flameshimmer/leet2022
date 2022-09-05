#include "stdafx.h"

//Given two integers representing the numerator and denominator of a fraction,
//return the fraction in string format.
//If the fractional part is repeating, enclose the repeating part in parentheses.
//If multiple answers are possible, return any of them.
//It is guaranteed that the length of the answer string is less than 104 for all
//the given inputs.
// 
//
//Example 1:
//Input: numerator = 1, denominator = 2
//Output: "0.5"
//
//Example 2:
//Input: numerator = 2, denominator = 1
//Output: "2"
//
//Example 3:
//Input: numerator = 4, denominator = 333
//Output: "0.(012)"
// 
//Constraints:
//-231 <= numerator, denominator <= 231 - 1
//denominator != 0

namespace Solution2022
{
	namespace FractiontoRecurringDecimal
	{
		string fractionToDecimal(int numerator, int denominator) {
			if (numerator == 0) { return "0"; }
			string result;
			if (numerator > 0 ^ denominator > 0) { result += '-'; }
			long long n = labs(numerator);
			long long d = labs(denominator);

			result += to_string(n / d);
			long long r = n % d;
			if (r == 0) { return result; }

			result += '.';
			unordered_map<int, int> map; // <remainder value, last remainer value position in the result string>
			while (r) {
				if (map.find(r) != map.end()) {
					result.insert(map[r], "(");
					result += ')';
					break;
				}
				map[r] = result.size(); // why is this result.size instead of result.size -1: because the new d hasn't appended to the result yet!
				r *= 10;
				result += to_string(r / d);
				r %= d;
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
