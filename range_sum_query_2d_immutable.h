#pragma once

#include "allhead.h"

namespace range_sum_query_2d_immutable {
	class NumMatrix {
	public:
		NumMatrix(vector<vector<int>> &matrix) {
			m = matrix;
			for (int i = 0; i < m.size(); i++) {
				for (int j = 0; j < m[0].size(); j++) {
					int lefttop = (i == 0 || j == 0) ? 0 : m[i - 1][j - 1];
					int top = (i == 0) ? 0 : m[i - 1][j];
					int left = (j == 0) ? 0 : m[i][j - 1];

					m[i][j] = m[i][j] + top + left - lefttop;
				}
			}

			for (auto v : m) {
				for (int i : v) {
					cout << i << " ";
				}
				cout << endl;
			}
		}

		int sumRegion(int row1, int col1, int row2, int col2) {
			int lefttop = (row1 == 0 || col1 == 0) ? 0 : m[row1 - 1][col1 - 1];
			int top = (row1 == 0) ? 0 : m[row1 - 1][col2];
			int left = (col1 == 0) ? 0 : m[row2][col1 - 1];

			return m[row2][col2] - top - left + lefttop;
		}
	private:
		vector<vector<int>> m;
	};

	void test() {
		vector<vector<int>> matrix;
		matrix.emplace_back(vector<int>({ 3, 0, 1, 4, 2 }));
		matrix.emplace_back(vector<int>({ 5, 6, 3, 2, 1 }));
		matrix.emplace_back(vector<int>({ 1, 2, 0, 1, 5 }));
		matrix.emplace_back(vector<int>({ 4, 1, 0, 1, 7 }));
		matrix.emplace_back(vector<int>({ 1, 0, 3, 0, 5 }));



		// sumRegion(2, 1, 4, 3), sumRegion(1, 1, 2, 2), sumRegion(1, 2, 2, 4)



		NumMatrix numMatrix(matrix);
		cout << numMatrix.sumRegion(2, 1, 4, 3) << endl; //8
		cout << numMatrix.sumRegion(1, 1, 2, 2) << endl; //11
		cout << numMatrix.sumRegion(1, 2, 2, 4) << endl; //12

	}



}