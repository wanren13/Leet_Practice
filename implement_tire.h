#pragma once

#include "allhead.h" 

namespace implement_tire {

	class TrieNode {
	public:
		// Initialize your data structure here.
		TrieNode *next[26] = { 0 };
		bool t = false;
		TrieNode() {}
	};

	class Trie {
	public:
		Trie() {
			root = new TrieNode();
		}

		// Inserts a word into the trie.
		void insert(string word) {
			TrieNode *curr = root;
			for (char c : word) {
				int i = c - 'a';
				if (!curr->next[i]) curr->next[i] = new TrieNode();
				curr = curr->next[i];
			}
			curr->t = true;
		}

		// Returns if the word is in the trie.
		bool search(string word) {
			TrieNode *curr = root;
			for (char c : word) {
				int i = c - 'a';
				curr = curr->next[i];
				if (!curr) return false;
			}

			return curr->t;
		}

		// Returns if there is any word in the trie
		// that starts with the given prefix.
		bool startsWith(string prefix) {
			TrieNode *curr = root;
			for (char c : prefix) {
				int i = c - 'a';
				curr = curr->next[i];
				if (!curr) return false;
			}

			return true;
		}

	private:
		TrieNode* root;
	};

	// Your Trie object will be instantiated and called as such:
	// Trie trie;
	// trie.insert("somestring");
	// trie.search("key");
	
//	class TrieNode {
//	public:
//		// Initialize your data structure here.
//		TrieNode* children[26] = { 0 };
//		bool eow;
//		int used;
//		TrieNode() : eow(false), used(0) {
//		}
//	};
//
//	class Trie {
//	public:
//		Trie() { 
//			root = new TrieNode();
//		}
//
//		// Inserts a word into the trie.
//		void insert(string word) {
//			TrieNode* curr = root, *next = NULL;
//			for (char c : word) {
//				next = curr->children[c - 'a'];
//				if (!next) {
//					next = new TrieNode();
//					curr->children[c - 'a'] = next;
//				}
//				curr->used++;
//				curr = next;
//			}
//			next->eow = true;
//		}
//
//		void delword(string word) {
//			delUtil(root, word, 0);
//		}
//
//		void delUtil(TrieNode* root, string word, int i) {
//			TrieNode* child = root->children[word[i] - 'a'];
//			root->used--;
//			if (i + 1 < word.length()) delUtil(child, word, i + 1);
//			if (child->used == 0) {
//				if (root->used != 0) child->eow = true;
//				else {
//					delete child;
//					root->children[word[i] - 'a'] = NULL;
//				}
//			}
//			else if (child->eow && i == word.length() - 1) child->eow = false;			
//		}
//
//
//		//void delUtil(TrieNode* root, string word, int i) {
//		//	TrieNode* child = root->children[word[i] - 'a'];
//		//	root->used--;
//		//	if (i + 1 < word.length()) delUtil(child, word, i + 1);
//		//	if (child->used == 0) {
//		//		if (root->used != 0) child->eow = true;
//		//		else {
//		//			delete child;
//		//			root->children[word[i] - 'a'] = NULL;
//		//		}
//		//	}
//		//	else child->eow = false;
//		//}
//
//		// Returns if the word is in the trie.
//		bool search(string word) {
//			TrieNode* curr = root, *next = NULL;
//			for (char c : word) {
//				next = curr->children[c - 'a'];
//				if (!next) return false;
//				curr = next;
//			}
//			return curr->eow;
//		}
//
//		// Returns if there is any word in the trie
//		// that starts with the given prefix.
//		bool startsWith(string prefix) {
//			TrieNode* curr = root, *next = NULL;
//			for (char c : prefix) {
//				next = curr->children[c - 'a'];
//				if (!next) return false;
//				curr = next;
//			}
//			return true;
//		}
//
//	private:
//		TrieNode* root;
};

	// Your Trie object will be instantiated and called as such:
	// Trie trie;
	// trie.insert("somestring");
	// trie.search("key");

	void test() {
		Trie trie;
		string word = "abc";
		string word1 = "ab";
		string prefix = "a";
		trie.insert(word);
		trie.insert(word1);
		cout << trie.search(word) << endl;
		cout << trie.search(word1) << endl;
		cout << trie.search(prefix) << endl;;
		cout << trie.startsWith(prefix) << endl;

		trie.delword(word);
		cout << trie.search(word) << endl;
		cout << trie.search(word1) << endl;
		cout << trie.startsWith(prefix) << endl;

	}
}