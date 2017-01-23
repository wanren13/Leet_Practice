#pragma once

#include "allhead.h"

namespace word_break_ii {
	//class Solution {
	//public:
	//	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
	//		vector<vector<string>> res(s.length() + 1);
	//		vector<bool> v(s.length() + 1, false);
	//		v[0] = true;
	//		// res[0].emplace_back(string());
	//		// cout << res[0].size() << endl;
	//		for (int i = 1; i < v.size(); i++) {
	//			for (string w : wordDict) {
	//				int start = i - w.length();
	//				if (start >= 0 && v[start] && s.substr(start, w.length()) == w) {
	//					v[i] = true;
	//					if (start == 0) res[i].emplace_back(w);
	//					else for (auto last : res[start]) res[i].emplace_back(last + " " + w);
	//				}
	//			}
	//		}
	//		return res.back();
	//	}
	//};

	//class Solution {
	//public:
	//	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
	//		int max_len = 0;
	//		for (auto s : wordDict) max_len = max(max_len, (int)s.length());
	//		vector<string> res;
	//		string sentence;
	//		backtrack(res, sentence, s, wordDict, 0, max_len);
	//		return res;
	//	}

	//	void backtrack(vector<string>& res, string sentence, const string& s, const unordered_set<string>& wordDict, int start, const int& max_len) {
	//		if (start == s.length()) {
	//			res.emplace_back(sentence);
	//			return;
	//		}
	//		string ss = sentence;
	//		for (int i = 1; i <= max_len && start + i <= s.length(); i++) {
	//			string t = s.substr(start, i);
	//			if (wordDict.find(t) != wordDict.end()) {
	//				sentence += t;
	//				if (start + i != s.length()) sentence += " ";
	//				backtrack(res, sentence, s, wordDict, start + i, max_len);
	//				swap(sentence, ss);
	//			}
	//		}
	//	}
	//};



	//class Solution {
	//	unordered_map<string, vector<string>> m;

	//	vector<string> combine(string word, vector<string> prev) {
	//		for (int i = 0;i<prev.size();++i) {
	//			prev[i] += " " + word;
	//		}
	//		return prev;
	//	}

	//public:
	//	vector<string> wordBreak(string s, unordered_set<string>& dict) {
	//		if (m.count(s)) return m[s]; //take from memory
	//		vector<string> result;
	//		if (dict.count(s)) { //a whole string is a word
	//			result.push_back(s);
	//		}
	//		for (int i = 1;i<s.size();++i) {
	//			string word = s.substr(i);
	//			if (dict.count(word)) {
	//				string rem = s.substr(0, i);
	//				vector<string> prev = combine(word, wordBreak(rem, dict));
	//				result.insert(result.end(), prev.begin(), prev.end());
	//			}
	//		}
	//		m[s] = result; //memorize
	//		return result;
	//	}
	//};


	class Solution {
	public:
		vector<string> wordBreak(string s, vector<string>& wordDict) {
			vector<string> res;
			vector<vector<vector<int>>> idx(s.length() + 1);
			vector<vector<int>> t;
			t.emplace_back(vector<int>{0});
			idx[0] = t;
			for (int i = 0; i < s.length(); i++) {
				if (!idx[i].empty()) {
					for (string str : wordDict) {
						int len = str.length();
						if (i + len <= s.length() && s.substr(i, len) == str) {
							for (auto v : idx[i]) {
								idx[i + len].emplace_back(v);
								idx[i + len].back().emplace_back(i + len);
							}
						}
					}
				}
			}

			for (auto v : idx.back()) {
				string str;
				for (int i = 1; i < v.size(); i++) {
					if (!str.empty()) str += " ";
					str += s.substr(v[i - 1], v[i] - v[i - 1]);
				}
				res.emplace_back(str);
			}

			return res;
		}
	};
	void test() {
		// string s = " aaa"; 
		string s = "catsanddog";
		// unordered_set<string> wordDict(
		// {"aaa", "aa", "a"}
		// { "cat", "cats", "and", "sand", "dog" }
		// );

		vector<string> wordDict(
			// {"aaa", "aa", "a"}
		{ "cat", "cats", "and", "sand", "dog" }
		);
		Solution sol;
		vector<string> res = sol.wordBreak(s, wordDict);
		for (auto s : res) cout << s << endl;

	}
}