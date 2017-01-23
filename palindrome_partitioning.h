#pragma once

#include "allhead.h"

namespace palindrome_partitioning {
	class Solution {
	public:
		vector<vector<string>> partition(string s) {
			vector<vector<string>> res;
			vector<string> palindrome;
			backtrack(res, palindrome, 0, s);
			return res;
		}

		void backtrack(vector<vector<string>>& res, vector<string>& palindrome, int start, const string& s) {
			if (start == s.length()) {
				res.emplace_back(palindrome);
				return;
			}

			for (int i = 1; i <= s.length() - start; i++) {
				string t = s.substr(start, i);
				if (isPalindrome(t)) {
					palindrome.emplace_back(t);
					backtrack(res, palindrome, start + i, s);
					palindrome.pop_back();
				}
			}
		}

		bool isPalindrome(const string& s) {
			int i = 0, j = s.length() - 1;
			while (i < j) {
				if (s[i++] != s[j--]) return false;
			}
			return true;
		}
	};

	void test() {
		Solution sol;
		string s = "aab";
		vector<vector<string>> res = sol.partition(s);
		for (auto v : res) {
			for (auto str : v) {
				cout << str << " ";
			}
			cout << endl;
		}
	}
}