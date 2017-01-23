#pragma once

#include "allhead.h"

namespace valid_sudoku {
	//class Solution {
	//public:
	//	bool isValidSudoku(vector<vector<char>>& board) {
	//		vector<int> chk(9, 0);
	//		bool valid = true;

	//		// check horizontally
	//		for (int row = 0; row < 9; row++) {
	//			vector<int> tmp = chk;
	//			for (int col = 0; col < 9; col++) {
	//				char c = board[row][col];
	//				if (c != '.') {
	//					int n = c - '0';
	//					if (n < 1 || n > 9) return false;
	//					else tmp[n - 1]++;
	//				}
	//			}
	//			if (!check(tmp)) return false;
	//		}

	//		// check vertically
	//		for (int col = 0; col < 9; col++) {
	//			vector<int> tmp = chk;
	//			for (int row = 0; row < 9; row++) {
	//				char c = board[row][col];
	//				if (c != '.') {
	//					int n = c - '0';
	//					if (n < 1 || n > 9) return false;
	//					else tmp[n - 1]++;
	//				}
	//			}
	//			if (!check(tmp)) return false;
	//		}

	//		int cnt = 1;
	//		// check square
	//		int si = 0, sj = 0, ei = 3, ej = 3;;
	//		for (int i = 0; i < 3; i++) {
	//			sj = 0;
	//			ej = 3;
	//			for (int j = 0; j < 3; j++) {
	//				vector<int> tmp = chk;
	//				for (int row = si; row < ei; row++) {
	//					for (int col = sj; col < ej; col++) {
	//						cnt++;
	//						char c = board[row][col];
	//						cout << c;
	//						if (c != '.') {
	//							int n = c - '0';
	//							if (n < 1 || n > 9) return false;
	//							else tmp[n - 1]++;
	//						}
	//						//cout << "Row: " << row << "  Col: " << col << endl;
	//					}
	//					cout << endl;
	//				}
	//				cout << endl;
	//				//for (int i : tmp) cout << i << " ";
	//				//cout << endl;
	//				if (!check(tmp)) return false;
	//				sj += 3;
	//				ej += 3;
	//			}
	//			si += 3;
	//			ei += 3;
	//		}

	//		cout << "count :" << cnt << endl;;

	//		return valid;
	//	}

	//	bool check(const vector<int>& v) {
	//		for (int i : v)
	//			if (i > 1) return false;
	//		return true;
	//	}
	//};
	class Solution {
	public:
		bool isValidSudoku(vector<vector<char>>& board) {
			int row[9][9] = { 0 }, col[9][9] = { 0 }, blk[9][9] = { 0 };
			for (int r = 0; r < 9; r++) {
				for (int c = 0; c < 9; c++) {
					if (board[r][c] == '.') continue;
					int n = board[r][c] - '0' - 1;
					int k = 3 * r + c;
					if (row[r][n] || col[c][n] || blk[k][n]) 
						return false;
					row[r][n] = col[c][n] = blk[k][n] = 1;
				}
			}
			return true;
		}
	};

	void test() {
		Solution sol;
		vector<vector<char>> board;
		string s = ".87654321"; 
		board.emplace_back(s.begin(), s.end());
		s = "2........";
		board.emplace_back(s.begin(), s.end());
		s = "3........";
		board.emplace_back(s.begin(), s.end());
		s = "4........";
		board.emplace_back(s.begin(), s.end());
		s = "5........";
		board.emplace_back(s.begin(), s.end());
		s = "6........";
		board.emplace_back(s.begin(), s.end());
		s = "7........";
		board.emplace_back(s.begin(), s.end());
		s = "8........";
		board.emplace_back(s.begin(), s.end());
		s = "9........";
		board.emplace_back(s.begin(), s.end());
		
		cout << sol.isValidSudoku(board) << endl;
	}
}