#include "stdafx.h"

//Given the head of a linked list and an integer val, remove all the nodes of the
//linked list that has Node.val == val, and return the new head.
// 
//
//Example 1:
//Input: head = [1,2,6,3,4,5,6], val = 6
//Output: [1,2,3,4,5]
//
//Example 2:
//Input: head = [], val = 1
//Output: []
//
//Example 3:
//Input: head = [7,7,7,7], val = 7
//Output: []
// 
//Constraints:
//The number of nodes in the list is in the range [0, 104].
//1 <= Node.val <= 50
//0 <= val <= 50

namespace Solution2022
{
	namespace RemoveLinkedListElements
	{
		/**
		 * Definition for singly-linked list.
		 * struct ListNode {
		 *     int val;
		 *     ListNode *next;
		 *     ListNode() : val(0), next(nullptr) {}
		 *     ListNode(int x) : val(x), next(nullptr) {}
		 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
		 * };
		 */
		ListNode* removeElements(ListNode* head, int val) {
			ListNode* dummyHead = new ListNode();
			dummyHead->next = head;

			ListNode* cur = dummyHead;
			while (cur->next) {
				if (cur->next->val == val) {
					ListNode* tmp = cur->next;
					cur->next = cur->next->next;
					delete tmp;
				}
				else {
					cur = cur->next;
				}
			}
			ListNode* result = dummyHead->next;
			delete dummyHead;
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
