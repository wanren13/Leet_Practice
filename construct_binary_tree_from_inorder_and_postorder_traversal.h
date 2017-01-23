#pragma once

#include "allhead.h"

namespace construct_binary_tree_from_inorder_and_postorder_traversal {
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
		//TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		//	for (int i = 0; i < inorder.size(); i++) {
		//		idx[inorder[i]] = i;
		//	}
		//	return listToTree(postorder, postorder.size() - 1, 0, int(postorder.size()) - 1);
		//}

		//TreeNode* listToTree(const vector<int>& postorder, int rid, int begin, int end) {
		//	if (begin > end) return NULL;
		//	TreeNode* root = new TreeNode(postorder[rid]);
		//	root->left = listToTree(postorder, rid - (end - idx[postorder[rid]]) - 1), begin, idx[postorder[rid]] - 1));
		//	root->right = listToTree(postorder, rid - 1, idx[postorder[rid]] + 1, end);
		//	return root;
		//}

	private:
		unordered_map<int, int> idx;
	};

	void test() {
		//vector<int> inorder({ 4,10,3,1,7,11,8,2 });
		//vector<int> postorder({ 4,1,3,10,11,8,2,7 });
		//Solution sol;
		//TreeNode* root = sol.buildTree(inorder, postorder);
	}
}