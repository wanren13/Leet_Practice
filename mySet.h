#pragma once

#include "allhead.h"

namespace mySet {
	template <class T>
	struct TreeNode{
		T val;
		TreeNode* left, *right;
		TreeNode(T v) :val(v), left(NULL), right(NULL) {}
	};
	
	
	template<class T>
	class mySet {
	public:
		mySet() {
			root = NULL;
		}

		void insert(T val) {
			TreeNode<T>* newNode = new TreeNode<T>(val);
			if (root) {
				TreeNode<T>* curr = root;
				while (1) {
					if (curr->val == val) return;
					else if (curr->val > val) {
						if (curr->left) curr = curr->left;
						else {
							curr->left = newNode;
							return;
						}
					}
					else {
						if (curr->right) curr = curr->right;
						else {
							curr->right = newNode;
							return;
						}
					}
				}
			}
			else {
				root = newNode;
			}
		}

		TreeNode<T>* remove(T val) {
			TreeNode<T>* curr = root, *parent = root;
			TreeNode<T>* next = NULL;
			while (curr) {
				if (curr->val == val) {
					bool isleft = curr == parent->left;
					bool isright = curr == parent->right;
					if (curr->left && curr->right) {
						TreeNode<T>* smallest = curr->right;
						TreeNode<T>* smallestParent = curr->right;
						while (smallest && smallest->left) {
							smallestParent = smallest;
							smallest = smallest->left;
						}
						if (smallest) {
							curr->val = smallest->val;
							delete smallest;
							smallestParent->left = NULL;
							next = curr;
						}
						else {
							parent->right = curr->right;
							curr->right->left = curr->left;
							next = curr->right;
							delete curr;
						}

						break;
					}
					else {
						TreeNode<T>* child = (!curr->left && !curr->right) ? NULL :
							curr->left ? curr->left : curr->right;
						if (curr == parent->left) parent->left = child;
						else if (curr == parent->right)	parent->right = child;
						else root = child;
						next = child;
						delete curr;
						break;
					}
				}
				else {
					parent = curr;
					if (curr->val > val) curr = curr->left;
					else curr = curr->right;
				}
				
			}
			return next;
		}

		TreeNode<T>* find(T val) {
			TreeNode* curr = root;
			while (curr) {
				if (curr->val == val) break;
				else if (curr->val > val) curr->left;
				else curr->right;
			}
			return curr;
		}

		void printTree() {
			DFSprint(root);
			cout << endl;
		}

		void DFSprint(TreeNode<T>* r) {
			if (!r) return;
			DFSprint(r->left);
			cout << r->val << " ";
			DFSprint(r->right);
		}

		~mySet() {
			deleteTree(root);
			root = NULL;
			cout << "Three is deleted" << endl;
		}

	private:
		TreeNode<T>* root;
		void deleteTree(TreeNode<T>* root) {
			if (!root) return;
			deleteTree(root->left);
			deleteTree(root->right);
			delete root;
		}
	};



	void test() {

		{
			mySet<int> s;
			s.insert(3);
			s.printTree();
			cout << endl;
			s.insert(1);
			s.printTree();
			cout << endl;
			s.insert(2);
			s.printTree();
			cout << endl;
			s.insert(5);
			s.printTree();
			cout << endl;
			s.insert(4);
			s.printTree();
			cout << endl;
			s.insert(7);
			s.printTree();
			cout << endl;
			s.insert(6);
			s.printTree();
			cout << endl;

			TreeNode<int>* node = s.remove(5);
			cout << "New node is " << (node ? to_string(node->val) : "NULL") << endl;
			s.printTree();
		}

		cout << "Done" << endl;

	}
}