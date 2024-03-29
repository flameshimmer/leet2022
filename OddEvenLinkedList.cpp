#include "stdafx.h"

//Given the head of a singly linked list, group all the nodes with odd indices
//together followed by the nodes with even indices, and return the reordered list.
//The first node is considered odd, and the second node is even, and so on.
//
//Note that the relative order inside both the even and odd groups should remain
//as it was in the input.
//You must solve the problem in O(1) extra space complexity and O(n) time
//complexity.
// 
//
//Example 1:
//Input: head = [1,2,3,4,5]
//Output: [1,3,5,2,4]
//
//Example 2:
//Input: head = [2,1,3,5,6,4,7]
//Output: [2,3,6,7,1,5,4]
// 
//Constraints:
//The number of nodes in the linked list is in the range [0, 104].
//-106 <= Node.val <= 106

namespace Solution2022
{
	namespace OddEvenLinkedList
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

		ListNode* oddEvenList(ListNode* head) {
			if (!head || !head->next || !head->next->next) { return head; }

			ListNode* odd = head;
			ListNode* even = head->next;
			ListNode* evenHead = even;
			while (even && even->next) {
				odd->next = even->next;
				odd = odd->next;
				even->next = odd->next;
				even = even->next;
			}
			odd->next = evenHead;
			return head;
		}

		namespace Another {
			ListNode* oddEvenList(ListNode* head) {
				if (!head || !head->next || !head->next->next) { return head; }

				ListNode* oddHead = nullptr;
				ListNode* oddTail = nullptr;
				ListNode* evenHead = nullptr;
				ListNode* evenTail = nullptr;
				int count = 1;

				ListNode* cur = head;
				while (cur) {
					bool isOdd = count % 2 == 1;
					ListNode*& head = isOdd ? oddHead : evenHead;
					ListNode*& tail = isOdd ? oddTail : evenTail;

					if (!head) { head = cur; }
					else { tail->next = cur; }
					tail = cur;

					cur = cur->next;
					count++;
				}

				oddTail->next = evenHead;
				evenTail->next = nullptr;

				return oddHead;
			}
		}

		void Main() {
			ListNode* test = createList({ 1, 2, 3, 4, 5 });
			print(oddEvenList(test));
		}
	}
}
