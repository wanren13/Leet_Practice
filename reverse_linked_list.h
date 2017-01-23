#pragma once

#include "allhead.h"

namespace reverse_linked_list {
	/**
	* Definition for singly-linked list.
	* struct ListNode {
	*     int val;
	*     ListNode *next;
	*     ListNode(int x) : val(x), next(NULL) {}
	* };
	*/
	//class Solution {
	//public:
	//	ListNode* reverseList(ListNode* head) {
	//		// if (head == nullptr || head->next == nullptr) return head;

	//		/* Iterative way 1
	//		stack<ListNode*> s;
	//		while (head) {
	//		s.push(head);
	//		head = head->next;
	//		}

	//		head = s.top();
	//		s.pop();
	//		ListNode* curr = head;

	//		while (!s.empty()) {
	//		curr->next = s.top();
	//		s.pop();
	//		curr = curr->next;
	//		}

	//		curr->next = NULL;
	//		//*/

	//		/* Recurrsion way 1
	//		ListNode* next = head->next;
	//		head->next = NULL;
	//		head = reverse(head, next);
	//		//*/


	//		//* Iterative way 2
	//		//if (head = nullptr) return head;
	//		ListNode* next = head, *curr = head, *prev = NULL;
	//		while (next) {
	//			curr = next;
	//			next = curr->next;
	//			curr->next = prev;
	//			prev = curr;			
	//		}
	//		return curr;
	//		//*/

	//		/* Recurrsion way 2
	//		ListNode *node = reverseList(head->next);
	//		node->next = head;




	//		//*/





	//		
	//	}

	//	ListNode* reverse(ListNode* head, ListNode* next) {
	//		if (next == nullptr) return head;
	//		else {
	//			ListNode *nextNode = next->next;
	//			next->next = head;
	//			return reverse(next, nextNode);
	//		}
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
		// ListNode* reverseList(ListNode* head) {
		//     ListNode* curr = head, *prev = NULL;
		//     while (curr) {
		//         ListNode* next = curr->next;
		//         curr->next = prev;
		//         prev = curr;
		//         curr = next;
		//     }
		//     return prev;
		// }
		ListNode* reverseList(ListNode* head) {
			ListNode* tail = reverseList1(head);
			if (tail) tail->next = NULL;
			return newhead;
		}


		ListNode* reverseList1(ListNode* head) {
			if (!head || !head->next) newhead = head;
			else {
				ListNode* tmp = reverseList1(head->next);
				tmp->next = head;
			}
			return head;
		}

	private:
		ListNode* newhead;
	};


	void test() {
		Solution sol;

		ListNode *head = generateLeetCodeLinkedList(0);

		printLeetCodeLinkedList(head);

		head = generateLeetCodeLinkedList(5);

		head = sol.reverseList(head);

		printLeetCodeLinkedList(head);
	}
}