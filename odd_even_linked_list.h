#pragma once

#include "allhead.h"

namespace odd_even_linked_list {
	class Solution {
	public:
		ListNode* oddEvenList(ListNode* head) {
			if (!head || !head->next) return head;
			ListNode *odd = head, *even = head->next, *evenhead = head->next;
			while (odd && even) {
				odd = odd->next = even->next;
				even = even->next = even->next ? even->next->next : NULL;
			}
			odd->next = evenhead;

			return head;


			//ListNode odd(0), even(0);
			//ListNode *curr = head, *ocurr = &odd, *ecurr = &even;
			//while (curr) {
			//	if (curr->val % 2) ocurr = ocurr->next = curr;
			//	else ecurr = ecurr->next = curr;
			//	curr = curr->next;
			//}
			//ocurr->next = even.next;
			//return odd.next;



			//if (!head) return head;
			//ListNode* odd = head;
			//ListNode* even = head->next;
			//ListNode* evenHead = head->next;
			//while (odd && even && even->next) {
			//	odd->next = odd->next->next;
			//	odd = odd->next;
			//	even->next = even->next->next;
			//	even = even->next;
			//}
			//odd->next = evenHead;
			//return head;
		}
	};

	void test() {
		Solution s;
		ListNode* head = new ListNode(1);
		head->next = new ListNode(2);
		// head->next->next = new ListNode(3);
		//head->next->next->next = new ListNode(4);
		//head->next->next->next->next = new ListNode(5);
		//head->next->next->next->next->next = new ListNode(6);
		//head->next->next->next->next->next->next = new ListNode(7);
		//head->next->next->next->next->next->next->next = new ListNode(8);

		head = s.oddEvenList(head);
		printLeetCodeLinkedList(head);		
	}
}