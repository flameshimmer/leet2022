#include "stdafx.h"
//Given a string s, reverse the order of characters in each word 
//within a sentence while still preserving whitespaceand initial word order.
//
//Example 1:
//
//Input: s = "Let's take LeetCode contest"
//	Output : "s'teL ekat edoCteeL tsetnoc"
//	Example 2 :
//
//	Input : s = "God Ding"
//	Output : "doG gniD"
//
//	Constraints :
//
//	1 <= s.length <= 5 * 104
//	s contains printable ASCII characters.
//	s does not contain any leading or trailing spaces.
//	There is at least one word in s.
//	All the words in s are separated by a single space.
namespace Solution2022
{
	namespace ReverseWordsinaStringIII
	{
		void reverse(string& s, int start, int end) {
			int len = s.size();
			if (len < 2) { return; }

			while (start < end) {
				char tmp = s[start];
				s[start] = s[end];
				s[end] = tmp;
				start++;
				end--;
			}
			return;
		}

		string reverseWords(string s) {
			int len = s.size();

			int front = 0;
			int back = 0;
			while (front < len) {
				while (front < len && s[front] == ' ') { front++; }
				back = front;
				while (front < len && s[front] != ' ') { front++; }
				reverse(s, back, front == len - 1 ? front : front - 1);				
			}
			return s;
		}

		void Main() {
			string test = "Let's take LeetCode contest";
			print(reverseWords(test));
		}
	}
}
