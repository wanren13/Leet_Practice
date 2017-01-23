#pragma once

#include "allhead.h"

namespace sortedlisttoBST {
	class Solution {
	public:
		TreeNode* sortedListToBST(ListNode* head) {
			listtovector(head);
			// if (v.empty()) return NULL;
			// TreeNode* root;
			return createBST(0, v.size());
		}
	private:
		vector<TreeNode*> v;
		void listtovector(ListNode* head) {
			while (head) {
				v.emplace_back(new TreeNode(head->val));
				head = head->next;
			}
		}
		TreeNode* createBST(int start, int end) {
			if (start == end) return NULL;
			int middle = (start + end) / 2;
			TreeNode* root = v[middle];
			TreeNode* left = createBST(start, middle);
			TreeNode* right = createBST(middle + 1, end);
			root->left = left;
			root->right = right;
			return root;
		}
	};

	void test() {
		ListNode* head = new ListNode(1);
		head->next = new ListNode(3);
		head->next->next = new ListNode(4);
		head->next->next->next = new ListNode(5);
		head->next->next->next->next = new ListNode(7);

		Solution s;
		TreeNode* root = s.sortedListToBST(head);
		cout << "Here" << endl;

	}
}