#pragma once

#include "allhead.h"

namespace combination_sum_iii {
	class Solution {
	public:
		vector<vector<int>> combinationSum3(int k, int n) {
			vector<vector<int>> res;
			vector<int> comb;
			helper(res, comb, 1, k, n);
			return res;
		}

		void helper(vector<vector<int>>& res, vector<int>& comb, int begin, const int& k, int& n) {
			if (n == 0 && comb.size() == k) {
				res.emplace_back(comb);
				return;
			}
			for (int i = begin; i < 9 && comb.size() < k; i++) {
				n -= i;
				comb.emplace_back(i);
				helper(res, comb, i + 1, k, n);
				n += i;
				comb.pop_back();
			}
		}
	};

	void test() {
		//Solution sol;
		//int k = 3;
		//int n = 15;
		//vector<vector<int>> res = sol.combinationSum3(k, n);
		//for (auto v : res) {
		//	for (auto i : v) {
		//		cout << i << " ";
		//	}
		//	cout << endl;
		//}

		vector<int> v({ 1,2,3 });
		for (auto i : v) i *= -1;
		for (auto i : v) cout << i << " ";
		cout << endl;
	}
}