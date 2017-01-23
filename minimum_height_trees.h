#pragma once

#include "allhead.h"

namespace minimum_height_trees {
	class Solution {
	public:
		vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
			vector<int> res;
			if (n == 0 || edges.empty()) return res;


			auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
				return p1.second > p2.second;
			};

			priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);

			unordered_map<int, vector<int>> adjlist;

			for (auto p : edges) {
				adjlist[p.first].emplace_back(p.second);
				adjlist[p.second].emplace_back(p.first);
			}

			for (auto p : adjlist) {
				q.emplace(p.first, dfs(p.first, adjlist));
			}

			int minheight = q.top().second;

			while (q.top().second == minheight) {
				res.emplace_back(q.top().first);
				q.pop();
			}

			return res;
		}

		int dfs(int node, unordered_map<int, vector<int>>& adjlist) {
			int len = 0;
			int n = adjlist[node].size();
			if (n == 0) return len;
			else {
				for (int i = 0; i < n; i++) {
					int connect = adjlist[node][i];
					if (connect != -1) {
					adjlist[node][i] = -1;
					len = max(len, 1 + dfs(connect, adjlist));
					adjlist[node].insert(it, connect);
				}
			}

			return len;
		}
	};

	void test() {
		int n = 4;
		vector<pair<int, int>> edges;
		edges.emplace_back(1, 0);
		edges.emplace_back(1, 2);
		edges.emplace_back(1, 3);
		Solution sol;
		vector<int> res = sol.findMinHeightTrees(n, edges);
		for (int i : res) cout << i << " ";
		cout << endl;
	}
}