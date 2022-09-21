#include "stdafx.h"

//Given the head of a linked list and a value x, partition it such that all nodes
//less than x come before nodes greater than or equal to x.
//You should preserve the original relative order of the nodes in each of the two
//partitions.
// 
//
//Example 1:
//Input: head = [1,4,3,2,5,2], x = 3
//Output: [1,2,2,4,3,5]
//
//Example 2:
//Input: head = [2,1], x = 2
//Output: [1,2]
// 
//Constraints:
//The number of nodes in the list is in the range [0, 200].
//-100 <= Node.val <= 100
//-200 <= x <= 200

namespace Solution2022
{
	namespace PartitionList
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
		ListNode* partition(ListNode* head, int x) {
			if (!head || !head->next) { return head; }

			ListNode* head1 = nullptr;
			ListNode* tail1 = nullptr;
			ListNode* head2 = nullptr;
			ListNode* tail2 = nullptr;

			ListNode* cur = head;
			while (cur) {
				if (cur->val < x) {
					if (!head1) { head1 = cur; }
					else { tail1->next = cur; }
					tail1 = cur;
				}
				else {
					if (!head2) { head2 = cur; }
					else { tail2->next = cur; }
					tail2 = cur;
				}
				cur = cur->next;
			}

			if (head1) { tail1->next = head2; } // NOTE: be careful of how to return the list!!!
			if (tail2) { tail2->next = nullptr; }
			return head1 ? head1 : head2;
		}

		void Main() {
			ListNode* test = createList({ 1,4,3,2,5,2 });
			print(partition(test, 3));
		}
	}
}
