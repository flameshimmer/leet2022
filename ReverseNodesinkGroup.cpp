#include "stdafx.h"

//Given the head of a linked list, reverse the nodes of the list k at a time, and
//return the modified list.
//k is a positive integer and is less than or equal to the length of the linked
//list. If the number of nodes is not a multiple of k then left-out nodes, in the
//end, should remain as it is.
//You may not alter the values in the list's nodes, only nodes themselves may be
//changed.
// 
//
//Example 1:
//Input: head = [1,2,3,4,5], k = 2
//Output: [2,1,4,3,5]
//
//Example 2:
//Input: head = [1,2,3,4,5], k = 3
//Output: [3,2,1,4,5]
// 
//Constraints:
//The number of nodes in the list is n.
//1 <= k <= n <= 5000
//0 <= Node.val <= 1000
// 
//Follow-up: Can you solve the problem in O(1) extra memory space?

namespace Solution2022
{
	namespace ReverseNodesinkGroup
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

		ListNode* reverseLinkedList(ListNode* head) {
			if (!head || !head->next) { return head; }
			ListNode* cur = head;
			ListNode* next = head->next;
			ListNode* nN = nullptr;

			cur->next = nullptr;
			while (next) {
				nN = next->next;
				next->next = cur;
				cur = next;
				next = nN;
			}
			return cur;
		}

		ListNode* reverseKGroup(ListNode* head, int k) {
			if (!head || !head->next || k == 1) { return head; }

			ListNode* resultHead = nullptr;
			ListNode* resultTail = nullptr;
			ListNode* start = head;
			ListNode* end = head;
			ListNode* next;

			while (end) {
				int i = 0;
				while (end && i < k - 1) { end = end->next; i++; }

				if (end) {
					next = end->next;
					end->next = nullptr;
					reverseLinkedList(start);

					if (!resultHead) { resultHead = end; }
					else { resultTail->next = end; }
					resultTail = start;

					start = next;
					end = next;
				}
			}
			if (!resultTail) { return head; }
			resultTail->next = start;
			return resultHead;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
