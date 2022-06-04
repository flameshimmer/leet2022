#include "stdafx.h"
//Given the head of a singly linked list, return the middle node of the linked list.
//
//If there are two middle nodes, return the second middle node.
//
//
//
//Example 1:
//
//
//Input: head = [1, 2, 3, 4, 5]
//	Output : [3, 4, 5]
//	Explanation : The middle node of the list is node 3.
//	Example 2 :
//
//
//	Input : head = [1, 2, 3, 4, 5, 6]
//	Output : [4, 5, 6]
//	Explanation : Since the list has two middle nodes with values 3 and 4, we return the second one.
//
//
//	Constraints :
//
//	The number of nodes in the list is in the range[1, 100].
//	1 <= Node.val <= 100
namespace Solution2022
{
	namespace MiddleoftheLinkedList
	{
		ListNode* middleNode(ListNode* head) {
			if (!head || !head->next) { return head; }

			ListNode* fast = head;
			ListNode* slow = head;
			while (fast && fast->next) {
				fast = fast->next->next;
				slow = slow->next;
			}
			return slow;
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
