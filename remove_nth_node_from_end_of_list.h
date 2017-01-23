#pragma once

#include "allhead.h"


namespace remove_nth_node_from_end_of_list {
	//class Solution {
	//public:
	//	ListNode* removeNthFromEnd(ListNode* head, int n) {
	//		//vector<ListNode*> list;
	//		//ListNode* dummyhead = new ListNode(0);
	//		//dummyhead->next = head;
	//		//list.emplace_back(dummyhead);
	//		//ListNode* curr = head;
	//		//while (curr) {
	//		//	list.emplace_back(curr);
	//		//	curr = curr->next;
	//		//}

	//		//int size = list.size();
	//		//int i = size - n;

	//		//list[i - 1]->next = list[i]->next;

	//		//return list.front()->next;

	//		if (head == nullptr) return head;

	//		ListNode* node1 = head, *node2 = head;

	//		for (int i = 0; i < n; i++) {
	//			node2 = node2->next;
	//		}

	//		if (node2 == nullptr) return head->next;

	//		while (node2->next) {
	//			node1 = node1->next;
	//			node2 = node2->next;
	//		}

	//		node1->next = node1->next->next;

	//		return head;


	//	}
	//};


	/**
	* Definition for singly-linked list.
	* struct ListNode {
	*     int val;
	*     ListNode *next;
	*     ListNode(int x) : val(x), next(NULL) {}
	* };
	*/
	class Solution {
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			ListNode newhead(0);
			newhead.next = head;
			ListNode *first = &newhead, *last = &newhead;
			int i = 0;
			while (i++ < n + 1) last = last->next;
			while (last) first = first->next;
			first->next = first->next->next;
			return newhead.next;
		}
	};

	void test() {
		ListNode* head = new ListNode(1);
		head->next = new ListNode(2);
		head->next->next = new ListNode(3);
		head->next->next->next = new ListNode(4);
		head->next->next->next->next = new ListNode(5);

		int n = 1;

		printLeetCodeLinkedList(head);

		Solution sol;

		head = sol.removeNthFromEnd(head, n);

		printLeetCodeLinkedList(head);
	}





}