#pragma once

#include "allhead.h"

namespace longest_increasing_path_in_a_matrix {
	class Solution {
	public:
		int longestIncreasingPath(vector<vector<int>>& matrix) {
			int longest = 0;
			int h = matrix.size();
			if (h == 0) return longest;
			int w = matrix[0].size();

			vector<bool> mrow(w, false);
			vector<vector<bool>> visited(h, mrow);
			vector<vector<bool>> searched(h, mrow);

			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					// if (searched[i][j]) continue;
					vector<vector<bool>> v = visited;
					int path = dfs(searched, v, matrix, i, j, h, w);
					longest = max(longest, path);
					cout << path << " ";
				}
				cout << endl;
			}

			return longest;
		}

		int dfs(vector<vector<bool>>& searched, vector<vector<bool>>& visited, const vector<vector<int>>& matrix, int i, int j, int h, int w) {
			if (visited[i][j]) return 0;
			searched[i][j] = true;
			visited[i][j] = true;
			int left = 0, right = 0, up = 0, down = 0;
			if (i > 0 && matrix[i - 1][j] > matrix[i][j]) up = dfs(searched, visited, matrix, i - 1, j, h, w);
			if (i < h - 1 && matrix[i + 1][j] > matrix[i][j]) down = dfs(searched, visited, matrix, i + 1, j, h, w);
			if (j > 0 && matrix[i][j - 1] > matrix[i][j]) left = dfs(searched, visited, matrix, i, j - 1, h, w);
			if (j < w - 1 && matrix[i][j + 1] > matrix[i][j]) right = dfs(searched, visited, matrix, i, j + 1, h, w);

			return 1 + max(left, max(right, max(up, down)));
		}
	};

	void test() {
		//vector<vector<int>> matrix;
		//matrix.emplace_back(vector<int>({9,9,4}));
		//matrix.emplace_back(vector<int>({6,6,8}));
		//matrix.emplace_back(vector<int>({2,1,1}));
		//Solution sol;
		//cout << sol.longestIncreasingPath(matrix) << endl;



		multimap<int, int> m;
		m.insert(pair<int, int>(2, 0));
		m.insert(pair<int, int>(2, 2));
		m.insert(pair<int, int>(3, 0));
		m.insert(pair<int, int>(4, 4));
		m.insert(pair<int, int>(5, 10));
		m.insert(pair<int, int>(6, 12));
		m.insert(pair<int, int>(2, 4));
		m.insert(pair<int, int>(2, 8));
		for (auto iter = m.begin(); iter != m.end(); iter++)
			cout << iter->first << ": " << iter->second << endl;


	}
}