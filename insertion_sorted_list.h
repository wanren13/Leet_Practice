#pragma once

#include "allhead.h"

namespace insertion_sorted_list {
	class Solution {
	public:
		ListNode* insertionSortList(ListNode* head) {
			if (!head || !head->next) return head;
			ListNode* curr = head;
			ListNode* next;

			while (curr) {
				next = curr->next;
				if (next && curr->val > next->val) {
					curr->next = next->next; 
					next->next = NULL;
					head = insert(head, next);
				}
				else {
					curr = curr->next;
				}				
			}
			return head;
		}

		ListNode* insert(ListNode* head, ListNode* node) {
			if (node->val < head->val) {
				node->next = head;
				head = node;
			}
			else {
				ListNode* curr = head;
				while (curr->next && node->val > curr->next->val) curr = curr->next;
				node->next = curr->next;
				curr->next = node;
			}

			return head;
		}
	};

	void test() {
		//ListNode* head = new ListNode(3);
		//head->next = new ListNode(2);
		//head->next->next = new ListNode(1);
		
		
		ListNode* head = new ListNode(2);
		head->next = new ListNode(1);


		/*ListNode* head = new ListNode(1);
		head->next = new ListNode(2);
		head->next->next = new ListNode(3);
		head->next->next->next = new ListNode(2);
		head->next->next->next->next = new ListNode(1);*/

		Solution s;

		head = s.insertionSortList(head);
		printLeetCodeLinkedList(head);
	}
}
















/*
next = curr->next;
if (next) {
if (next->val < curr->val) {
// connect curr and next->next
curr->next = next->next;
// replace head with next
if (next->val < head->val) {
next->next = head;
head = next;
}
else {
localcurr = head;
while (next->val > localcurr->next->val) localcurr = localcurr->next;
next->next = localcurr->next;
localcurr->next = next;
}
}
prev = curr;
if (curr->next)
curr = curr->next;
}
else {
localcurr = head;
if (next->val < head->val) {
next->next = head;
head = next;
}


while (localcurr->next && curr->val > localcurr->next->val) localcurr = localcurr->next;
if (localcurr != prev) {
curr->next = localcurr->next;
localcurr->next = curr;
prev->next = NULL;
}
break;
}
}



*/