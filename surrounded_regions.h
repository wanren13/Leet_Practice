#pragma once
#include <vector>

using namespace std;

namespace surrounded_regions {
	//class Solution {
	//public:
	//	void solve(vector<vector<char>>& board) {
	//		if (board.size() < 3)
	//			return;
	//		if (board[0].size() < 3)
	//			return;
	//		for (int r = 1; r < board.size() - 1; r++) {
	//			for (int c = 1; c < board[r].size() - 1; c++) {
	//				bool flip = false;
	//				if (board[r][c] == 'O') {
	//					flip = DFS(r, c, board);
	//				}
	//				for (pair<int, int> p : checked) {
	//					board[p.first][p.second] = (flip ? 'X' : 'O');
	//				}
	//				checked.clear();
	//			}
	//		}
	//	}

	//private:
	//	vector<pair<int, int>> checked;
	//	bool DFS(int r, int c, vector<vector<char>>& board) {
	//		int row = board.size();
	//		int col = board[0].size();
	//		stack<pair<int, int>> sp;
	//		sp.push(pair<int, int>(r, c));
	//		while (!sp.empty()) {
	//			pair<int, int> p = sp.top();
	//			sp.pop();
	//			int i = p.first;
	//			int j = p.second;

	//			if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
	//				return false;
	//			}
	//			else {
	//				board[i][j] = 'C';
	//				checked.emplace_back(i, j);
	//				if (i > 0 && board[i - 1][j] == 'O') {
	//					sp.push(pair<int, int>(i - 1, j));
	//				}

	//				if (i < row - 1 && board[i + 1][j] == 'O') {
	//					sp.push(pair<int, int>(i + 1, j));
	//				}

	//				if (j > 0 && board[i][j - 1] == 'O') {
	//					sp.push(pair<int, int>(i, j - 1));
	//				}

	//				if (j < col - 1 && board[i][j + 1] == 'O') {
	//					sp.push(pair<int, int>(i, j + 1));
	//				}
	//			}
	//		}
	//		return true;
	//	}





















	//	//set<pair<int, int>> checked;
	//	//bool DFS(int r, int c, const vector<vector<char>>& board) {
	//	//	int row = board.size();
	//	//	int col = board[0].size();
	//	//	checked.insert(pair<int, int>(r, c));

	//	//	// point on the edge
	//	//	if (r == 0 || r == row - 1|| c == 0 || c == col - 1) {
	//	//			return false;
	//	//	}
	//	//	bool validup = true, validdown = true, validleft = true, validright = true;
	//	//	
	//	//	if (r > 0 && board[r - 1][c] == 'O' && checked.find(pair<int, int>(r - 1, c)) == checked.end()) {
	//	//		validup = DFS(r - 1, c, board);
	//	//	}

	//	//	if (r < row - 1 && board[r + 1][c] == 'O' && checked.find(pair<int, int>(r + 1, c)) == checked.end()) {
	//	//		validdown = DFS(r + 1, c, board);
	//	//	}

	//	//	if (c > 0 && board[r][c - 1] == 'O' && checked.find(pair<int, int>(r, c - 1)) == checked.end()) {
	//	//		validleft = DFS(r, c - 1, board);
	//	//	}

	//	//	if (c < col - 1 && board[r][c + 1] == 'O' && checked.find(pair<int, int>(r, c + 1)) == checked.end()) {
	//	//		validright = DFS(r, c + 1, board);
	//	//	}
	//	//	return (validup && validdown && validleft && validright);
	//	//}

	//};


	class Solution {
	public:
		void solve(vector<vector<char>>& board) {
			int h = board.size();
			if (h == 0) return;
			int w = board[0].size();
			for (int r = 1; r < h - 1; r++) {
				for (int c = 1; c < w - 1; c++) {
					dfs(board, r, c, h, w);
				}
			}
			for (int r = 1; r < h - 1; r++) {
				for (int c = 1; c < w - 1; c++) {
					if (board[r][c] == '.') board[r][c] = 'O';
				}
			}
		}

		bool dfs(vector<vector<char>>& board, int r, int c, int h, int w) {
			if (r < 0 || r == h || c < 0 || c == w || board[r][c] == 'X') return false;
			if (board[r][c] == '.' || (board[r][c] == 'O' && (r == 0 || r == h - 1 || c == 0 || c == w - 1))) return true;
			board[r][c] = '.';
			bool flip = dfs(board, r - 1, c, h, w) || dfs(board, r + 1, c, h, w) || dfs(board, r, c - 1, h, w) || dfs(board, r, c + 1, h, w);
			if (!flip) board[r][c] = 'X';
			return flip;
		}
	};

	void test() {
		Solution s;
		vector<vector<char>> board;

		//*
		board.emplace_back(vector<char>({ 'X' , 'X', 'X', 'X' }));
		board.emplace_back(vector<char>({ 'X' , 'O', 'O', 'X' }));
		board.emplace_back(vector<char>({ 'X' , 'X', 'O', 'X' }));
		board.emplace_back(vector<char>({ 'X' , 'O', 'X', 'X' }));
		//*/

		/*
		board.emplace_back(vector<char>({ 'X' , 'X', 'X'}));
		board.emplace_back(vector<char>({ 'X' , 'O', 'X'}));
		board.emplace_back(vector<char>({ 'X' , 'X', 'X'}));
		//*/

		/*
		board.emplace_back(vector<char>({ 'O' , 'O', 'O' }));
		board.emplace_back(vector<char>({ 'O' , 'O', 'O' }));
		board.emplace_back(vector<char>({ 'O' , 'O', 'O' }));
		//*/


		//set<pair<int, int>> sp;
		//sp.insert(pair<int, int>(1, 3));
		//set<pair<int, int>>::iterator iter = sp.find(pair<int, int>(2, 3));
		//if (iter == sp.end()) {
		//	cout << "End\n";
		//}
		//else {
		//	cout << "Not end\n";
		//}


		
		s.solve(board);

		for (vector<char> row : board) {
			for (char col : row) {
				cout << col << " ";
			}
			cout << endl;
		}
	}
}