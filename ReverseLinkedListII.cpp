#include "stdafx.h"

//Given the head of a singly linked list and two integers left and right where
//left <= right, reverse the nodes of the list from position left to position
//right, and return the reversed list.
// 
//
//Example 1:
//Input: head = [1,2,3,4,5], left = 2, right = 4
//Output: [1,4,3,2,5]
//
//Example 2:
//Input: head = [5], left = 1, right = 1
//Output: [5]
// 
//Constraints:
//The number of nodes in the list is n.
//1 <= n <= 500
//-500 <= Node.val <= 500
//1 <= left <= right <= n
// 
//Follow up: Could you do it in one pass?

namespace Solution2022
{
	namespace ReverseLinkedListII
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
		ListNode* reverseBetween(ListNode* head, int left, int right) {
			ListNode* dummy = new ListNode(0);
			dummy->next = head;
			ListNode* prev = dummy;
			for (int i = 0; i < left - 1; i++) {
				prev = prev->next;
			}

			ListNode* cur = prev->next;
			for (int i = 0; i < right - left; i++) {
				ListNode* tmp = prev->next;
				prev->next = cur->next;
				cur->next = cur->next->next;
				prev->next->next = tmp;
			}
			ListNode* result = dummy->next;
			delete dummy;
			return result;
		}

		void Main() {
			ListNode* test = createList({ 1, 2, 3, 4, 5 });
			print(reverseBetween(test, 2, 4));
		}
	}
}
