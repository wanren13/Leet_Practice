#include "allhead.h"

namespace remove_duplicates_from_sorted_list_ii {
	class Solution {
	public:
		ListNode* deleteDuplicates(ListNode* head) {
			//ListNode dummyhead(0);
			//dummyhead.next = head;
			//ListNode* curr = &dummyhead;
			//while (curr) {
			//	int cnt = 0;
			//	ListNode* next = curr->next;
			//	while (next && next->next && next->val == next->next->val) {
			//		next = next->next;
			//		cnt++;
			//	}
			//	cnt = cnt > 0 ? cnt + 1 : cnt;
			//	while (cnt--) {
			//		next = curr->next;
			//		curr->next = next->next;
			//		delete next;
			//	}
			//}
			//return dummyhead.next;


			ListNode** curr = &head;
			while (*curr) {
				ListNode* next = (*curr)->next;
				while ((*curr)->val == next->val) { next = next->next; }
				if ((*curr)->next != next) {
					while ((*curr) != next) *curr = (*curr)->next;
				}
				else curr = &(*curr)->next;
			}

			return head;

		}
	};

	void test() {
		ListNode* head = new ListNode(1);
		head->next = new ListNode(2);
		head->next->next = new ListNode(2);
		head->next->next->next = new ListNode(3);

		Solution sol;
		head = sol.deleteDuplicates(head);
		printLeetCodeLinkedList(head);
	}
}

