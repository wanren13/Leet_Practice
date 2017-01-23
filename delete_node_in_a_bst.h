#pragma once

#include "allhead.h"

namespace delete_node_in_a_bst {
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
		TreeNode* deleteNode(TreeNode* root, int key) {
			return delNode(&root, key);
		}

		TreeNode* delNode(TreeNode** root, int key) {
			if (!*root) return *root;
			else if ((*root)->val == key) {
				if ((*root)->left && (*root)->right) {
					//*root = (*root)->left;
					//delNode(&(*root)->left, key);
					TreeNode* r = *root;
					TreeNode**l = &(*root)->right;
					while ((*l)->left) l = &(*l)->left;
					swap(r->val, (*l)->val);
					delNode(l, key);
				}
				else if ((*root)->left) {
					*root = (*root)->left;
				}
				else if ((*root)->right) {
					*root = (*root)->right;
				}
				else *root = NULL;
			}
			else if ((*root)->val > key) delNode(&(*root)->left, key);
			else delNode(&(*root)->right, key);
			return *root;
		}
	};

	void test() {
		TreeNode* root = new TreeNode(3);
		root->left = new TreeNode(1);
		root->right = new TreeNode(4);
		root->left->right = new TreeNode(2);

		Solution sol;

		root = sol.deleteNode(root, 3);
	}
}