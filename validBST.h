#pragma once

#include "allhead.h"

namespace validBST {
	//class Solution {
	//public:
	//	bool isValidBST(TreeNode* root) {
	//		toStack(root);
	//		int prev = INT_MIN, curr;
	//		while (!s.empty()) {
	//			TreeNode* node = s.top();
	//			s.pop();
	//			toStack(node->right);
	//			curr = node->val;
	//			if (curr <= prev) return false;
	//			prev = curr;
	//		}
	//		return true;
	//	}
	//private:
	//	stack<TreeNode*> s;
	//	void toStack(TreeNode* root) {
	//		while (root) {
	//			s.push(root);
	//			root = root->left;
	//		}
	//	}
	//};

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
		bool isValidBST(TreeNode* root) {
			TreeNode* prev = NULL;
			return inOrder(prev, root);
		}
		bool inOrder(TreeNode*& prev, TreeNode* curr) {
			if (!curr) return true;
			bool left = inOrder(prev, curr->left);
			bool mid = (prev ? prev->val < curr->val : true);
			prev = curr;
			bool right = inOrder(prev, curr->right);
			return left && mid && right;
		}
	};

	void test() {
		//string tree = "10,5,15,null,null,6,20";
		string tree = "2,1,3";
		// "-2147483648";
		TreeNode* root = genTree(tree);

		Solution s;
		cout << "Tree is " << (s.isValidBST(root) ? "" : "Not ") << "valid BST" << endl;
	}
}