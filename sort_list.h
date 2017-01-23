#pragma once

#include "allhead.h"

namespace sort_list {
	class Solution {
	public:
		ListNode* sortList(ListNode* head) {
			
			
			
			
			return head;
		}
	};

	void test() {
		ListNode* head = new ListNode(2);
		head->next = new ListNode(3);
		head->next->next = new ListNode(1);

		Solution s;
		head = s.sortList(head);

		printLeetCodeLinkedList(head);
	}
}