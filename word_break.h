#pragma once

#include "allhead.h"

namespace word_break {
	class Solution {
	public:
		bool wordBreak(string s, unordered_set<string>& wordDict) {
			// 		if (s.empty()) return true;
			// 		for (auto w : wordDict) {
			// 			int l = w.length();
			// 			if (w == s.substr(0, l) && wordBreak(s.substr(l), wordDict)) return true;
			// 		}
			// 		return false;

			vector<bool> v(s.length() + 1, false);
			v[0] = true;

			int longest = 0;
			for (auto w : wordDict) longest = max(longest, (int)w.length());

			for (int i = 0; i < s.length(); i++) {
				for (auto w : wordDict) {
					int start = i + 1 - w.length();
					if (start >= 0 && v[start] && wordDict.find(s.substr(start, w.length())) != wordDict.end()) {
						v[i] = true;
						break;
					}
				}
			}
			return v.back();
		}
	};

	void test() {
		string s =
			//"leetcode";
			"abcd";
		unordered_set<string> wordDict(
		// {"leet","code"}
		{"a", "abc","b","cd"}
		);
		Solution sol;
		cout << sol.wordBreak(s, wordDict) << endl;

	}
}