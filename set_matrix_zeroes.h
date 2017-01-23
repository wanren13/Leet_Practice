#pragma once

#include "allhead.h"


namespace set_matrix_zeroes {
	void printMatrix(vector<vector<int>> matrix) {
		for (auto v : matrix) {
			for (int i : v) {
				cout << i << " ";
			}
			cout << endl;
		}
	}

	class Solution {
	public:
		void setZeroes(vector<vector<int>>& matrix) {
			// set<int> rows, cols;
			// for (int r = 0; r < matrix.size(); r++) {
			//     for (int c = 0; c < matrix[0].size(); c++) {
			//         if (matrix[r][c] == 0) {
			//             rows.insert(r);
			//             cols.insert(c);
			//         }
			//     }
			// }

			// for (int r : rows) {
			//     for (int c = 0; c < matrix[0].size(); c++) {
			//         matrix[r][c] = 0;
			//     }
			// }

			// for (int c : cols) {
			//     for (int r = 0; r < matrix.size(); r++) {
			//         matrix[r][c] = 0;
			//     }
			// }

			if (matrix.empty()) return;

			bool firstColZeros = false, firstRowZeros = false;

			for (int r = 0; r < matrix.size() && !firstColZeros; r++) {
				if (matrix[r][0] == 0) firstColZeros = true;
			}

			for (int c = 0; c < matrix[0].size() && !firstRowZeros; c++) {
				if (matrix[0][c] == 0) firstRowZeros = true;
			}

			// if (firstColZeros) matrix[0][0] = 0;

			if (matrix.size() > 1 && matrix[0].size() > 1) {
				for (int r = 1; r < matrix.size(); r++) {
					for (int c = 1; c < matrix[0].size(); c++) {
						if (matrix[r][c] == 0) {
							matrix[0][c] = 0;
							matrix[r][0] = 0;
						}
					}
				}
			}

			// printMatrix(matrix);
			if (matrix.size() > 1 && matrix[0].size() > 1) {
				for (int r = 1; r < matrix.size(); r++) {
					for (int c = 1; c < matrix[0].size(); c++) {
						if (matrix[r][0] == 0 || matrix[0][c] == 0) {
							matrix[r][c] = 0;
						}
					}
				}
			}

			if (firstColZeros) {
				for (int r = 0; r < matrix.size(); r++) {
					matrix[r][0] = 0;
				}
			}

			if (firstRowZeros) {
				for (int c = 0; c < matrix[0].size(); c++) {
					matrix[0][c] = 0;
				}
			}

		}
	};

	

	void test() {
		// [[0,0,0,5],[4,3,1,4],[0,1,1,4],[1,2,1,3],[0,0,1,1]]
		vector<vector<int>> matrix;
		matrix.emplace_back(vector<int>({ 0,0,0,5 }));
		matrix.emplace_back(vector<int>({ 4,3,1,4 }));
		matrix.emplace_back(vector<int>({ 0,1,1,4 }));
		matrix.emplace_back(vector<int>({ 1,2,1,3 }));
		matrix.emplace_back(vector<int>({ 0,0,1,1 }));
		
		printMatrix(matrix);


		Solution s;
		s.setZeroes(matrix);	

		cout << endl << endl;
		
		printMatrix(matrix);
	}
}