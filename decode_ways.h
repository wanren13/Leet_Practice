#pragma once

#include "allhead.h" 

namespace decode_ways {
	class Solution {
	public:
		int numDecodings(string s) {
			int len = s.length();
			if (len == 0) return 0;
			if (s[0] - '0' < 1 || s[0] - '0' > 26) return 0;
			int res = 1;
			s.insert(0, "1");
			// cout << res << endl;
			for (int i = 2; i < len + 1; i++) {
				if (!isdigit(s[i])) return 0;
				int n1 = stoi(s.substr(i - 2, 2));
				int n2 = stoi(s.substr(i - 1, 2));
				if (n2 > 0 && n2 < 27) {
					if (s[i - 1] == '0') continue;
					if (n1 > 0 && n1 < 27) {
						if (s[i] != '0') res = res + res / 2;
						else res = res - res / 2;
					}
					else {
						if (s[i] != '0')
							res *= 2;
					}
				}
				else if (s[i] == '0') return 0;
				// cout << n1 << " "<< n2 << " "<< res << endl;
			}

			return res;
		}
	};

	void test() {
		Solution sol;
		string s = "11";
		cout << sol.numDecodings(s) << endl;
	}
}