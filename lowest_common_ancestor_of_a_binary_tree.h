#pragma once

#include "allhead.h"

namespace lowest_common_ancestor_of_a_binary_tree {
	class Solution {
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			if (!root) return NULL;
			if (root == p || root == q) return root;

			TreeNode* left = lowestCommonAncestor(root->left, p, q);
			TreeNode* right = lowestCommonAncestor(root->right, p, q);

			if (left && right) return root;
			return left ? left : right;
		}
	};

	void test() {

	}
}

