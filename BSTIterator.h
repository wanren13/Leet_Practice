#pragma once

#include <iostream>
#include <stack>
#include "TreeNode.h"

using namespace std;

namespace BSTIterator {
	class BSTIterator {
	public:
		BSTIterator(TreeNode *root) {
			toStack(root);

			//inorder(root);
		}

		/** @return whether we have a next smallest number */
		bool hasNext() {
			return !s.empty();
		}

		/** @return the next smallest number */
		int next() {
			TreeNode* node = s.top();
			s.pop(); 
			toStack(node->right);
			return node->val;
		}
	private:
		void toStack(TreeNode* root) {
			while (root) {
				s.push(root);
				root = root->left;
			}
		}
		stack<TreeNode*> s;
	};


	void test() {

		string tree = "2,1,3";

		TreeNode* root = genTree(tree);

		BSTIterator i = BSTIterator(root);
		while (i.hasNext()) cout << i.next() << " ";
		cout << endl;
	}
}