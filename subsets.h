#pragma once

#include "allhead.h"

namespace subsets {
	class Solution {
	public:
		vector<vector<int>> subsets(vector<int>& nums) {
			vector<vector<int>> res({ vector<int>() });
			for (int i : nums) {
				for (auto v : res) {
					v.emplace_back(i);
					res.emplace_back(v);
				}
			}

			return res;
		}
	};

	void test() {
		Solution sol;
		vector<int> nums({ 1,2,3 });
		vector<vector<int>> s = sol.subsets(nums);
		for (auto v : s) {
			for (auto i : v) {
				cout << i << " ";
			}
			cout << endl;
		}
	}
}