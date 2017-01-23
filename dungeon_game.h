#pragma once

#include "allhead.h"

namespace dungeon_game {
	class Solution {
	public:
		int calculateMinimumHP(vector<vector<int>>& dungeon) {
			int h = dungeon.size(), w = dungeon[0].size();
			vector<int> minhp = dungeon[0];
			vector<int> hp = dungeon[0];

			for (int c = 1; c < w; c++) {
				hp[c] += hp[c - 1];
				minhp[c] = min(hp[c], minhp[c - 1]);
			}

			for (int r = 1; r < h; r++) {
				hp[0] += dungeon[r][0];
				minhp[0] = min(hp[0], minhp[0]);
				for (int c = 1; c < w; c++) {
					if (minhp[c - 1] < minhp[c]) {
						hp[c] += dungeon[r][c];
						minhp[c] = min(minhp[c], hp[c]);
					}
					else {
						hp[c] = hp[c - 1] + dungeon[r][c];
						minhp[c] = min(minhp[c - 1], hp[c]);
					}
				}
			}

			return 1 - min(minhp.back(), 0);
		}
	};

	void test() {
		vector<vector<int>> dungeon;
		dungeon.emplace_back(vector<int>(
		// { -2, -3, 3 }
		{1, -3, 3}
		));
		dungeon.emplace_back(vector<int>(
		// { -5, -10, 1 }
		{0, -2, 0}
		));
		dungeon.emplace_back(vector<int>(
		//{ 10, 30, -5 }
		{-3,-3,-3}
		));			

		Solution sol;
		cout << sol.calculateMinimumHP(dungeon) << endl;
	}
}