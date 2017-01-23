#pragma once

#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* newNode(string str) {
	if (str == "null") {
		return NULL;
	}
	else {
		return new TreeNode(stoi(str));
	}
}

TreeNode* genTree(string str) {
	if (str.empty()) {
		return NULL;
	}
	int start = 0;
	int end = 0;
	unsigned int i = 0;
	while (i < str.length() && str[i] != ',') i++;
	end = i;
	string val = str.substr(start, end - start);
	TreeNode* root = newNode(val);
	
	if (root != NULL) {
		queue<TreeNode*> q;
		q.push(root);
		while (i < (int)str.length()) {
			TreeNode* parent = q.front();
			q.pop();
			if (parent) {
				i++;
				start = i;
				while (i < str.length() && str[i] != ',') i++;
				end = i;
				string val = str.substr(start, end - start);
				TreeNode* leftchild = newNode(val);
				parent->left = leftchild;
				q.push(leftchild);
				if (i < str.length()) {
					i++;
					start = i;
					while (i < str.length() && str[i] != ',') i++;
					end = i;
					string val = str.substr(start, end - start);
					TreeNode* rightchild = newNode(val);
					parent->right = rightchild;
					q.push(rightchild);
				}
			}
		}
	}
	return root;
}