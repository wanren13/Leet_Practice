#pragma once

#include "allhead.h"

namespace maximum_submatrix {
	class Solution {
	public:
		int maxSum(vector<vector<int>> matrix) {
			if (matrix.empty()) return INT_MIN;
			int height = matrix.size();
			int width = matrix[0].size();

			// calculate accumulative sum for each column
			for (int r = 1; r < height; r++) {
				for (int c = 0; c < width; c++) {
					matrix[r][c] = matrix[r][c] + matrix[r - 1][c];
				}
			}

			int max_val = matrix[0][0];

			for (int begin = 0; begin < height; begin++) {
				for (int r = begin; r < height; r++) {
					// sum of each colomn from row_begin to row_r
					vector<int> sums = matrix[r];
					for (int c = 0; c < width; c++) {
						sums[c] = begin == 0 ? sums[c] : sums[c] - matrix[begin - 1][c];
					}

					// find consecutive max from column 0 to column width - 1
					for (int c = 1; c < width; c++) {
						int s = sums[c] + sums[c - 1];
						if (sums[c] < s) {
							sums[c] = s;
							max_val = max(max_val, s);
						}
					}
				}
			}
			return max_val;
		}
	};

	void test() {
		vector<vector<int>> matrix;
		matrix.emplace_back(vector<int>({ 2,1,-3,-4,5 }));
		matrix.emplace_back(vector<int>({ 0,6,3,4,1 }));
		matrix.emplace_back(vector<int>({ 2,-2,-1,4,-5 }));
		matrix.emplace_back(vector<int>({ -3,3,1,0,3 }));

		Solution sol;

		char *str = "abcdef";
		cout << str << endl;

		cout << sol.maxSum(matrix) << endl;
	}
}
