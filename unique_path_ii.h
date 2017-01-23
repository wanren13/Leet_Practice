#pragma once

#include "allhead.h"

namespace unique_path_ii {
	class Solution {
	public:
		int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
			if (obstacleGrid.empty()) return 0;

			int rows = obstacleGrid.size();
			int cols = obstacleGrid[0].size();

			if (obstacleGrid.front().front() == 1 || obstacleGrid.back().back() == 1) return 0;

			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < cols; c++) {
					obstacleGrid[r][c] = (obstacleGrid[r][c] - 1) * (-1);
					// cout << obstacleGrid[r][c] << " ";
				}
				// cout << endl;
			}

			// cout << "************************" << endl;

			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < cols; c++) {
					if (r == 0 && c == 0) continue;
					int prevRow = 0, prevCol = 0;
					if (r != 0) prevRow = obstacleGrid[r - 1][c];
					if (c != 0) prevCol = obstacleGrid[r][c - 1];
					obstacleGrid[r][c] = obstacleGrid[r][c] == 0 ? 0 : prevRow + prevCol;
					// cout << obstacleGrid[r][c] << " ";
				}
				// cout << endl;
			}

			return obstacleGrid[rows - 1][cols - 1];
		}
	};

	void test() {
		vector<vector<int>> obstacleGrid;
		obstacleGrid.emplace_back(vector<int>({ 0, 0 }));
		obstacleGrid.emplace_back(vector<int>({ 1, 0 }));
		Solution sol;
		cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
	}
}