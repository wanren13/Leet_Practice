/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "allhead.h"

namespace lowest_common_ancestor_of_a_binary_search_tree {

	class Solution {
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			vector<TreeNode*> pv, qv;
			pv.emplace_back(root);
			qv.emplace_back(root);

			dfs(pv, root, p);
			dfs(qv, root, q);

			int i = 0;
			while (i < min(pv.size(), qv.size()) && pv[i] == qv[i]) i++;

			return pv[i - 1];
		}

		bool dfs(vector<TreeNode*>& v, TreeNode* root, TreeNode* target) {
			if (root == target) return true;
			if (root == NULL) return false;
			bool left = false, right = false;
			v.emplace_back(root->left);
			left = dfs(v, root->left, target);
			if (!left) v.pop_back();

			v.emplace_back(root->right);
			right = dfs(v, root->right, target);
			if (!right) v.pop_back();

			return left || right;

		}
	};

	void test() {
		TreeNode* root = new TreeNode(0);
		TreeNode* left = new TreeNode(1);
		TreeNode* right = new TreeNode(2);
		TreeNode* leftleft = new TreeNode(3);

		root->left = left;
		root->right = right;
		//left->right = right;
		left->left = leftleft;

		Solution sol;
		TreeNode* ans = sol.lowestCommonAncestor(root, right, leftleft);
		if (ans) cout << ans->val << endl;
		else cout << "NULL" << endl;
	}
};