#pragma once

#include "allhead.h"

namespace edit_distance {
	class Solution {
	public:
		int minDistance(string word1, string word2) {
			// int lcs = 0;
			// vector<int> v(word2.length() + 1, 0);
			// for (char c : word1) {
			//     int last = 0;
			//     for (int i = 0; i < word2.length(); i++) {
			//         int temp = v[i + 1];
			//         if (word2[i] == c) {
			//             v[i + 1] = last + 1;
			//             lcs = max(lcs, v[i + 1]);
			//         }
			//         else v[i + 1] = max(v[i + 1], v[i]);
			//         last = temp;
			//     }
			// }

			// lcs = abs(int(word2.length()) - int(word1.length())) + word2.length() - lcs;

			// return lcs;



			// string lcs;
			// vector<string> v(word2.length() + 1);
			// for (char c : word1) {
			//     string last;
			//     for (int i = 0; i < word2.length(); i++) {
			//         string t = v[i + 1];
			//         if (word2[i] == c) {
			//             swap(v[i + 1], last);
			//             v[i + 1] += c;
			//             if (v[i + 1].length() > lcs.length()) lcs = v[i + 1];
			//         }
			//         else if (v[i].length() > v[i + 1].length()) v[i + 1] = v[i];
			//         swap(last, t);
			//     }
			// }

			// cout << lcs << endl;
			// return lcs.length();

			struct point {
				int idx1 = -1, idx2 = -1;
			};
			int lcs = 0; point end;
			vector<point> p(word2.length() + 1);
			vector<int> v(word2.length() + 1, 0);

			for (int i = 0; i < word1.length(); i++) {
				int last = 0;
				point lp;
				for (int j = 0; j < word2.length(); j++) {
					int tmp = v[j + 1];
					point tp = p[j + 1];
					if (word1[i] == word2[j]) {
						v[j + 1] = last + 1;
						if (v[j + 1] > lcs) {
							lcs = v[j + 1];
							end.idx1 = i;
							end.idx2 = j;
						}
						if (tp.idx1 == -1) {
							p[j + 1].idx1 = end.idx1 = i;
							p[j + 1].idx2 = end.idx2 = j;
						}
						// else p[j + 1] = tp;
					}
					else if (v[j] > v[j + 1]) {
						v[j + 1] = v[j];
						p[j + 1] = p[j];
					}

					last = tmp;

				}
			}

			cout << p.back().idx1 << ", " << end.idx1 << endl;
			cout << p.back().idx2 << ", " << end.idx2 << endl;

			return lcs;

		}
	};

	void test() {
		string s1 = "abc";
		string s2 = "acd";
		Solution sol;
		cout << sol.minDistance(s1, s2) << endl;
	}
}