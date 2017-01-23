#pragma once

#include "allhead.h"

namespace palindrome_linked_list {
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
		bool isPalindrome(ListNode* head) {
			if (!head || !head->next) return true;
			ListNode* slow, *fast;
			slow = head; fast = head;
			while (fast && fast->next) {
				slow = slow->next;
				fast = fast->next->next;
			}

			ListNode* curr = slow->next;
			ListNode* prev = NULL, *next;

			while (curr) {
				next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}

			while (prev) {
				if (head->val != prev->val) return false;
				head = head->next;
				prev = prev->next;
			}

			return true;






			// 		int n = 0;
			// 		ListNode* curr = head;
			// 		while (curr) {
			// 			curr = curr->next;
			// 			n++;
			// 		}
			// 		if (n < 2) return true;
			// 		int half = n / 2, mid = (n + 1) / 2;
			// 		int cnt = 0;
			// 		curr = head;
			// 		while (cnt++ != mid) curr = curr->next;
			// 		ListNode* next = curr->next;
			// 		while (next) {
			// 			ListNode* nextnext = next->next;
			// 			next->next = curr;
			// 			curr = next;
			// 			next = nextnext;
			// 		}
			// 		cnt = 0;
			// 		while (cnt++ != half) {
			// 			if (head->val != curr->val) return false;
			// 			head = head->next;
			// 			curr = curr->next;
			// 		}
			// 		return true;
		}
	};

	void test() {
		ListNode* head = new ListNode(1);
		head->next = new ListNode(2);
		head->next->next = new ListNode(3);
		head->next->next->next = new ListNode(1);
		//head->next->next->next->next = new ListNode(1);


		Solution sol;

		cout << "Is" << (sol.isPalindrome(head) ? " " : " not ") << "palindrome linked list" << endl;
	}


}