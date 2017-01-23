#pragma once

#include "allhead.h"

namespace minimum_path_sum {
	class Solution {
	public:
		int minPathSum(vector<vector<int>>& grid) {
			int h = grid.size();
			if (h == 0) return 0;
			int w = grid[0].size();
			if (w == 0) return 0;
			vector<int> sums = grid[0];
			for (int c = 1; c < w; c++) sums[c] += sums[c - 1];

			for (int r = 1; r < h; r++) {
				sums[0] += grid[r - 1][0];
				for (int c = 1; c < w; c++) {
					sums[c] = min(sums[c - 1], sums[c]) + grid[r][c];
				}
			}
			return sums.back();
		}
	};

	void test() {
		vector<vector<int>> grid;
		grid.emplace_back(vector<int>({ 1,2,1 }));
		grid.emplace_back(vector<int>({ 3,2,4 }));
		grid.emplace_back(vector<int>({ 1,2,4 }));
		Solution sol;
		cout << sol.minPathSum(grid) << endl;
	}
}