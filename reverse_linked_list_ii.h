#pragma once

#include "allhead.h"

namespace reverse_linked_list_ii {
	class Solution {
	public:
		ListNode* reverseBetween(ListNode* head, int m, int n) {
			if (head == nullptr) return head;
			ListNode* dumbhead = new ListNode(0);
			dumbhead->next = head;
			ListNode* lefttail = dumbhead, *righthead = NULL, *reversehead;

			for (int i = 1; i < m; i++) {
				lefttail = lefttail->next;
			}

			reversehead = lefttail->next;

			ListNode *next = reversehead, *curr = reversehead, *prev = NULL;

			int count = 0;

			while (count <= n - m) {
				curr = next;
				next = curr->next;
				curr->next = prev;
				prev = curr;
				count++;
			}

			reversehead->next = next;
			lefttail->next = curr;
			return dumbhead->next;
		}
	};


	void test() {
		ListNode* head = generateLeetCodeLinkedList(0);
		int m = 0, n = 0;
		Solution sol;
		head = sol.reverseBetween(head, m, n);
		printLeetCodeLinkedList(head);
	}
}