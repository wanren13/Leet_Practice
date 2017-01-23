#pragma once

#include "allhead.h"

namespace sort_characters_by_frequency {
	class Solution {
	public:
		struct CF {
			char c;
			int freq;
			CF() : c(0), freq(0) {}
		};
		string frequencySort(string s) {
			CF cf[128];
			for (char c : s) {
				cf[c].c = c;
				cf[c].freq++;
			}
			sort(cf, cf + 128, [](const CF& l, const CF& r) -> bool {
				return l.freq > r.freq;
			});

			string res;
			for (int i = 0; i < 128; i++) {
				if (cf[i].c) {
					for (int j = 0; j < cf[i].freq; j++) {
						res += cf[i].c;
					}
				}
				else break;
			}

			return res;
		}
	};

	void test() {
		Solution sol;
		string s = "tree";
		string res = sol.frequencySort(s);
		cout << res << endl;
	}
}