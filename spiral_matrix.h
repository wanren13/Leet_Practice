#pragma once

#include "allhead.h"

namespace spiral_matrix {
	//class Solution {
	//public:
	//	vector<int> spiralOrder(vector<vector<int>>& matrix) {
	//		vector<int> res;

	//		int height = matrix.size();
	//		if (height == 0) return res;
	//		int width = matrix[0].size();
	//		int row = 0, col = -1;

	//		int size = height * width;
	//		while (res.size() != size) {
	//			// to right
	//			for (int i1 = 0; i1 < width; i1++) {
	//				res.emplace_back(matrix[row][++col]);
	//			}

	//			// to bottom
	//			height--;
	//			if (height == 0) break;
	//			for (int j1 = 0; j1 < height; j1++) {
	//				res.emplace_back(matrix[++row][col]);
	//			}

	//			// to left
	//			width--;
	//			if (width == 0) break;
	//			for (int i2 = 0; i2 < width; i2++) {
	//				res.emplace_back(matrix[row][--col]);
	//			}

	//			// to top
	//			height--;
	//			for (int j2 = 0; j2 < height; j2++) {
	//				res.emplace_back(matrix[--row][col]);
	//			}

	//			width--;
	//		}

	//		return res;
	//	}
	//};


	class Solution {
	public:
		vector<int> spiralOrder(vector<vector<int>>& matrix) {
			vector<int> res;
			int h = matrix.size();
			if (h == 0) return res;
			int w = matrix[0].size();

			int up = 0, down = h - 1, left = 0, right = w - 1;

			while (left <= right || up <= down) {
				for (int r = up, c = left; c <= right; c++) res.emplace_back(matrix[r][c]);
				up++; if (up >= h) break;
				for (int r = up, c = right; r <= down; r++) res.emplace_back(matrix[r][c]);
				right--; if (right < 0) break;
				for (int r = down, c = right; c >= left; c--) res.emplace_back(matrix[r][c]);
				down--; if (down < 0) break;
				for (int r = down, c = left; r >= up; r--) res.emplace_back(matrix[r][c]);
				left++; if (left >= w) break;
			}

			return res;
		}
	};

	void test() {
		Solution sol;
		vector<vector<int>> matrix;
		matrix.emplace_back(vector<int>({ 1,2,3,4 }));
		matrix.emplace_back(vector<int>({ 5,6,7,8 }));
		matrix.emplace_back(vector<int>({ 9,10,11,12 }));
		//matrix.emplace_back(vector<int>({ 7,8,9 }));
		//matrix.emplace_back(vector<int>({ 10,11,12 }));
		//matrix.emplace_back(vector<int>({ 13,14,15 }));

		vector<int> v = sol.spiralOrder(matrix);
		for (int i : v) {
			cout << i << " ";
		}

		cout << endl;
	}




}