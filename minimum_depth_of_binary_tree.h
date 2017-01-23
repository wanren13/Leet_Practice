#pragma once

#include "allhead.h"

namespace minimum_depth_of_binary_tree {
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
		int minDepth(TreeNode* root) {
			if (!root) return 0;
			// else if (!root->left && !root->right)
			return min(minDepth(root->left), minDepth(root->right)) + 1;
		}
	};

	void test() {
		string tree = "1,2,2,3,3,null,3,null,null,4,null,null,4";
		TreeNode* root = genTree(tree);
		
		Solution sol;
		cout << sol.minDepth(root) << endl;

	}
}