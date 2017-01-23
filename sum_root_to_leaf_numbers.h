#pragma once

#include "allhead.h"

namespace sum_root_to_leaf_numbers {
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
		int sumNumbers(TreeNode* root) {
			vector<int> nums;
			dfs(root, nums, 0);
			int sum = 0;
			for (int i : nums) sum += i;
			return sum;
		}

		void dfs(TreeNode* root, vector<int>& nums, int p) {
			if (!root || !(root->left && root->right)) nums.emplace_back(p);
			p = p * 10 + root->val;
			dfs(root->left, nums, p);
			dfs(root->right, nums, p);
		}
	};

	void test() {
		TreeNode* root = NULL;
		Solution sol;
		cout << sol.sumNumbers(root) << endl;
	}


}