#pragma once

#include <iostream>
#include <queue>
#include <stack>

namespace binary_search_tree {
	using namespace std;

	template <class T>
	class Node {
	public:
		Node() :val(T()), left(NULL), right(NULL) {}
		Node(T v) :val(v), left(NULL), right(NULL) {}
		Node(T v, Node* l, Node* r) :val(v), left(l), right(r) {}
		T val;
		Node* left;
		Node* right;
	// private:
	//	friend ostream& operator<<(ostream& os, const Node*& node);
	};

	template <class T>
	ostream& operator<<(ostream& os, const Node<T>* node)
	{
		string str, val = "NULL", lval = "NULL", rval = "NULL";

		if (node) {
			val = to_string(node->val);
			if (node->left) {
				lval = to_string(node->left->val);
			}

			if (node->right) {
				rval = to_string(node->right->val);
			}
			str = "(" + val + ": [" + lval + ", " + rval + "])";
			os << str;
		}		
		return os;
	}


	template <class T>
	class BST {
	public:
		BST() :root(NULL) {}
		void newTree() {
			if (root == NULL) {
				root = new Node<T>();
			}
		}
		void newTree(T val) {
			if (root == NULL) {
				root = new Node<T>(val);
			}
		}
		void insert(T val) {
			Node<T>* curr = root;
			while (curr) {
				if (val >= curr->val) {
					if (curr->right) {
						curr = curr->right;
					}
					else {
						curr->right = new Node<T>(val);
						break;
					}
				}
				else {
					if (curr->left) {
						curr = curr->left;
					}
					else {
						curr->left = new Node<T>(val);
						break;
					}
				}
			}

		}
		bool search(T val) {
			Node<T>* curr = root;
			while (curr) {
				if (val == curr->val)
					return true;
				if (val >= curr->val) {
					curr = curr->right;
				}
				else {
					curr = curr->left;
				}
			}
			return false;
		}
		void printTree() {
			Node<T>* curr;
			queue<Node<T>*> q;
			q.push(root);

			while (1) {

				int levelcount = q.size();
				if (levelcount == 0) {
					break;
				}
				while (levelcount > 0) {
					curr = q.front();
					q.pop();
					cout << setw(3) << curr << " ";
					levelcount--;
					if (curr->left) {
						q.push(curr->left);
					}
					if (curr->right) {
						q.push(curr->right);
					}
				}
				cout << endl;
			}
		}


		void traverseTree(string type) {
			cout << type << ": " << endl;

			if (type == "preOrder")
				preOrder(root);
			if (type == "inOrder")
				inOrder(root);
			if (type == "postOrder")
				postOrder(root);
		}

		void preOder() {
			cout << "PreOrder Stack:" << endl;
			//Node<T>* curr;
			//stack<Node<T>*> s;
			//if (root)
			//	s.push(root);
			//while (!s.empty()) {
			//	curr = s.top();
			//	if (curr) {
			//		cout << curr << " ";
			//		curr = curr->left;
			//		s.push(curr);
			//	}
			//	else {
			//		s.pop();
			//		curr = s.top();
			//		while (!s.empty() && curr->right == NULL) {
			//			s.pop();
			//			if (!s.empty())
			//				curr = s.top();
			//		}
			//		if (curr->right) {
			//			curr = curr->right;
			//			// cout << curr << " ";
			//			s.pop();
			//			s.push(curr);
			//		}				
			//	}
			//}

			stack<Node<T>*> s;
			Node<T>* curr = root;
			s.push(curr);
			while (!s.empty()) {
				curr = s.top();
				s.pop();
				cout << curr << " ";
				if (curr->right)
					s.push(curr->right);
				if (curr->left)
					s.push(curr->left);
			}

			cout << endl;
		}

		void inOrder() {
			cout << "inOrder Stack:" << endl;
			Node<T>* curr;
			stack<Node<T>*> s;
			s.push(root);
			curr = root->left;
			while (s.size() > 0) {

				while (curr) {
					s.push(curr);
					if (curr->left)
						curr = curr->left;
					else
						break;
				}
				while (curr->right == NULL) {
					curr = s.top();
					cout << curr << " ";
					s.pop();
				}
				curr = curr->right;
			}
			cout << endl;
		}

		void postOrder() {
			cout << "PostOrder Stack:" << endl;
			cout << endl;
		}

		void dfs() {
			cout << "DFS" << endl;
			stack<Node<T>*> s;
			Node<T>* curr = root;
			s.push(curr);
			while (!s.empty()) {
				curr = s.top();
				s.pop();
				cout << curr << " ";
				if (curr->right)
					s.push(curr->right);
				if (curr->left)
					s.push(curr->left);
			}
			cout << endl;
		}

		void bfs() {
			cout << "BFS" << endl;
			queue<Node<T>*> q;
			Node<T>* curr = root;
			q.push(curr);
			while (!q.empty()) {
				curr = q.front();
				q.pop();
				cout << curr << " ";
				if (curr->left)
					q.push(curr->left);
				if (curr->right)
					q.push(curr->right);
			}
			cout << endl;
		}

		int findMaxDepth() {
			return depth(root, "max");
		}

		int findMinDepth() {
			return depth(root, "min");
		}

		~BST() {
			if (root) {
				deleteTree(root);
			}
		}
	private:
		Node<T>* root;

		void deleteTree(Node<T>* root) {
			if (root == NULL)
				return;
			deleteTree(root->left);
			deleteTree(root->right);
			delete root;
		}

		void preOrder(Node<T>* root) {
			if (root == NULL)
				return;
			cout << root << " ";
			preOrder(root->left);
			preOrder(root->right);
		}

		void inOrder(Node<T>* root) {
			if (root == NULL)
				return;
			inOrder(root->left);
			cout << root << " ";
			inOrder(root->right);
		}

		void postOrder(Node<T>* root) {
			if (root == NULL)
				return;
			postOrder(root->left);
			postOrder(root->right);
			cout << root << " ";
		}


		int depth(Node<T>* root, string conf) {
			if (root == NULL) {
				return 0;
			}
			else {
				int leftDepth = 1 + depth(root->left, conf);
				int rightDepth = 1 + depth(root->right, conf);
				if (conf == "max")
					return max(leftDepth, rightDepth);
				else
					return min(leftDepth, rightDepth);
			}
		}
	};


	void test() {
		BST<int> bTree;
		bTree.newTree(5);
		bTree.insert(1);
		bTree.insert(6);
		bTree.insert(9);
		bTree.insert(7);
		bTree.insert(3);
		bTree.insert(2);
		bTree.insert(4);
		bTree.insert(10);
		bTree.insert(11);
		bTree.insert(0);
		bTree.printTree();

		cout << (bTree.search(19) ? "Found" : "Not Found") << endl;
		cout << (bTree.search(4) ? "Found" : "Not found") << endl;
		cout << "Max depth is " << bTree.findMaxDepth() << endl;
		cout << "Min depth is " << bTree.findMinDepth() << endl;



		bTree.traverseTree("preOrder");
		cout << endl;
		bTree.traverseTree("inOrder");
		cout << endl;
		bTree.traverseTree("postOrder");
		cout << endl;

		bTree.preOder();
		bTree.inOrder();
		bTree.postOrder();

		bTree.dfs();
		bTree.bfs();
	
	}
}
