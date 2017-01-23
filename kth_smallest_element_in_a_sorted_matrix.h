#pragma once

#include "allhead.h"

namespace kth_smallest_element_in_a_sorted_matrix {
	class Solution {
	public:
		int kthSmallest(vector<vector<int>>& matrix, int k) {
			int r1 = 0, c1 = 1, r2 = 1, c2 = 0;
			int res = matrix[0][0];
			int h = matrix.size(), w = matrix[0].size();
			while (--k) {
				if (c1 == w) {
					r1++;
					c1 = min(w - 1, c2 + 1);
				}
				if (r2 == h) {
					c2++;
					r2 = min(h - 1, r1 + 1);
				}
				if (matrix[r1][c1] > matrix[r2][c2]) res = matrix[r2++][c2];
				else res = matrix[r1][c1++];
			}
			return res;
		}
	};

	void test() {
		vector<vector<int>> matrix;
		//matrix.emplace_back(vector<int>({ 1,5,9 }));
		//matrix.emplace_back(vector<int>({ 10,11,13 }));
		//matrix.emplace_back(vector<int>({ 12,13,15 }));
		//int k = 9;

		matrix.emplace_back(vector<int>({ 3,4,5 }));
		matrix.emplace_back(vector<int>({ 3,5,5 }));
		matrix.emplace_back(vector<int>({ 6,7,8 }));
		int k = 9;


		Solution sol;
		cout << sol.kthSmallest(matrix, k) << endl;
	}
}