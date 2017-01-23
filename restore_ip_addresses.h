#pragma once

#include "allhead.h"

namespace restore_ip_addresses {
	class Solution {
	public:
		vector<string> restoreIpAddresses(string s) {
			vector<string> res;
			int len = s.length();
			for (int i = 1; i < 4 && i < len - 2; i++) {
				for (int j = 1; j < 4 && i + j < len - 1; j++) {
					for (int k = 1; k < 4 && i + j + k < len; k++) {
						if (isValid(s, 0, i) && isValid(s, i, j) && isValid(s, i + j, k) && isValid(s, i + j + k, len - i - j - k)) {
							res.emplace_back(s.substr(0, i) + ',' + s.substr(i, j) + ',' + s.substr(i + j, k) + ',' + s.substr(i + j + k, len - i - j - k));
						}
					}
				}
			}

			return res;
		}

		bool isValid(const string& s, int begin, int len) {
			if (len > 3 || (len > 1 && s[begin] == '0')) return false;
			int n = stoi(s.substr(begin, len));
			return n >= 0 && n <= 255;
		}
	};

	void test() {
		string s = "0000";
		Solution sol;
		vector<string> res = sol.restoreIpAddresses(s);
		for (auto s : res) {
			cout << s << endl;
		}
	}
}