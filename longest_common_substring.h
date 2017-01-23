#pragma once

#include "allhead.h"

namespace longest_common_substring
{
	class Solution {
	public:
		int LCS (string& s1, string& s2){
			vector<int> cnt(s1.length() + 1);
			int maxlen = 0;
			for (int i = 0; i < s1.length(); i++) {
				for (int j = 0; j < s2.length(); j++) {
					if (s1[i] == s2[j]) {
						cnt[i + 1] = 1 + cnt[i];
						maxlen = max(maxlen, cnt[i + 1]);
					}
				}
			}
			return maxlen;
		}
	};

	void test() {
		string str1 = "abc";
		string str2 = "abcd";
		Solution sol;
		cout << sol.LCS(str1, str2) << endl;
	}
}