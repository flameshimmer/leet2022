#include "stdafx.h"

//Given a string s containing an out-of-order English representation of digits
//0-9, return the digits in ascending order.
// 
//
//Example 1:
//Input: s = "owoztneoer"
//Output: "012"
//
//Example 2:
//Input: s = "fviefuro"
//Output: "45"
// 
//Constraints:
//1 <= s.length <= 105
//s[i] is one of the characters
//["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
//s is guaranteed to be valid.

namespace Solution2022
{
	namespace ReconstructOriginalDigitsfromEnglish
	{
	
	    string originalDigits(string s) {
			unordered_map<char, int> count;
			for (char c : s) { count[c] ++; }

			vector<int> out(10, 0);

			out[0] = count['z'];
			out[2] = count['w'];
			out[4] = count['u'];
			out[6] = count['x'];
			out[8] = count['g'];

			out[3] = count['h'] - out[8];
			out[5] = count['f'] - out[4];
			out[7] = count['s'] - out[6];

			out[9] = count['i'] - out[5] - out[6] - out[8];
			out[1] = count['n'] - out[7] - 2 * out[9];

			string result = "";
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < out[i]; j++) {
					result += to_string(i);
				}
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
