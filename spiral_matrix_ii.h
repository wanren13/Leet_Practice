#pragma once

#include "allhead.h"

namespace spiral_matrix_ii {
	class Solution {
	public:
		vector<vector<int>> generateMatrix(int n) {
			vector<vector<int>> res(n, vector<int>(n, 0));
			int max_num = n * n;
			int num = 1;

			int row = 0, col = -1, width = n, height = n;

			while (num <= max_num) {
				// to right
				for (int i1 = 0; i1 < width; i1++) {
					res[row][++col] = num++;
				}

				// to bottom
				height--;
				if (height == 0) break;
				for (int j1 = 0; j1 < height; j1++) {
					res[++row][col] = num++;
				}

				// to left
				width--;
				if (width == 0) break;
				for (int i2 = 0; i2 < width; i2++) {
					res[row][--col] = num++;
				}

				// to top
				height--;
				for (int j2 = 0; j2 < height; j2++) {
					res[--row][col] = num++;
				}

				width--;
			}

			return res;
		}
	};

	void test() {
		Solution sol;
		vector<vector<int>> matrix = sol.generateMatrix(1);

		for (auto v : matrix) {
			for (int i : v) {
				cout << i << " ";
			}
			cout << endl;
		}
	}
}