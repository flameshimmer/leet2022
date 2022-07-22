#include "stdafx.h"

//Implement strStr().
//Given two strings needle and haystack, return the index of the first occurrence
//of needle in haystack, or -1 if needle is not part of haystack.
//Clarification:
//What should we return when needle is an empty string? This is a great question
//to ask during an interview.
//For the purpose of this problem, we will return 0 when needle is an empty
//string. This is consistent to C's strstr() and Java's indexOf().
// 
//
//Example 1:
//Input: haystack = "hello", needle = "ll"
//Output: 2
//
//Example 2:
//Input: haystack = "aaaaa", needle = "bba"
//Output: -1
// 
//Constraints:
//1 <= haystack.length, needle.length <= 104
//haystack and needle consist of only lowercase English characters.

namespace Solution2022
{
	namespace ImplementstrStr
	{
	    int strStr(string haystack, string needle) {
			int len1 = haystack.size();
			int len2 = needle.size();
			if (len2 == 0) { return 0; }
			if (len1 < len2) { return -1; }

			int result = -1;
			for (int i = 0; i < len1; i++) {
				int j = 0;
				while(j < len2) {
					if (haystack[i + j] != needle[j]) {
						break;
					}
					j++;
				}
				if (j == len2) { return i; }
			}
			return -1;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
