#pragma once

#include "allhead.h"

namespace kth_smallest_element_in_a_BST {
	/**
	* Definition for a binary tree node.
	* struct TreeNode {
	*     int val;
	*     TreeNode *left;
	*     TreeNode *right;
	*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	* };
	*/
	// class Solution {
	// public:
	//     int kthSmallest(TreeNode* root, int k) {
	//         int K;
	//         find(root, k, K);
	//         return K;
	//     }

	//     void find (TreeNode* root, int k, int& K) {
	//         if(!root) return;
	//         find(root->left, k, K);
	//         if(n++ == k) {
	//             K = root->val;
	//             return;
	//         }
	//         else find(root->right, k, K);
	//     }

	//     int n = 1;
	// };

	// class Solution {
	// public:
	//     int kthSmallest(TreeNode* root, int k) {
	//         int K;
	//         find(root, k, K);
	//         return K;
	//     }

	//     void find (TreeNode* root, int& k, int& K) {
	//         if(!root) return;
	//         find(root->left, k, K);
	//         if(--k == 0) {
	//             K = root->val;
	//             return;
	//         }
	//         else find(root->right, k, K);
	//     }
	// };

	class Solution {
	public:
		int kthSmallest(TreeNode* root, int k) {
			int count = countNodes(root->left) + 1;
			while (count != k) {
				if (count < k) {
					root = root->right;
					count += 1 + countNodes(root->left);
				}
				else {
					root = root->left;
					count = 1 + countNodes(root->left);
				}
			}
			return root->val;
		}

		int countNodes(TreeNode* root) {
			if (!root) return 0;
			return 1 + countNodes(root->left) + countNodes(root->right);
		}
	};

	void test() {
		Solution sol;
		TreeNode* root = new TreeNode(1);
		root->right = new TreeNode(2);
		cout << sol.kthSmallest(root, 2) << endl;
	}
}