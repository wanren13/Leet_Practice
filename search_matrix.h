#pragma once

#include "allhead.h"

namespace search_matrix {

	void printMatrix(const vector<vector<int>>& m) {
		for (vector<int> v : m) {
			for (int i : v) {
				cout << i << " ";
			}
			cout << endl;
		}
	}


	void generateMatrix(vector<vector<int>>& m, int size) {
		if (size == 0) return;
		srand((int)time(0));
		m = vector<vector<int>>(size, vector<int>(size, 0));
		int last = 0;
		m[0][0] = rand() % 10;
		for (int i = 1; i < size; i++) {
			m[0][i] = m[0][i - 1] + rand() % 10;
		}
		
		for (int i = 1; i < size; i++) {
			m[i][0] = m[i - 1][0] + rand() % 10;
			for (int j = 1; j < size; j++) {
				m[i][j] = max(m[i - 1][j], m[i][j - 1]) + rand() % 10;
			}
		}
	}


	bool find(const vector<vector<int>>& m, int num) {
		int size = m.size();
		int row = 0, col = 0;

		while (col < size) {
			cout << m[row][col] << " ";
			if (m[row][col] == num) return true;
			if (m[row][col] < num) col++;
		}
		row++;
		col = min(col, size - 1);
		while (row < size && col > -1) {
			int n = m[row][col];
			cout << m[row][col] << " ";
			if (n == num) 
				return true;
			else if (n > num) {
				col--;
			}
			else {
				row++;
			}
		}
		
		return false;
	}

	void test() {
		vector<vector<int>> m;
		generateMatrix(m, 8);
		printMatrix(m);
		int n = 62;
		bool found = find(m, n);
		cout << endl << endl << (found? "Found " : "Not found ") << " number: " << n << endl;

	}
}