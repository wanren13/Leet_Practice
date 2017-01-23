#pragma once

#include "allhead.h"

namespace word_search_ii {
	
	class Solution {
	public:
		vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
			vector<string> ans;
			int h = board.size();
			if (h == 0) return ans;
			int w = board[0].size();

			// create trie dict for words
			trieRoot = new TrieNode();

			// insert words
			for (string word : words) {
				TrieNode* curr = trieRoot;
				for (char c : word) {
					TrieNode* child = curr->children[c - 'a'];
					if (!child) {
						child = new TrieNode();
						curr->children[c - 'a'] = child;
					}
					curr->numofchildren++;
					curr = child;
				}
				curr->EOW = true;
			}

			for (int r = 0; r < h; r++) {
				for (int c = 0; c < w; c++) {
					unordered_set<string> wordset;
					dfs(wordset, board, "", trieRoot, r, c, h, w);
					copy(wordset.begin(), wordset.end(), back_inserter(ans));
					for (string s : wordset) deleteWord(s);
				}
			}

			//deleteWord("oath");
			//deleteWord("oath");

			return ans;
		}
	private:
		struct TrieNode {
			TrieNode* children[26] = { 0 };
			int numofchildren = 0;
			bool EOW = false;
		};
		TrieNode* trieRoot;
		void delHelper(TrieNode* root, const string& word, int idx) {
			if (root == nullptr) return;
			TrieNode* child = root->children[word[idx] - 'a'];
			root->numofchildren--;
			if (idx + 1 < word.length()) delHelper(child, word, idx + 1);
			else child->EOW = false;
			if (child && child->numofchildren == 0 && !child->EOW) {
				delete child;
				root->children[word[idx] - 'a'] = NULL;
			}
		}

		void deleteWord(const string& word) {
			delHelper(trieRoot, word, 0);
		}

		void dfs(unordered_set<string>& ans, vector<vector<char>>& board, string word, TrieNode* root, int r, int c, int h, int w) {
			if (r < 0 || c < 0 || r == h || c == w || root == nullptr) return;
			
			char sc = board[r][c];
			if (sc == '#') return;
			board[r][c] = '#';

			word += sc;
			int idx = sc - 'a';

			TrieNode* child = root->children[idx];
			if (child && child->EOW) ans.insert(word);
			
			dfs(ans, board, word, child, r - 1, c, h, w); // up
			dfs(ans, board, word, child, r + 1, c, h, w); // down
			dfs(ans, board, word, child, r, c - 1, h, w); // left
			dfs(ans, board, word, child, r, c + 1, h, w); // right

			board[r][c] = sc;
		}
	};
	
	/*

	class Solution {
	public:
		vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
			vector<string> ans;
			int h = board.size();
			if (h == 0) return ans;
			int w = board[0].size();
			
			
			// create trie dict for words
			trieRoot = new TrieNode();

			// insert words
			for (string word : words) {
				TrieNode* curr = trieRoot;
				for (char c : word) {
					TrieNode* child = curr->children[c - 'a'];
					if (!child) {
						child = new TrieNode();
						curr->children[c - 'a'] = child;
					}
					curr->numofchildren++;
					curr = child;
				}
				curr->EOW = true;
			}

			for (int r = 0; r < h; r++) {
				for (int c = 0; c < w; c++) {
					string word;
					dfs(ans, board, word, &trieRoot, r, c, h, w);
				}
			}

			//deleteWord("oath");
			//deleteWord("oath");

			return ans;
		}
	private:
		struct TrieNode {
			TrieNode* children[26] = { 0 };
			int numofchildren = 0;
			bool EOW = false;
		};
		TrieNode* trieRoot;
		void delHelper(TrieNode* root, const string& word, int idx) {
			if (root == nullptr) return;
			TrieNode* child = root->children[word[idx] - 'a'];
			root->numofchildren--;
			if (idx + 1 < word.length()) delHelper(child, word, idx + 1);
			else child->EOW = false;
			if (child && child->numofchildren == 0 && !child->EOW) {
				delete child;
				root->children[word[idx] - 'a'] = NULL;
			}
		}

		void deleteWord(const string& word) {
			delHelper(trieRoot, word, 0);
		}

		int cnt = 0;

		void dfs(vector<string>& ans, vector<vector<char>>& board, string word, TrieNode** root, int r, int c, int h, int w) {
			cnt++;

			if (r < 0 || c < 0 || r == h || c == w || *root == nullptr) return;

			if ((*root)->EOW) {
				ans.emplace_back(word);
				deleteWord(word);
			}

			char sc = board[r][c];
			if (sc == '#') return;
			board[r][c] = '#';

			word += sc;
			int idx = sc - 'a';

			if (*root) dfs(ans, board, word, &(*root)->children[idx], r - 1, c, h, w); // up
			if (*root) dfs(ans, board, word, &(*root)->children[idx], r + 1, c, h, w); // down
			if (*root) dfs(ans, board, word, &(*root)->children[idx], r, c - 1, h, w); // left
			if (*root) dfs(ans, board, word, &(*root)->children[idx], r, c + 1, h, w); // right


			board[r][c] = sc;
		}		
	};
	*/
	void test() {
		//vector<string> words({ "oath", "pea", "eat", "rain" }); 
		//vector<vector<char>> board;
		//board.emplace_back(vector<char>({ 'o', 'a', 'a', 'n' }));
		//board.emplace_back(vector<char>({ 'e', 't', 'a', 'e' }));
		//board.emplace_back(vector<char>({ 'i', 'h', 'k', 'r' }));
		//board.emplace_back(vector<char>({ 'i', 'f', 'l', 'v' }));

		vector<string> words({ "a" });
		vector<vector<char>> board;
		board.emplace_back(vector<char>({ 'a'}));
		Solution sol;
		vector<string> res = sol.findWords(board, words);

		for (string str : res) cout << str << " ";
		cout << endl;


		//int* t = new int(5);
		//int** pt = &t;
		//delete t;
		//t = NULL;
		//cout << "Hello" << endl;
	}
}