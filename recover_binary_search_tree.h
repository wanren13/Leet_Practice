#pragma once

#include "allhead.h"

namespace recover_binary_search_tree {
	/**
	* Definition for a binary tree node.
	* struct TreeNode {
	*     int val;
	*     TreeNode *left;
	*     TreeNode *right;
	*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	* };
	*/

	class Solution {
	public:
		void recoverTree(TreeNode* root) {
			TreeNode dummy(INT_MIN);
			TreeNode* pre = &dummy, *node = NULL;
			inOrder(pre, node, root);
		}

		void inOrder(TreeNode* pre, TreeNode* node, TreeNode* root) {
			if (!root) return;
			inOrder(pre, node, root->left);
			if (pre->val > root->val) {
				if (!node) node = pre;
				else swap(root->val, node->val);
			}
			pre = root;
			inOrder(pre, node, root->right);
		}
	};

	void test() {
		Solution sol;
		TreeNode* root = new TreeNode(0);
		root->left = new TreeNode(1);
//		root->right = new TreeNode(1);
		sol.recoverTree(root);
	}
}