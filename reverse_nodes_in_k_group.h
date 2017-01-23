#pragma once

#include "allhead.h"

namespace reverse_nodes_in_k_group {
	class Solution {
	public:
		ListNode* reverseKGroup(ListNode* head, int k) {
			ListNode newhead(0);
			newhead.next = head;
			ListNode* nexthead = &newhead;
			while (nexthead) {
				ListNode* tmp = nexthead->next, *tail = nexthead->next;
				int cnt = 0;
				while (tmp && cnt++ < k - 1) tmp = tmp->next;				
				if (cnt == k) nexthead->next = reverse(nexthead->next, tmp->next);
				else break;
				nexthead = tail;
			}

			return newhead.next;
		}

		ListNode* reverse(ListNode* head, ListNode* tail) {
			ListNode* prev = tail, *next = NULL;
			while (head && head->next != tail) {
				next = head->next;
				head->next = prev;
				prev = head;
				head = next;
			}
			head->next = prev;
			return head;
		}
		
		
		
		
		//void reverse(ListNode** head, ListNode* tail) {
		//	if (!head || !(*head)) return;
		//	ListNode *prev = tail, *next = NULL;
		//	while (*head && (*head)->next != tail) {
		//		next = (*head)->next;
		//		(*head)->next = prev;
		//		prev = *head;
		//		*head = next;
		//	 }
		//	(*head)->next = prev;
		//}



		// ListNode* reverseKGroup(ListNode* head, int k) {
		//	ListNode newhead(0);
		//	newhead.next = head;
		//	ListNode* curr = &newhead, *tmp = curr->next;
		//	while (curr && tmp) {
		//		int cnt = 0;
		//		tmp = curr->next;
		//		while (tmp && cnt++ <= k) tmp = tmp->next;
		//		if (cnt == k + 1) curr->next = reverse(curr->next, tmp);
		//	}

		//	return newhead.next;
		//}

		//ListNode* reverse(ListNode* head, ListNode* tail) {
		//	ListNode *curr = head, *prev = tail, *next = NULL;
		//	while (curr && curr->next != tail) {
		//		next = curr->next;
		//		curr->next = prev;
		//		prev = curr;
		//		curr = next;
		//	}
		//	return curr;
		//}
	};

	void test() {
		ListNode* head = new ListNode(1);
		head->next = new ListNode(2);
		head->next->next = new ListNode(3);
		head->next->next->next = new ListNode(4);
		head->next->next->next->next = new ListNode(5);

		int k = 2;
		Solution sol;
		// sol.reverse(&head, NULL);

		ListNode *r = sol.reverseKGroup(head, k);
		printLeetCodeLinkedList(head);
	}
}