#include "stdafx.h"

//Given the head of a linked list, return the list after sorting it in ascending
//order.
// 
//
//Example 1:
//Input: head = [4,2,1,3]
//Output: [1,2,3,4]
//
//Example 2:
//Input: head = [-1,5,3,4,0]
//Output: [-1,0,3,4,5]
//
//Example 3:
//Input: head = []
//Output: []
// 
//Constraints:
//The number of nodes in the list is in the range [0, 5 * 104].
//-105 <= Node.val <= 105
// 
//Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e.
//constant space)?

namespace Solution2022
{
	namespace SortList
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
		ListNode* merge(ListNode* l1, ListNode* l2) {
			if (!l1 || !l2) { return l1 ? l1 : l2; }

			ListNode* head = nullptr;
			ListNode* tail = nullptr;

			while (l1 && l2) {
				bool l1Smaller = l1->val < l2->val;
				ListNode* node = l1Smaller ? l1 : l2;

				if (!head) { head = node; }
				else { tail->next = node; }
				tail = node;

				if (l1Smaller) { l1 = l1->next; }
				else { l2 = l2->next; }
			}
			tail->next = l1 ? l1 : l2;
			return head;
		}

	    ListNode* sortList(ListNode* head) {
			if (!head || !head->next) { return head; }

			ListNode* slow = head;
			ListNode* fast = head->next;
			while (fast && fast->next) {
				slow = slow->next;
				fast = fast->next->next;
			}
			ListNode* secondHead = slow->next;
			slow->next = nullptr;
			
			ListNode* left = sortList(head);
			ListNode* right = sortList(secondHead);
			return merge(left, right);
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
