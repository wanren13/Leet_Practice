#pragma once

#include "allhead.h"

namespace compare_version_numbers {
	class Solution {
	public:
		int compareVersion(string version1, string version2) {
			int i = 0, j = 0;
			while (i < version1.size() || j < version2.size()) {
				int v1 = 0, v2 = 0;
				while (i < version1.size()) {
					char c = version1[i++];
					if (c == '.') break;
					v1 = v1 * 10 + (c - '0');
				}
				while (j < version2.size()) {
					char c = version2[j++];
					if (c == '.') break;
					v2 = v2 * 10 + (c - '0');
				}
				if (v1 > v2) return 1;
				if (v2 > v1) return -1;
			}
			return 0;
		}
	};

	void test() {
		string version1 = "1.1";
		string version2 = "1.000000000000000000000010";
		Solution sol;
		cout << sol.compareVersion(version1, version2);
	}
}