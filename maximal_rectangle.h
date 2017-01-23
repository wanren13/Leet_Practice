#pragma once

#include "allhead.h"

namespace maximal_rectangle {
	class Solution {
	public:
		int maximalRectangle(vector<vector<char>>& matrix) {
			int height = matrix.size();
			if (height == 0) return 0;
			int width = matrix[0].size();
			vector<int> hs(width + 1, 0);
			vector<int> ws(width + 1, 0);

			int maxRec = 0;
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					int n = matrix[i][j] - '0';
					int size = n;
					if (hs[j] && hs[j + 1] && n) {
						int leftheight = min(hs[j], hs[j + 1] + 1);
						int leftsize = leftheight * ws[j];
						int topwidth = min(ws[j] + 1, ws[j + 1]);
						int topsize = hs[j + 1] * topwidth;
						if (leftsize + leftheight >= topsize + topwidth) {
							hs[j + 1] = leftheight;
							ws[j + 1] = ws[j] + 1;
						}
						else {
							hs[j + 1] = hs[j + 1] + 1;
							ws[j + 1] = topwidth;
						}
						size = hs[j + 1] * ws[j + 1];
					}
					else {
						if (n != 0) {
							int topsize = hs[j + 1] + 1;
							int leftsize = ws[j] + 1;
							size = max(topsize, leftsize);
							if (size == topsize) {
								hs[j + 1] = topsize;
								ws[j + 1] = 1;
							}
							else {
								hs[j + 1] = 1;
								ws[j + 1] = leftsize;
							}
						}
						else {
							hs[j + 1] = 0;
							ws[j + 1] = 0;
							size = 0;
						}
						
					}
					maxRec = max(maxRec, size);
				}
			}

			//*
			cout << "width: ";
			for (int w : ws) cout << w << " ";
			cout << endl << "height: ";
			for (int h : hs) cout << h << " ";
			cout << endl;
			//*/

			return maxRec;
		}
	};

	void test() {
		Solution sol;
		vector<vector<char>> matrix;
		string s = "001001000011111";
		matrix.emplace_back(s.begin(), s.end());
		s = "001001000011110";
		matrix.emplace_back(s.begin(), s.end());
		s = "111111111111100";
		matrix.emplace_back(s.begin(), s.end());
		//s = "10010";
		//matrix.emplace_back(s.begin(), s.end());

		cout << sol.maximalRectangle(matrix);

	}
}