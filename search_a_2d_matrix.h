#pragma once

#include "allhead.h"

namespace search_a_2d_matrix {
	//class Solution {
	//public:
	//	bool searchMatrix(vector<vector<int>>& matrix, int target) {
	//		int height = matrix.size();
	//		if (height == 0) return false;
	//		int width = matrix[0].size();

	//		int row = 0, col = 0;

	//		// to right most
	//		while (matrix[row][col] < target) {
	//			if (col + 1 == width) break;
	//			else col++;
	//			if (matrix[row][col] == target) return true;
	//		}

	//		while (true) {
	//			if (matrix[row][col] == target) return true;
	//			else if (matrix[row][col] < target) { row++; if (row == height) return false; }
	//			else {
	//				while (matrix[row][col] > target) { col--; if (col < 0) return false; }
	//			}
	//		}

	//		return false;
	//	}
	//};

	class Solution {
	public:
		bool searchMatrix(vector<vector<int>>& matrix, int target) {
			int h = matrix.size();
			if (h == 0) return false;
			int w = matrix[0].size();

			int begin = 0, end = h * w - 1;

			while (begin <= end) {
				int mid = begin + (end - begin) / 2;
				int n = matrix[mid / w][mid % w];
				if (n == target) return true;
				else if (n < target) begin = mid + 1;
				else end = mid - 1;
			}

			return false;
		}
	};

	void test() {
		Solution sol;
		vector<vector<int>> matrix;
		matrix.emplace_back(vector<int>({1,3,5,7}));
		matrix.emplace_back(vector<int>({10,11,16,20}));
		matrix.emplace_back(vector<int>({23,30,34,50}));
		int target = 3;
		cout << (sol.searchMatrix(matrix, target) ? "True" : "False") << endl;
	}
}