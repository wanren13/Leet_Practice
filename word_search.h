#pragma once

#include "allhead.h"

namespace word_search {
	class Solution {
	public:
		bool exist(vector<vector<char>>& board, string word) {
			dir[0].r = -1; dir[0].c = 0;
			dir[1].r = 1;  dir[1].c = 0;
			dir[2].r = 0;  dir[2].c = -1;
			dir[3].r = 0;  dir[3].c = 1;

			for (int i = 0; i < board.size(); i++) {
				for (int j = 0; j < board[0].size(); j++) {
					if (dfs(board, word, 0, i, j)) return true;
				}
			}
			return false;
		}

		bool dfs(vector<vector<char>>& board, const string& word, int i, int r, int c) {
			if (i > word.length()) return true;
			if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || !board[r][c]) return false;
			char t = board[r][c];
			if (word[i] == t) {
				for (int d = 0; d < 4; d++) {
					board[r][c] = 0;
					bool find = dfs(board, word, i + 1, r + dir[d].r, c + dir[d].c);
					board[r][c] = t;
					if (find) return true;
				}
			}
			return false;
		}
	private:
		struct Dir {
			int r, c;
			//Dir(int rr, int cc) : r(rr), c(cc) {}
		};
		Dir dir[4];
	};


	//class Solution {
	//public:
	//	bool exist(vector<vector<char>>& board, string word) {
	//		bool found = false;
	//		int h = board.size();
	//		if (h == 0) return found;
	//		int w = board[0].size();

	//		for (int r = 0; r < h; r++) {
	//			for (int c = 0; c < w; c++) {
	//				if (r == h - 1 && c == w - 1) 
	//					cout << "***********************************************************************************" << endl;
	//				if (dfs(board, word, 0, r, c, h, w, 0)) return true;
	//			}
	//		}
	//		return found;
	//	}

	//	bool dfs(vector<vector<char>>& board, const string& word, int i, int r, int c, int h, int w, int st) {
	//		cout << "Enter Stack " << st<< " r: " << r << " c: " << c << " i: " << i << " char: " << word[i] << " board: " << (board[r][c] == '\0'?'0':board[r][c]) << endl;
	//		if (i >= word.length()) {
	//			cout << "Leave Stack " << st << " r: " << r << " c: " << c << " i: " << i << " char: " << word[i] << " board: " << (board[r][c] == '\0' ? '0' : board[r][c]) << endl;
	//			return false;
	//		}
	//		char bc = board[r][c];
	//		bool match = word[i] == bc;
	//		if (i == word.length() - 1) {
	//			cout << "Leave Stack " << st << " r: " << r << " c: " << c << " i: " << i << " char: " << word[i] << " board: " << (board[r][c] == '\0' ? '0' : board[r][c]) << endl;
	//			return match;
	//		}
	//		else {
	//			if (!match) {
	//				cout << "Leave Stack " << st << " r: " << r << " c: " << c << " i: " << i << " char: " << word[i] << " board: " << (board[r][c] == '\0' ? '0' : board[r][c]) << endl;
	//				return false;
	//			}
	//			board[r][c] = 0;
	//			bool left = false, right = false, up = false, down = false;
	//			if (r > 0 && board[r - 1][c]) up = dfs(board, word, i + 1, r - 1, c, h, w, st + 1);
	//			if (r < h - 1 && board[r + 1][c]) down = dfs(board, word, i + 1, r + 1, c, h, w, st + 1);
	//			if (c > 0 && board[r][c - 1]) left = dfs(board, word, i + 1, r, c - 1, h, w, st + 1);
	//			if (c < w - 1 && board[r][c + 1]) right = dfs(board, word, i + 1, r, c + 1, h, w, st + 1);
	//			board[r][c] = bc;
	//			cout << "Leave Stack " << st << " r: " << r << " c: " << c << " i: " << i << " char: " << word[i] << " board: " << (board[r][c] == '\0' ? '0' : board[r][c]) << endl;
	//			return  left || right || up || down;
	//		}
	//	}
	//};

	void test (){
//		vector<vector<char>> board = vector<vector<char>>(10, vector<char>(10, 'a'));
//		string word = "baaaaaaaaaaaaaaaaaaa";
		//vector<vector<char>> board{ {'A','B','C','E'}, {'S','F','C','S'}, {'A', 'D', 'E', 'E'} };
		//string word = "ABCCED";
		vector<vector<char>> board{ {'a','a'} };
		string word = "aaa";
		Solution sol;
		cout << sol.exist(board, word) << endl;

	}
}