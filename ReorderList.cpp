#include "stdafx.h"

//You are given the head of a singly linked-list. The list can be represented as:
//L0 → L1 → … → Ln - 1 → Ln
//Reorder the list to be on the following form:
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//You may not modify the values in the list's nodes. Only nodes themselves may be
//changed.
// 
//
//Example 1:
//Input: head = [1,2,3,4]
//Output: [1,4,2,3]
//
//Example 2:
//Input: head = [1,2,3,4,5]
//Output: [1,5,2,4,3]
// 
//Constraints:
//The number of nodes in the list is in the range [1, 5 * 104].
//1 <= Node.val <= 1000

namespace Solution2022
{
	namespace ReorderList
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

		namespace ThreeSteps {

			ListNode* getMid(ListNode* head) {
				ListNode* slow = head;
				ListNode* fast = head->next;
				while (fast && fast->next) {
					slow = slow->next;
					fast = fast->next->next;
				}
				return slow;
			}

			ListNode* reverse(ListNode* head) {
				if (!head || !head->next) { return head; }
				ListNode* cur = head;
				ListNode* next = head->next;
				ListNode* nN;
				cur->next = nullptr;
				while (next) {
					nN = next->next;
					next->next = cur;
					cur = next;
					next = nN;
				}
				return cur;
			}

			void reorderList(ListNode* head) {
				if (!head || !head->next) { return; }

				ListNode* mid = getMid(head);
				ListNode* first = head;
				ListNode* second = mid->next;
				mid->next = nullptr;

				second = reverse(second);

				ListNode* resultHead = nullptr;
				ListNode* resultTail = nullptr;
				int i = 0;
				while (first && second) {
					ListNode* node = first;
					if (i % 2) { node = second; }

					if (!resultHead) { resultHead = node; }
					else { resultTail->next = node; }
					resultTail = node;

					if (node == first) { first = first->next; }
					else { second = second->next; }
					i++;
				}
				if (first || second) {
					resultTail->next = first ? first : second;
				}
			}
		}


		namespace UseStack {

			void reorderList(ListNode* head) {
				if (!head || !head->next || !head->next->next) { return; }

				stack<ListNode*> s;
				ListNode* cur = head;
				int size = 0;
				while (cur) {
					s.push(cur);
					cur = cur->next;
					size++;
				}

				cur = head;
				ListNode* next;
				for (int i = 0; i < size / 2; i++) {
					next = cur->next;
					cur->next = s.top();
					s.pop();
					cur->next->next = next;
					cur = next;
				}
				cur->next = nullptr;
			}

		}
		void Main() {
			ThreeSteps::reorderList(createList({ 1, 2, 3, 4, 5 }));
		}
	}
}
