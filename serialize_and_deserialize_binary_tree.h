#pragma once

#include "allhead.h"

namespace serialize_and_deserialize_binary_tree {
	/**
	* Definition for a binary tree node.
	* struct TreeNode {
	*     int val;
	*     TreeNode *left;
	*     TreeNode *right;
	*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	* };
	*/
	//class Codec {
	//public:

	//	// Encodes a tree to a single string.
	//	string serialize(TreeNode* root) {
	//		string res;
	//		queue<TreeNode*> curr;
	//		queue<TreeNode*> next;
	//		if (root) next.push(root);
	//		bool push = true;
	//		while (push) {
	//			curr = next;
	//			next = queue<TreeNode*>();
	//			push = false;
	//			while (!curr.empty()) {
	//				TreeNode* node = curr.front();
	//				curr.pop();
	//				if (node == nullptr) res += "null,";
	//				else {
	//					res += (to_string(node->val) + ",");
	//					push = push || node->left || node ->right;
	//					next.push(node->left);
	//					next.push(node->right);
	//				}
	//			}
	//		}
	//		if (!res.empty()) res.pop_back();
	//		return res;
	//	}

	//	// Decodes your encoded data to tree.
	//	TreeNode* deserialize(string data) {
	//		TreeNode* root = NULL;
	//		if (data.empty()) return root;
	//		queue<TreeNode*> q;
	//		char *str = new char[data.length() + 1];
	//		strcpy(str, data.c_str());
	//		char * token = strtok(str, ",");
	//		if (token && strcmp(token, "null")) root = new TreeNode(atoi(token));
	//		if (root) q.push(root);
	//		while (token) {
	//			TreeNode *leftChild = NULL, *rightChild = NULL;
	//			token = strtok(NULL, ",");
	//			if (token && strcmp(token, "null")) leftChild = new TreeNode(atoi(token));
	//			token = strtok(NULL, ",");
	//			if (token && strcmp(token, "null")) rightChild = new TreeNode(atoi(token));

	//			q.front()->left = leftChild;
	//			q.front()->right = rightChild;
	//			q.pop();
	//			if (leftChild) q.push(leftChild);
	//			if (rightChild) q.push(rightChild);
	//		}

	//		return root;
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
	class Codec {
	public:

		// Encodes a tree to a single string.
		string serialize(TreeNode* root) {
			queue<TreeNode*> q;
			q.push(root);
			string s;
			while (!q.empty()) {
				if (!q.front()) s += "# ";
				else {
					s += to_string(q.front()->val);
					q.push(q.front()->left);
					q.push(q.front()->right);
				}
				q.pop();
			}
			return s;
		}

		// Decodes your encoded data to tree.
		TreeNode* deserialize(string data) {
			istringstream is(data);
			string s;
			is >> s;
			TreeNode* root = s == "#" ? NULL : new TreeNode(stoi(s));
			queue<TreeNode*> q;
			q.push(root);
			int curr = 1, next = 0;
			while (!q.empty()) {
				if (q.front()) {
					TreeNode* node = NULL;
					for (int i = 0; i < 2; i++) {
						if (is >> s) {
							node = s == "#" ? NULL : new TreeNode(stoi(s));
							if (i == 0) q.front()->left = node;
							else q.front()->right = node;
							q.push(node);
						}
					}
				}
				q.pop();
			}

			return root;
		}
	};

	// Your Codec object will be instantiated and called as such:
	// Codec codec;
	// codec.deserialize(codec.serialize(root));

	void test() {
		Codec codec;
		string data = "-1 # 1 # 1 #";
			// "1,2,3,null,null,4,5";

		TreeNode* root = new TreeNode(9);
		root->right = new TreeNode(92);

		cout << codec.serialize(root) << endl;
		// cout << codec.serialize(codec.deserialize(data)) << endl;
		//istringstream is(data);
		//string n;
		//while (is >> n) cout << n << endl;


	}
}