#pragma once

#include "allhead.h"
// #define q.top().second topiter


namespace merge_k_sorted_lists {

	typedef pair<int, vector<ListNode*>::iterator> p;
	

	//class Solution {
	//public:
	//	ListNode* mergeKLists(vector<ListNode*>& lists) {
	//		ListNode* head = NULL;
	//		auto cmp = [](p left, p right) { return left.first > right.first; };
	//		priority_queue<p, vector<p>, decltype(cmp)> q(cmp);

	//		for (vector<ListNode*>::iterator iter = lists.begin(); iter != lists.end(); iter++) {
	//			if (*iter)	q.push(p((*iter)->val, iter));
	//		}

	//		if (q.empty()) return head;

	//		vector<ListNode*>::iterator iter = q.top().second;
	//		q.pop();
	//		head = *iter;
	//		if (head->next) {
	//			*iter = head->next;
	//			q.push(p(head->next->val, iter));
	//		}

	//		ListNode* curr = head;

	//		while (!q.empty()) {
	//			iter = q.top().second;
	//			q.pop();
	//			curr->next = *iter;
	//			curr = curr->next;
	//			if (curr->next) {
	//				*iter = curr->next;
	//				q.push(p(curr->next->val, iter));
	//			}
	//		 }


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
	//class Solution {
	//public:
	//	ListNode* mergeKLists(vector<ListNode*>& lists) {
	//		// if (lists.empty()) return NULL;
	//		if (lists.size() == 1) return lists[0];
	//		ListNode head(0); ListNode* curr = &head;
	//		auto cmp = [](ListNode* left, ListNode* right) { return left->val < right->val; };
	//		priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);

	//		for (ListNode* node : lists) if (node) q.push(node);

	//		while (!q.empty()) {
	//			curr->next = q.top();
	//			q.pop();
	//			curr = curr->next;
	//			if (curr->next) q.push(curr->next);
	//		}

	//		return head.next;
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
		ListNode* mergeKLists(vector<ListNode*>& lists) {
			auto cmp = [](ListNode* &n1, ListNode* &n2) {
				return n1->val > n2->val;
			};
			priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
			for (auto i : lists) q.push(i);
			ListNode head(0);
			ListNode *curr = &head;
			while (!q.empty()) {
				curr = curr->next = q.top();
				q.pop();
				if (curr->next) q.push(curr->next);
			}
			return head.next;
		}
	};


	void test() {
		Solution s;
		vector<ListNode*> lists;

		lists.emplace_back(new ListNode(1));
		lists[0] = NULL;

		//ListNode* l1 = new ListNode(1);
		//l1->next = new ListNode(3);
		//l1->next->next = new ListNode(5);

		//ListNode* l2 = //NULL;
		// new ListNode(2);
		// l2->next = new ListNode(2);
		// l2->next->next = new ListNode(6);

		//lists.emplace_back(l1);
		//lists.emplace_back(l2);

		ListNode* l = s.mergeKLists(lists);

		printLeetCodeLinkedList(l);


		//vector<int> v;
		//v.push_back(1);
		//v.push_back(2);
		//v.push_back(3);
		//v.push_back(4);
		//v.push_back(5);
		//v.push_back(6);

		//vector<int>::iterator iter = v.begin();

		//vector<int>::iterator iter2 = iter + 2;

		//(*iter2) = 10;


		//for (int i : v) {
		//	cout << i << " ";
		//}

		//cout << endl;
	}
}