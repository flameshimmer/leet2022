#include "stdafx.h"

//Given the head of a singly linked list, return true if it is a palindrome.
// 
//
//Example 1:
//Input: head = [1,2,2,1]
//Output: true
//
//Example 2:
//Input: head = [1,2]
//Output: false
// 
//Constraints:
//The number of nodes in the list is in the range [1, 105].
//0 <= Node.val <= 9
// 
//Follow up: Could you do it in O(n) time and O(1) space?

namespace Solution2022
{
	namespace PalindromeLinkedList
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
		namespace TwoPass {
			bool isPalindrome(ListNode* head) {
				if (!head || !head->next) {
					return true;
				}
				stack<int> s;

				ListNode* cur = head;
				while (cur) {
					s.push(cur->val);
					cur = cur->next;
				}

				cur = head;
				while (cur) {
					if (cur->val != s.top()) {
						return false;
					}
					s.pop();
					cur = cur->next;
				}
				return true;
			}
		}


		namespace TwoPointersOnePass {
			bool isPalindrome(ListNode* head) {
				if (!head || !head->next) { return true; }

				ListNode* slow = head;
				ListNode* fast = head->next;
				stack<int> s;
				while (fast && fast->next) {
					s.push(slow->val);
					slow = slow->next;
					fast = fast->next->next;
				}

				if (fast) { s.push(slow->val); }
				slow = slow->next;

				while (slow) {
					if (slow->val != s.top()) { return false; }
					slow = slow->next;
					s.pop();
				}
				return true;
			}
		}


		void Main() {
			//ListNode* test = createList({ 1, 2, 2, 1 });
			//print(TwoPass::isPalindrome(test));

			ListNode* test = createList({ 1, 2, 3, 2, 1 });
			print(TwoPass::isPalindrome(test));
		}
	}
}
