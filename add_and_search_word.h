#pragma once

#include "allhead.h"

namespace add_and_search_word {
	//class WordDictionary {
	//public:
	//	// Adds a word into the data structure.
	//	void addWord(string word) {
	//		trie.addWord(word);
	//	}

	//	// Returns if the word is in the data structure. A word could
	//	// contain the dot character '.' to represent any one letter.
	//	bool search(string word) {
	//		return trie.search(word);
	//	}
	//private:
	//	class Trie {
	//	public:
	//		Trie() {
	//			root = new TrieNode();
	//		}

	//		void addWord(string word) {
	//			TrieNode* curr = root;
	//			for (char c : word) {
	//				TrieNode* child = curr->children[c - 'a'];
	//				if (!child) {
	//					child = new TrieNode();
	//					curr->children[c - 'a'] = child;
	//				}
	//				curr->cnt++;
	//				curr = child;
	//			}
	//			curr->endOfWord = true;
	//		}

	//		bool search(string word) {
	//			if (root == NULL) return false;
	//			return searchHelper(root, word, 0);
	//		}

	//	private:
	//		struct TrieNode{
	//			TrieNode* children[26] = { 0 };
	//			bool endOfWord;
	//			int cnt;
	//			TrieNode() : endOfWord(false), cnt(0) {}
	//		};
	//		TrieNode* root;

	//		bool searchHelper(TrieNode* root, string word, int i) {
	//			char c = word[i];
	//			bool found = false;
	//			if (i == word.length() - 1) {
	//				if (root->cnt == 0) return false;
	//				if (c == '.') {
	//					bool eow = false;
	//					for (auto child : root->children) {
	//						if (child) eow = eow || child->endOfWord;
	//					}
	//					return eow;
	//				}
	//				else return (root->children[c - 'a'] != NULL) && root->children[c - 'a']->endOfWord;
	//			}
	//			else {
	//				bool ans = false;
	//				if (c == '.' && root->cnt != 0) {
	//					for (auto child : root->children) {
	//						if (child && searchHelper(child, word, i + 1))
	//							return true;
	//					}
	//				}
	//				else {
	//					TrieNode* child = root->children[c - 'a'];
	//					ans = (child != NULL) && searchHelper(child, word, i + 1);
	//				}
	//				return ans;
	//			}
	//		}

	//	};
	//	Trie trie;
	//};

	class WordDictionary {
	public:
		WordDictionary() {
			root = new TrieNode();
		}

		// Adds a word into the data structure.
		void addWord(string word) {
			TrieNode* curr = root;
			for (char c : word) {
				if (curr->next.find(c) == curr->next.end()) curr->next[c] = new TrieNode();
				curr = curr->next[c];
			}
			curr->t = true;
		}

		// Returns if the word is in the data structure. A word could
		// contain the dot character '.' to represent any one letter.
		bool search(string word) {
			TrieNode* curr = root;
			return dfs(curr, word, 0);
		}


	private:
		struct TrieNode {
			unordered_map<char, TrieNode*> next;
			bool t = false;
			TrieNode() {}
		};
		TrieNode *root;

		bool dfs(TrieNode* curr, const string& word, int i) {
			if (i == word.length()) return curr->t;
			char c = word[i];
			if (!curr->next.empty()) {
				if (c == '.') {
					for (auto n : curr->next) {
						if (dfs(n.second, word, i + 1)) return true;
					}
				}
				else if (curr->next.find(c) != curr->next.end()) {
					return dfs(curr->next[c], word, i + 1);
				}
			}
			return false;
		}
	};

	// Your WordDictionary object will be instantiated and called as such:
	// WordDictionary wordDictionary;
	// wordDictionary.addWord("word");
	// wordDictionary.search("pattern");



	void test() {
		WordDictionary worddict;
		worddict.addWord("a");
		worddict.addWord("ab"); 
		cout << worddict.search("a");
		cout << worddict.search("a.");
		cout << worddict.search("ab");
		cout << worddict.search(".a");
		cout << worddict.search(".b");
		cout << worddict.search("ab.");
		cout << worddict.search(".");
		cout << worddict.search("..");
		 //cout << worddict.search(word1) << endl;
	}
}