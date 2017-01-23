#pragma once

#include "allhead.h"

namespace populating_next_right_pointers_in_each_node_ii {
	/**
	* Definition for binary tree with next pointer.
	* struct TreeLinkNode {
	*  int val;
	*  TreeLinkNode *left, *right, *next;
	*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	* };
	*/
	class Solution {
	public:
		void connect(TreeLinkNode *root) {
			while (root) {
				TreeLinkNode *curr, *left = NULL;
				curr = root->left ? root->left : root->right;
				if (curr) left = curr;
				if (root->left && root->right) curr = root->left->next = root->right;
				while (root = root->next) {
					TreeLinkNode* next = root->left ? root->left : root->right;
					if (curr) curr->next = next;
					if (curr && !left) left = curr;
					if (root->left && root->right) curr = root->left->next = root->right;
					else curr = next;
				}
				root = left;
			}
		}
	};

	void test() {
		Solution sol;
	}
}

