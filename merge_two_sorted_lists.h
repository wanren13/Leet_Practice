#pragma once

#include "allhead.h"

namespace merge_two_sorted_lists {
	//class Solution {
	//public:
	//	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	//		ListNode* head = NULL;
	//		if (!l1 && !l2) return head;

	//		ListNode* curr;

	//		int num1 = INT_MAX, num2 = INT_MAX;
	//		if (l1) num1 = l1->val;
	//		if (l2) num2 = l2->val;

	//		if (num1 < num2) {
	//			head = l1;
	//			l1 = l1->next;
	//		}
	//		else {
	//			head = l2;
	//			l2 = l2->next;
	//		}

	//		curr = head;

	//		while (l1 || l2) {
	//			if (l1) num1 = l1->val;
	//			else {
	//				curr->next = l2;
	//				break;
	//			}
	//			if (l2) num2 = l2->val;
	//			else {
	//				curr->next = l1;
	//				break;
	//			}

	//			if (num1 < num2) {
	//				if (l1) {
	//					curr->next = l1;
	//					l1 = l1->next;
	//				}
	//			}
	//			else {
	//				if (l2) {
	//					curr->next = l2;
	//					l2 = l2->next;
	//				}
	//			}
	//			curr = curr->next;
	//		}
	//		return head;
	//	}
	//};


	class Solution {
	public:
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			ListNode head(0);
			//ListNode *curr = &head;
			//while (l1 || l2) {
			//	if (l1 && l2) {
			//		if (l1->val > l2->val)->next = l1->val < l2->val ? l1 : l2;
			//	else {
			//		curr->next = l1 ? l1 : l2;
			//		break;
			//	}
			//	curr = curr->next;
			//}

			return head.next;
		}
	};

	void test() {
		Solution s;
		ListNode* l1, *l2;
		l1 = new ListNode(1);
		l1->next = new ListNode(3);
		l1->next->next = new ListNode(5);

		l2 = new ListNode(2);
		l2->next = new ListNode(4);
		l2->next->next = new ListNode(6);

		ListNode* head = s.mergeTwoLists(l1, l2);

		printLeetCodeLinkedList(head);
	}
}