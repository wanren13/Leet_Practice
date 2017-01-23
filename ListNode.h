#pragma once

#include "allhead.h"

// Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void printLeetCodeLinkedList(ListNode* head) {
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

ListNode* generateLeetCodeLinkedList(int n) {
	ListNode* head = NULL;
	ListNode** curr = &head;
	for (int i = 1; i <= n; i++) {
		*curr = new ListNode(i);
		curr = &(*curr)->next;
	}

	return head;
}



// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

