#pragma once

#include "allhead.h"

namespace remove_linked_list_elements {
	class Solution {
	public:
		ListNode* removeElements(ListNode* head, int val) {
			ListNode* prev = head, *curr = head;
			// 1,3,1,1,2,3

			while (curr) {
				if (curr->val == val) {
					if (curr == head) {
						head = curr->next;
						curr = head;
						prev = head;
					}
					else {
						curr = curr->next;
						prev->next = curr;
					}
				}
				else {
					prev = curr;
					curr = curr->next;
				}
			}

			return head;
		}
	};

	void test() {
		Solution s;
		ListNode* head = new ListNode(1);
		head->next = new ListNode(1);
		head->next->next = new ListNode(1);
		//head->next->next->next = new ListNode(4);
		//head->next->next->next->next = new ListNode(5);
		//head->next->next->next->next->next = new ListNode(6);
		//head->next->next->next->next->next->next = new ListNode(7);
		//head->next->next->next->next->next->next->next = new ListNode(8);
		head = s.removeElements(head, 1);
		printLeetCodeLinkedList(head);
	}
}