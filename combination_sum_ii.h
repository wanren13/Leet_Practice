#pragma once

#include "allhead.h"

namespace combination_sum_ii {
	class Solution {
	public:
		vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
			sort(candidates.begin(), candidates.end());
			vector<vector<int>> res;
			vector<int> combination;
			helper(res, combination, candidates, 0, target);
			return res;
		}

		void helper(vector<vector<int>> &res, vector<int> &combination, const vector<int>& candidates, int start, int &target) {
			if (target == 0) {
				res.emplace_back(combination);
				return;
			}

			for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
				combination.emplace_back(candidates[i]);
				target -= candidates[i];
				helper(res, combination, candidates, i + 1, target);
				combination.pop_back();
				target += candidates[i];
			}
		}
	};

	void test() {
		vector<int> candidates({ 10, 1, 2, 7, 6, 1, 5 });
		int target = 8;

		Solution sol;
		vector<vector<int>> res = sol.combinationSum2(candidates, target);
		for (auto v : res) {
			for (auto i : v) {
				cout << i << " ";
			}
			cout << endl;
		}
	}
}
