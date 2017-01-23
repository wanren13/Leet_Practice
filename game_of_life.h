#pragma once

#include "allhead.h"

namespace game_of_life {
	//class Solution {
	//public:
	//	void gameOfLife(vector<vector<int>>& board) {
	//		for (int i = 0; i < board.size(); i++) {
	//			for (int j = 0; j < board[0].size(); j++) {
	//				int cnt = countNeighbors(i, j, board);
	//				cout << cnt << " ";
	//				// if (board[i][j] == 1) {
	//				//     if (cnt <= 2) board[i][j] += 10;
	//				//     else if (cnt < 4) board[i][j] += 20;
	//				//     else board[i][j] += 10;
	//				// }
	//				// else {
	//				//     if (cnt == 3) board[i][j] += 20;
	//				//     else board[i][j] += 10;
	//				// }
	//			}
	//			cout << endl;
	//		}

	//		//updateBoard(board);
	//	}

	//	int countNeighbors(int i, int j, const vector<vector<int>>& board) {
	//		int cnt = 0;
	//		for (int r = max(i - 1, 0); r <= min(i + 1, (int)board.size() - 1); r++) {
	//			for (int c = max(j - 1, 0); c <= min(j + 1, (int)board[0].size() - 1); c++) {
	//				if (i != r && j != c) 
	//					cnt += board[r][c] % 10;
	//			}
	//		}
	//		return cnt;
	//	}

	//	void updateBoard(vector<vector<int>>& board) {
	//		for (int i = 0; i < board.size(); i++) {
	//			for (int j = 0; j < board[0].size(); j++) {
	//				board[i][j] = board[i][j] / 10;
	//			}
	//		}
	//	}
	//};

	class Solution {
	public:
		void gameOfLife(vector<vector<int>>& board) {
			int h = board.size();
			if (h == 0) return;
			int w = board[0].size();
			for (int r = 0; r < h; r++) {
				for (int c = 0; c < w; c++) {
					int n = countNeighbors(board, r, c, h, w);
					if ((board[r][c] == 1 && n == 2) || n == 3) board[r][c] += 10;
				}
			}

			for (int r = 0; r < board.size(); r++) {
				for (int c = 0; c < board[0].size(); c++) {
					board[r][c] /= 10;
				}
			}
		}

		int countNeighbors(const vector<vector<int>>& board, int r, int c, int h, int w) {
			int n = 0;
			for (int i = max(r - 1, 0); i <= min(r + 1, h - 1); i++) {
				for (int j = max(c - 1, 0); j <= min(c + 1, w - 1); j++) {
					if (i != r && j != c) n += board[i][j] % 10;
				}
			}
			return n;
		}
	};


	void test() {
		vector<vector<int>> board;
		board.emplace_back(vector<int>({ 1, 0, 1 }));
		board.emplace_back(vector<int>({ 0, 1, 0 }));
		board.emplace_back(vector<int>({ 1, 1, 1 }));
		Solution sol;
		sol.gameOfLife(board);
		for (auto v : board) {
			for (auto i : v) {
				cout << i << " ";
			}
			cout << endl;
		}
	}
}