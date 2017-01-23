#pragma once

#include "allhead.h"

namespace permutations {
	//class Solution {
	//public:
	//	vector<vector<int>> permute(vector<int>& nums) {
	//		vector<vector<int>> res;
	//		perm(res, nums, vector<int>());
	//		return res;
	//	}

	//	void perm(vector<vector<int>>& res, vector<int> nums, vector<int> p) {
	//		if (nums.empty()) res.emplace_back(p);
	//		for (int i = 0; i < nums.size(); i++) {
	//			p.emplace_back(nums[i]);
	//			vector<int> rest;
	//			for (int j = 0; j < nums.size(); j++) {
	//				if (i != j) rest.emplace_back(nums[j]);
	//			}
	//			perm(res, rest, p);
	//			p.pop_back();
	//		}
	//	}
	//};

	class Solution {
	public:
		vector<vector<int>> permute(vector<int>& nums) {
			vector<vector<int>> res;
			helper(res, nums, 0);
			return res;
		}

		void helper(vector<vector<int>>& res, vector<int>& nums, int start) {
			if (start == nums.size()) {
				res.emplace_back(nums);
				return;
			}
			for (int i = start; i < nums.size(); i++) {
				swap(nums[start], nums[i]);
				helper(res, nums, start + 1);
				swap(nums[start], nums[i]);
			}
		}
	};

	void test() {
		Solution sol;
		vector<int> nums({ 1,2,3,4,5 });
		vector<vector<int>> res = sol.permute(nums);
		for (auto v : res) {
			for (int i : v) {
				cout << i << " ";
			}
			cout << endl;
		}
	}
}