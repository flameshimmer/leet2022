#include "stdafx.h"
//You are given the heads of two sorted linked lists list1 and list2.
//Merge the two lists in a one sorted list. The list should be made by splicing
//together the nodes of the first two lists.
//Return the head of the merged linked list.
// 
//
//Example 1:
//Input: list1 = [1,2,4], list2 = [1,3,4]
//Output: [1,1,2,3,4,4]
//
//Example 2:
//Input: list1 = [], list2 = []
//Output: []
//
//Example 3:
//Input: list1 = [], list2 = [0]
//Output: [0]
// 
//Constraints:
//The number of nodes in both lists is in the range [0, 50].
//-100 <= Node.val <= 100
//Both list1 and list2 are sorted in non-decreasing order. 
namespace Solution2022
{
	namespace MergeTwoSortedLists
	{
		ListNode* mergeTwoList(ListNode* list1, ListNode* list2) {
			if (!list1 || !list2) { return list1 ? list1 : list2; }

			ListNode* head = nullptr;
			ListNode* tail = nullptr;

			while (list1 && list2) {
				bool list1Smaller = list1->val < list2->val;
				if (!head) {
					head = list1Smaller ? list1 : list2;
					tail = head;
				}
				else {
					tail->next = list1Smaller ? list1 : list2;
					tail = tail->next;
				}
				if (list1Smaller) {
					list1 = list1->next;
				}
				else {
					list2 = list2->next;
				}
			}
			tail->next = list1 ? list1 : list2;
			return head;
		}

		ListNode* mergeTwoListsWithDummyNode(ListNode* list1, ListNode* list2) {
			if (!list1 || !list2) { return list1 ? list1 : list2; }

			ListNode* head = new ListNode(0);
			ListNode* tail = head;

			while (list1 && list2) {
				if (list1->val < list2->val) {
					tail->next = list1;
					list1 = list1->next;
				}
				else {
					tail->next = list2;
					list2 = list2->next;
				}
				tail = tail->next;
				tail->next = nullptr;
			}
			if (!list1 || !list2) { tail->next = list1 ? list1 : list2; }
			ListNode* result = head->next;
			delete head;
			return result;
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
