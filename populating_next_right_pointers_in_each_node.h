#pragma once

#include "allhead.h"

namespace populating_next_right_pointers_in_each_node {
	class Solution {
	public:
		void connect(TreeLinkNode *root) {
			//queue<TreeLinkNode*> q;
			//if(root) q.push(root);
			//int currlvl = 1, nextlvl = 0;

			//while (!q.empty()) {
			//	TreeLinkNode* prev = NULL, *curr = NULL;
			//	while (currlvl--) {
			//		curr = q.front();
			//		// cout << curr->val << " ";
			//		q.pop();
			//		if (prev) prev->next = curr;
			//		prev = curr;
			//		
			//		if (curr->left) {
			//			q.push(curr->left);
			//			nextlvl++;
			//		}
			//		if (curr->right) {
			//			q.push(curr->right);
			//			nextlvl++;
			//		}
			//	}
			//	currlvl = nextlvl;
			//	nextlvl = 0;
			//	// cout << endl;
			//}


			TreeLinkNode *prev = root;
			TreeLinkNode *curr = prev;

			while (prev) {
				curr = prev;
				while (curr) {
					if (curr->left) curr->left->next = curr->right;
					else return;
					if (curr->next) curr->right->next = curr->next->left;
					curr = curr->next;
				}
				prev = prev->left;
			}

		}
	};

	void test() {
		TreeLinkNode* root = new TreeLinkNode(1);
		root->left = new TreeLinkNode(2);
		root->right = new TreeLinkNode(3);
		root->left->left = new TreeLinkNode(4);
		root->left->right = new TreeLinkNode(5);
		root->right->left = new TreeLinkNode(6);
		root->right->right = new TreeLinkNode(7);

		Solution sol;
		sol.connect(root);
	}
}