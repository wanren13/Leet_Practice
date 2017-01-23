#pragma once

#include "allhead.h"

namespace reorder_list {
	class Solution {
	public:
		void reorderList(ListNode* head) {

			/* My solution (works well)
			if (!head || !head->next) return;
			
			ListNode* slow = head, *fast = head, *last = head;
			
			while (fast && fast->next) {
				last = slow;
				slow = last->next;
				fast = fast->next->next;
			}

			last->next = NULL;

			ListNode* newhead, *prev;

			if (fast) {
				newhead = slow->next;
				prev = slow;
				prev->next = NULL;
			}
			else {
				newhead = slow;
				prev = NULL;
			}

			ListNode *curr = newhead;

			while (newhead) {
				curr = newhead;
				newhead = curr->next;
				curr->next = prev;
				prev = curr;
			}

			ListNode *p = head, *next, *tmp;

			while (p) {
				next = p->next;
				tmp = curr->next;
				p->next = curr;	
				if (next) curr->next = next;
				p = next;
				curr = tmp;
			}

			//*/


			//* Leet Code Solution
			if (!head || !head->next) return;

			// find the middle node: O(n)
			ListNode *p1 = head, *p2 = head->next;
			while (p2 && p2->next) {
				p1 = p1->next;
				p2 = p2->next->next;
			}

			// cut from the middle and reverse the second half: O(n)
			ListNode *head2 = p1->next;
			p1->next = NULL;

			p2 = head2->next;
			head2->next = NULL;
			while (p2) {
				p1 = p2->next;
				p2->next = head2;
				head2 = p2;
				p2 = p1;
			}

			// merge two lists: O(n)
			for (p1 = head, p2 = head2; p1; ) {
				auto t = p1->next;
				p1 = p1->next = p2;
				p2 = t;
			}

			//*/
		}
	};

	void test() {
		Solution sol;
		ListNode* head = generateLeetCodeLinkedList(4);
		sol.reorderList(head);
		printLeetCodeLinkedList(head);
		/*head = generateLeetCodeLinkedList(5);
		sol.reorderList(head);
		printLeetCodeLinkedList(head);*/
		int a = 1, b = 2, c = 3;
		a = b = c;
		cout << "a " << a << endl;
		cout << "b " << b << endl;
		cout << "c " << c << endl;
	}
}