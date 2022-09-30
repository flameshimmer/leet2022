#include "stdafx.h"

//Given a linked list, swap every two adjacent nodes and return its head. You
//must solve the problem without modifying the values in the list's nodes (i.e.,
//only nodes themselves may be changed.)
// 
//
//Example 1:
//Input: head = [1,2,3,4]
//Output: [2,1,4,3]
//
//Example 2:
//Input: head = []
//Output: []
//
//Example 3:
//Input: head = [1]
//Output: [1]
// 
//Constraints:
//The number of nodes in the list is in the range [0, 100].
//0 <= Node.val <= 100

namespace Solution2022
{
	namespace SwapNodesinPairs
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
		namespace Recursive {
			ListNode* swapPairs(ListNode* head) {
				if (!head || !head->next) { return head; }
				ListNode* next = head->next;
				head->next = swapPairs(next->next);
				next->next = head;
				return next;
			}
		}

		namespace Iterative {
			ListNode* swapPairs(ListNode* head) {
				if (!head || !head->next) { return head; }

				ListNode* result = head->next;
				ListNode* cur = head;
				ListNode* next = cur->next;
				ListNode* nN = nullptr;
				ListNode* prev = nullptr;

				while (next) {
					nN = next->next;
					next->next = cur;
					cur->next = nN;

					if (prev) { prev->next = next; }
					prev = cur;

					cur = nN;
					next = cur ? cur->next : nullptr;
				}
				return result;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
