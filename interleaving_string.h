#pragma once

#include "allhead.h"

namespace interleaving_string {
	class Solution {
	public:
		bool isInterleave(string s1, string s2, string s3) {
			if (s1.length() + s2.length() != s3.length()) return false;
			int i1 = 0, i2 = 0, i3 = 0;
			while (i3 != s3.length()) {
				if (s1[i1] == s3[i3]) {
					i1++;
					i3++;
				}
				else if (s2[i2] == s3[i3]) {
					i2++;
					i3++;
				}
				else return false;
			}

			return true;
		}
	};

	void test() {
		string s1 = "aabcc";
		string s2 = "dbbca";
		string s3 = "aadbbcbcac";
		//"aadbbbaccc";
		Solution sol;
		cout << sol.isInterleave(s1, s2, s3) << endl;
	}
}