#pragma once

#include "allhead.h"

namespace intersection_of_two_linked_lists {
	class Solution {
	public:
		ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
			if (!headA || !headB) return NULL;
			ListNode *p1 = headA, *p2 = headB;
			while (p1 != p2) {
				if (!p1) p1 = headB;
				if (!p2) p2 = headA;
				p1 = p1->next;
				p2 = p2->next;				
			}
			return p1;
		}
	};

	void test() {
		ListNode *c = new ListNode(6);
		c->next = new ListNode(7);
		c->next->next = new ListNode(8);

		ListNode *a = new ListNode(1);
		a->next = new ListNode(2);
		//a->next->next = c;
		ListNode *b = new ListNode(3);
		b->next = new ListNode(4);
		b->next->next = new ListNode(5);
		//b->next->next->next = c;

		Solution sol;
		c = sol.getIntersectionNode(a, b);
		printLeetCodeLinkedList(c);
	}
}