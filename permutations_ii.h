#pragma once

#include "allhead.h"

namespace permutations_ii {
	class Solution {
	public:
		vector<vector<int>> permuteUnique(vector<int>& nums) {
			vector<vector<int>> res;
			sort(nums.begin(), nums.end());
			helper(res, nums, 0);
			return res;
		}

		void helper(vector<vector<int>>& res, vector<int> nums, int start) {
			if (start == nums.size()) {
				res.emplace_back(nums);
				return;
			}
			for (int i = start; i < nums.size(); i++) {
				if (nums[i] == nums[start]) continue;
				swap(nums[start], nums[i]);
				helper(res, nums, start + 1);
				// swap(nums[start], nums[i]);
			}
		}

	};

	void test() {
		vector<int> nums({ 1,2,1 });
		Solution sol;
		vector<vector<int>> res = sol.permuteUnique(nums);
		for (auto v : res) {
			for (auto i : v) {
				cout << i << " ";
			}
			cout << endl;
		}
	}
}