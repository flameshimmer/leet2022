#include "stdafx.h"
//Given the head of a singly linked list, reverse the list, and return the
//reversed list.
// 
//
//Example 1:
//Input: head = [1,2,3,4,5]
//Output: [5,4,3,2,1]
//
//Example 2:
//Input: head = [1,2]
//Output: [2,1]
//
//Example 3:
//Input: head = []
//Output: []
// 
//Constraints:
//The number of nodes in the list is the range [0, 5000].
//-5000 <= Node.val <= 5000
// 
//Follow up: A linked list can be reversed either iteratively or recursively.
//Could you implement both?

namespace Solution2022
{
	namespace ReverseLinkedList
	{
		ListNode* reverseList(ListNode* head) {
			if (!head || !head->next) { return head; }

			ListNode* cur = head;
			ListNode* next = cur->next;
			ListNode* nN = next->next;

			cur->next = nullptr;
			while (next) {
				nN = next->next;
				next->next = cur;
				cur = next;
				next = nN;
			}
			return cur;
		}

		ListNode* reverseListRecursive(ListNode* head) {
			if (!head || !head->next) { return head; }

			ListNode* newTail = head->next;
			ListNode* newHead = reverseListRecursive(newTail);
			newTail->next = head;
			head->next = nullptr;
			return newHead;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
