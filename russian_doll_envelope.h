#pragma once

#include "allhead.h"

namespace russian_doll_envelop {
	class Solution {
	public:
		int maxEnvelopes(vector<pair<int, int>>& envelopes) {
			int w = 0, h = 0;
			for (auto p : envelopes) {
				w = max(w, p.first);
				h = max(h, p.second);
			}
			cout << w << "  " << h << endl;
			vector<vector<int>> m(h + 1, vector<int>(w + 1, 0));

			for (auto p : envelopes) m[p.second][p.first] = 1;

			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					cout << m[i][j] << " ";
				}
				cout << endl;
			}

			int maxnum = INT_MIN;
			for (int i = 1; i < h; i++) {
				for (int j = 1; j < w; j++) {
					m[i][j] += m[i - 1][j - 1];
					maxnum = max(maxnum, m[i][j]);
				}
			}


			// for (int i = 0; i < h; i++) {
			//     for (int j = 0; j < w; j++) {
			//         cout << m[i][j] << " ";
			//     }
			//     cout << endl;
			// }


			return maxnum;
		}
	};

	void test() {
		vector<pair<int,int>> envelopes(
		{ pair<int,int>(5,4), pair<int,int>(6,4), pair<int,int>(6,7), pair<int,int>(2,3)}
			);

		Solution sol;
		cout << sol.maxEnvelopes(envelopes) << endl;
	}
}