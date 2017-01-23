#pragma once

#include "allhead.h"

namespace remove_duplicate_letters {
	class Solution {
	public:
		string removeDuplicateLetters(string s) {
			int cnt[256] = { 0 };
			bool visited[256] = { 0 };
			string res; res += char(0);
			for (char c : s) cnt[c]++;
			for (char c : s) {
				cnt[c]--;
				if (visited[c]) continue;
				while (res.back() > c && cnt[res.back()]) {
					visited[res.back()] = false;
					res.pop_back();
				}
				res += c;
				visited[c] = true;
			}
			return res.substr(1);
		}
	};

	void test() {
		string s = 
		//	"bcabc";
			"mitnlruhznjfyzmtmfnstsxwktxlboxutbic";
		Solution sol;
		cout << sol.removeDuplicateLetters(s) << endl;
		/*string s;
		cout << s.back() << endl;*/
	}
}