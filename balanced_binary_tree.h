#pragma once

#include "TreeNode.h"
#include <iostream>
#include <queue>

using namespace std;

namespace balanced_binary_tree {
	//class Solution {
	//public:
	//	bool isBalanced(TreeNode* root) {
	//		if (root == NULL)
	//			return true;
	//		// bool foundMin = false;
	//		// int numofElem;
	//		// int diff = 0;
	//		q.push(root);
	//		while (!q.empty()) {
	//			TreeNode* curr = q.front();
	//			q.pop();
	//			int leftdepth = depth(curr->left);
	//			int rightdepth = depth(curr->right);
	//			if (leftdepth - rightdepth > 1 || rightdepth - leftdepth > 1) {
	//				return false;
	//			}
	//			if (curr->left)  q.push(curr->left);
	//			if (curr->right) q.push(curr->right);
	//		}
	//		return true;
	//	}
	//private:
	//	int depth(TreeNode* root) {
	//		if (root == NULL) {
	//			return 0;
	//		}
	//		return 1 + max(depth(root->left), depth(root->right));
	//	}

	//	queue<TreeNode*> q;
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
		// bool isBalanced(TreeNode* root) {
		//     if (!root) return true;
		//     return ((root->left && root->right) || (!root->left && !root->right)) && isBalanced(root->left) && isBalanced(root->right);
		// }

		bool isBalanced(TreeNode* root) {
			// if (!root) return true;
			int l = INT_MIN, s = INT_MAX;
			path(root, 0, l, s);
			return l - s < 2;

		}

		void path(TreeNode* root, int count, int& l, int& s) {
			if (!root) {
				l = max(count, l);
				s = min(count, s);
			}
			else {
				path(root->left, count + 1, l, s);
				path(root->right, count + 1, l, s);
			}
		}
	};

	void test() {
		// string tree = "1,2,2,3,null,null,3,4,null,null,4";
		string tree = "1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5";
		TreeNode* root  = genTree(tree);

		Solution s;

		cout << "Tree is " << (s.isBalanced(root)?"":"not ") << "balanced" << endl;
	}
}