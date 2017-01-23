#pragma once

#include "allhead.h"

namespace construct_binary_tree_from_preorder_and_inorder_traversal {
	//class Solution {
	//public:
	//	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	//		return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	//	}

	//	TreeNode* create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
	//		if (ps > pe) {
	//			cout << "NULL" << endl;
	//			return nullptr;
	//		}
	//		TreeNode* node = new TreeNode(preorder[ps]);
	//		int pos;
	//		for (int i = is; i <= ie; i++) {
	//			if (inorder[i] == node->val) {
	//				pos = i;
	//				break;
	//			}
	//		}
	//		cout << "PS: " << ps << "   PE: " << pe << "   IS: " << is << "   IE: " << ie << "   POS: " << pos << "   NODE: " << node->val << endl;
	//		node->left = create(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
	//		node->right = create(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);
	//		return node;
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
		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			for (int i = 0; i < inorder.size(); i++) {
				idx[inorder[i]] = i;
			}

			return getRoot(preorder, inorder, 0, 0, (int)preorder.size() - 1);
		}



		TreeNode* getRoot(const vector<int>& preorder, const vector<int>& inorder, 
						int rid, int begin, int end) {
			if (begin > end) return NULL;
			TreeNode* root = new TreeNode(preorder[rid]);
			root->left = getRoot(preorder, inorder, rid + 1, 
				                 begin, idx[preorder[rid]] - 1);
			root->right = getRoot(preorder, inorder, rid + idx[preorder[rid]] - begin + 1, 
				                 idx[preorder[rid]] + 1, end);
			return root;
		}
		 
	private:
		unordered_map<int, int> idx;
	};

	void test() {
		Solution sol;
		vector<int> preorder(
		// { 1,2,4,5,3,6,7 }
		{7, 10, 4, 3, 1, 2, 8, 11}
		);
		vector<int> inorder(
		// { 4,2,5,1,6,3,7 }
		{4, 10, 3, 1, 7, 11, 8, 2}
		);
		TreeNode* root = sol.buildTree(preorder, inorder);
	}

}