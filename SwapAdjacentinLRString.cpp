#include "stdafx.h"

//In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move
//consists of either replacing one occurrence of "XL" with "LX", or replacing one
//occurrence of "RX" with "XR". Given the starting string start and the ending
//string end, return True if and only if there exists a sequence of moves to
//transform one string to the other.
// 
//
//Example 1:
//Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
//Output: true
//Explanation: We can transform start to end following these steps:
//RXXLRXRXL ->
//XRXLRXRXL ->
//XRLXRXRXL ->
//XRLXXRRXL ->
//XRLXXRRLX
//
//Example 2:
//Input: start = "X", end = "L"
//Output: false
// 
//Constraints:
//1 <= start.length <= 104
//start.length == end.length
//Both start and end will only consist of characters in 'L', 'R', and 'X'.

namespace Solution2022
{
	namespace SwapAdjacentinLRString
	{

	    bool canTransform(string start, string end) {
			int len = start.size();
			string s1, s2;
			for (char c : start) {
				if (c != 'X') { s1.push_back(c); }
			}
			for (char c : end) {
				if (c != 'X') { s2.push_back(c); }
			}
			if (s1 != s2) { return false; }

			int i = 0;
			int j = 0;
			while (i < len && j < len) {
				while (i < len && start[i] == 'X') { i++; }
				while (j < len && end[j] == 'X') { j++; }
				if (i == len && j == len) { return true; }
				if (i == len || j == len) { return false; }

				if ((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) { return false; }
				i++;
				j++;
			}
			return true;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
