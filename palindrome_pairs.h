#pragma once

#include "allhead.h"

namespace palindrome_pairs {
	//class Solution {
	//public:
	//	//vector<vector<int>> palindromePairs(vector<string>& words) {
	//	//	vector<vector<int>> res;
	//	//	unordered_map<string, int> dict;
	//	//	for (int i = 0; i < words.size(); i++) {
	//	//		string s = words[i];
	//	//		reverse(s.begin(), s.end());
	//	//		dict[s] = i;
	//	//	}

	//	//	for (int i = 0; i < words.size(); i++) {
	//	//		string s = words[i];

	//	//		for (int j = 0; j <= s.length(); j++) {
	//	//			string left = s.substr(0, j);
	//	//			string right = s.substr(j, s.length() - j);

	//	//			if (dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i) res.push_back({ i, dict[left] });
	//	//			if (!left.empty() && dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i) res.push_back({ dict[right], i });
	//	//		}
	//	//	}
	//	//	return res;
	//	//}


	//	vector<vector<int>> palindromePairs(vector<string>& words) {
	//		vector<vector<int>> res;
	//		Trie trie;
	//		for (int i = 0; i < words.size(); i++) {
	//			string s = words[i];
	//			reverse(s.begin(), s.end());
	//			trie.insert(s, i);
	//		}

	//		for (int i = 0; i < words.size(); i++) {
	//			string s = words[i];

	//			for (int j = 0; j <= s.length(); j++) {
	//				string left = s.substr(0, j);
	//				string right = s.substr(j, s.length() - j);

	//				int lIdx = trie.find(left), rIdx = trie.find(right);

	//				if (lIdx != -1 && isPalindrome(right) && lIdx != i) res.push_back({ i, lIdx });
	//				if (!left.empty() && rIdx != -1 && isPalindrome(left) && rIdx != i) res.push_back({ rIdx, i });
	//			}
	//		}
	//		return res;
	//	}

	//private:
	//	class Trie {
	//	public :
	//		Trie() { root = new TrieNode(); }
	//		void insert (const string& word, int idx) {
	//			TrieNode* curr = root, *child = NULL;
	//			for (char c : word) {
	//				if (curr->children.find(c) != curr->children.end()) child = curr->children[c];
	//				else {
	//					child = new TrieNode();
	//					curr->children[c] = child;
	//				}
	//				curr = child;
	//			}
	//			curr->idx = idx;
	//		}

	//		int find(const string& word) {
	//			TrieNode* curr = root;
	//			for (char c : word) {
	//				if (curr->children.find(c) != curr->children.end()) curr = curr->children[c];
	//				else return -1;
	//			}
	//			return curr->idx;
	//		}
	//	private:
	//		struct TrieNode {
	//			unordered_map<char, TrieNode*> children;
	//			int idx = -1;
	//		};
	//		TrieNode* root;
	//	};

	//	bool isPalindrome(const string& s) {
	//		int begin = 0, end = s.size() - 1;
	//		while (begin < end) if (s[begin++] != s[end--]) return false;
	//		return true;
	//	}
	//};
	class Solution {
	public:
		vector<vector<int>> palindromePairs(vector<string>& words) {
			vector<vector<int>> res;

			vector<string> revs = words;
			for (int i = 0; i < words.size(); i++) reverse(revs[i].begin(), revs[i].end());
			for (int i = 0; i < revs.size(); i++) {
				for (int j = 0; j < words.size(); j++) {
					string w1 = revs[i] + words[j];
					string w2 = words[j] + revs[i];
					if (isPalindrome(w1)) res.emplace_back(vector<int>({ i, j }));
					if (isPalindrome(w2)) res.emplace_back(vector<int>({ j, i }));
				}
			}

			return res;
		}

		bool isPalindrome(const string& str) {
			int begin = 0, end = str.length() - 1;
			while (begin < end) if (str[begin++] != str[end--]) return false;
			return true;
		}
	};

	void test() {
		vector<string> words({ "abcd","dcba","lls","s","sssll", "" });
		Solution sol;
		vector<vector<int>> res = sol.palindromePairs(words);
		for (auto v : res) cout << v[0] << " " << v[1] << endl;
	}
}