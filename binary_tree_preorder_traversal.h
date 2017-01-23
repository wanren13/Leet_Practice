#pragma once

#include "allhead.h"

namespace binary_tree_preorder_traversal {
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
	//     vector<int> preorderTraversal(TreeNode* root) {
	//         stack<TreeNode*> s;
	//         vector<int> res;
	//         if (root) {
	//             s.push(root);
	//             res.emplace_back(root->val);
	//         }
	//         while (!s.empty()) {
	//             while (s.top()->left) {
	//                 res.emplace_back(s.top()->left->val);
	//                 s.push(s.top()->left);
	//             }

	//             while (!s.empty() && !s.top()->right) s.pop();
	//             if (!s.empty()) {
	//                 res.emplace_back(s.top()->right->val);  
	//                 s.top() = s.top()->right;
	//             }
	//         }
	//         return res;
	//     }
	// };


	class Solution {
	public:
		vector<int> preorderTraversal(TreeNode* root) {
			stack<TreeNode*> s;
			vector<int> res;
			if (root) res.emplace_back(root->val);
			while (!s.empty()) {
				TreeNode* top = s.top();
				res.emplace_back(top->val);
				s.pop();
				if (top->right) s.push(top->right);
				if (top->left) s.push(top->left);
			}
			return res;
		}
	};


	void test() {
		string tree = "1,null,2,3";
		TreeNode* root = genTree(tree);
		Solution sol;
		vector<int> res = sol.preorderTraversal(root);
		for (int i : res) cout << i;
		cout << endl;
	}
}