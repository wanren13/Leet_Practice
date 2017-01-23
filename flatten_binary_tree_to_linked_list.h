#pragma once

#include "allhead.h"

namespace flatten_binary_tree_to_linked_list {
	class Solution {
	public:
		void flatten(TreeNode* root) {
			TreeNode* newRoot = new TreeNode(0);
			flat(newRoot, root);
		}

		void flat(TreeNode*& parent, TreeNode* child) {
			if (!child) return;
			cout << child->val << " ";
			parent->right = child;
			parent = child;
			TreeNode* left = child->left;
			TreeNode* right = child->right;
			child->left = NULL;
			flat(parent, left);
			flat(parent, right);
		}

		void printT(TreeNode* root) {
			if (root == nullptr) return;
			cout << root->val << " ";
			printT(root->left);
			printT(root->right);
		}

	};

	void test() {
		Solution sol;
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->right = new TreeNode(5);
		root->left->left = new TreeNode(3);
		root->left->right = new TreeNode(4);
		root->right->right = new TreeNode(6);
		sol.flatten(root);
		// sol.printT(root);
		unordered_map<int, int> m;

		cout << "For loop test: " << endl;

		for (int i = 0; i < 5; i++) {
			cout << i << endl;
			i++;
		}
	}
}