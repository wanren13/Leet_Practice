#pragma once

#include "allhead.h"

namespace house_robber_iii {
	//struct TreeNode {
	//	int val;
	//	TreeNode *left;
	//	TreeNode *right;
	//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	//};
	//
	//class Solution {
	//public:
	//	int rob(TreeNode* root) {
	//		if (root == NULL) {
	//			return 0;
	//		}

	//		//int l = rob(root->left);
	//		//int r = rob(root->right);
	//		//int val = root->val + max(l, r);

	//		// return val;





	//		int l = 0, r = 0, ll = 0, lr = 0, rl = 0, rr = 0;
	//		int val = root->val;

	//		l = rob(root->left);
	//		r = rob(root->right);
	//		if (root->left) {
	//			ll = rob(root->left->left);
	//			lr = rob(root->left->right);
	//		}
	//		if (root->right) {
	//			rl = rob(root->right->left);
	//			rr = rob(root->right->right);
	//		}

	//		return max(val + ll + lr + rl + rr, l + r);

	//		// int val = root->val;
	//		// int lval = root->left->val;
	//		// int rval = root->right->val;

	//		// if (val > lval + rval) {
	//		//     int ll = 0, lr = 0, rl = 0, rr = 0;
	//		//     if (root->left) {
	//		//         ll = rob(root->left->left);
	//		//         lr = rob(root->left->right);
	//		//     }
	//		//     if (root->right) {
	//		//         rl = rob(root->right->left);
	//		//         rr = rob(root->right->right);
	//		//     }


	//		//     return val + max(rob(root->left), rob(root->right));
	//		// }
	//		// else {
	//		//     return lval + rval + max(rob(root->left), rob(root->right)); 
	//		// }





	//	}
	//};


	class Solution {
	public:
		int rob(TreeNode* root) {
			if (!root) return 0;
			int self = root->val + children(root->left) + children(root->right);
			int chd = children(root);

			return max(self, chd);
		}

		int children(TreeNode* root) {
			if (!root) return 0;
			int res = (root->left ? root->left->val : 0) + (root->right ? root->right->val : 0);
			return res;
		}
	};

	void test() {
		//TreeNode* root = new TreeNode(3);
		//root->left = new TreeNode(2);
		//root->right = new TreeNode(3);
		//root->left->right = new TreeNode(3);
		//root->right->right = new TreeNode(1);


		/*root->left = new TreeNode(4);
		root->right = new TreeNode(5);
		root->left->left = new TreeNode(1);
		root->left->right = new TreeNode(3);
		root->right->right = new TreeNode(1);*/


		//TreeNode* root = new TreeNode(3);
		//root->left = new TreeNode(4);
		//root->right = new TreeNode(5);
		//root->left->right = new TreeNode(1);
		//root->left->right = new TreeNode(3);
		//root->right->right = new TreeNode(1);


		TreeNode* root = new TreeNode(4);
		root->left = new TreeNode(1);
		root->right = new TreeNode(2);
		root->left->right = new TreeNode(3);


		Solution s;
		cout << s.rob(root) << endl;
	}
}