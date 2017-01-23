#pragma once

#include "allhead.h"

namespace substring_with_concatenation_of_all_words {
	class Solution {
	public:
		vector<int> findSubstring(string s, vector<string>& words) {
			vector<int> res;
			if (words.empty() || s.empty()) return res;
			int len = words[0].length(), n = words.size();
			unordered_map<string, int> dict;
			for (string str : words) dict[str]++;

			for (int i = 0; i <= (int)s.length() - n * len; i++) {
				unordered_map<string, int> m;
				for (int j = 0; j < n; j++) {
					string str = s.substr(i + j * len, len);
					if (++m[str] > dict[str]) goto next;
				}
				res.emplace_back(i);
				next: continue;
			}

			return res;
		}
	};


	//class Solution {
	//public:
	//	vector<int> findSubstring(string s, vector<string>& words) {
	//		vector<int> res;
	//		if (words.empty()) return res;

	//		unordered_map<string, int> dict;
	//		for (string s : words) dict[s]++;

	//		int cnt = 0, i = 0, len = words[0].length();
	//		unordered_map<string, int> m;

	//		while (i < s.length() + 1 - len * cnt) {
	//			m = dict;
	//			cnt = words.size();
	//			int j = i;
	//			while (cnt > 0) {
	//				string str = s.substr(j, len);
	//				if (m.find(str) != m.end()) {
	//					if (m[str]-- > 0) cnt--;
	//					else break;
	//				}
	//				else break;
	//				j += len;
	//			}

	//			if (cnt == 0) res.emplace_back(i);
	//			i++;
	//		}

	//		return res;
	//	}
	//};


	void test() {
		Solution sol;

		string s = // "wordgoodgoodgoodbestword";
			"barbarbarbarfoothefoobarbarman";
		vector<string> words(
		{ "bar" } 
		//{ "word", "good", "best", "good" }
		);
		vector<int> res = sol.findSubstring(s, words);
		for (int i : res) cout << i << " ";
		cout << endl;
	}
}