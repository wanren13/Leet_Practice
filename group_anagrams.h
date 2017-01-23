#pragma once

#include "allhead.h"

namespace group_anagrams {
	class Solution {
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			unordered_map<int, vector<string>> m;
			for (string s : strs) {
				m[s.size()].emplace_back(s);
			}

			vector<vector<string>> res;
			for (unordered_map<int, vector<string>>::iterator miter = m.begin(); miter != m.end(); miter++) {
				vector<string>::iterator iter = (miter->second).begin();
				while (iter != strs.end()) {
					vector<string> group;
					group.emplace_back(*iter);
					vector<string>::iterator iter1 = iter + 1;
					while (iter1 != strs.end()) {
						if (isAnagram(*iter, *iter1)) {
							group.emplace_back(*iter1);
							iter1 = strs.erase(iter1);
						}
						else iter1++;
					}
					iter = strs.erase(iter);
					res.emplace_back(group);
				}
			}
			return res;
		}

		bool isAnagram(string s, string t) {
			int arr[26];
			for (int i = 0; i < 26; i++) arr[i] = 0;
			for (int i = 0; i < s.length(); i++) {
				arr[s[i] - 'a']++;
				arr[t[i] - 'a']--;
			}

			for (int i = 0; i < 26; i++) {
				if (arr[i]) return false;
			}

			return true;
		}
	};

	void test() {
		Solution sol;
		vector<string> strs(
		{ "eat", "tea", "tan", "ate", "nat", "bat" }
		);
		vector<vector<string>> res = sol.groupAnagrams(strs);

		for (auto v : res) {
			for (auto s : v)
				cout << s << " ";
			cout << endl;
		}
	}

}