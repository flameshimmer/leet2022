#include "stdafx.h"

//You are given an array of k linked-lists lists, each linked-list is sorted in
//ascending order.
//Merge all the linked-lists into one sorted linked-list and return it.
// 
//
//Example 1:
//Input: lists = [[1,4,5],[1,3,4],[2,6]]
//Output: [1,1,2,3,4,4,5,6]
//Explanation: The linked-lists are:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//merging them into one sorted list:
//1->1->2->3->4->4->5->6
//
//Example 2:
//Input: lists = []
//Output: []
//
//Example 3:
//Input: lists = [[]]
//Output: []
// 
//Constraints:
//k == lists.length
//0 <= k <= 104
//0 <= lists[i].length <= 500
//-104 <= lists[i][j] <= 104
//lists[i] is sorted in ascending order.
//The sum of lists[i].length will not exceed 104.

namespace Solution2022
{
	namespace MergekSortedLists
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
	    ListNode* mergeKLists(vector<ListNode*>& lists) {
			int len = lists.size();
			if (len == 0) { return nullptr; }

			ListNode* head = nullptr;
			ListNode* tail = nullptr;

			auto comp = [](ListNode* a, ListNode* b) {return a->val > b->val; };

			priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

			for (ListNode* l : lists) {
				if (l) {
					pq.push(l);
				}
			}

			while (!pq.empty()) {
				ListNode* top = pq.top();
				pq.pop();
				
				if (top->next) { pq.push(top->next); }

				if (!head) { head = top; }
				else { tail->next = top; }
				tail = top;
			}
			return head;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
