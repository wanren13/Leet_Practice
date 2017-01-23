#pragma once

#include "allhead.h"

namespace findDuplicates {
	class Solution {
	public:
		vector<int> findDuplicates(vector<int>& nums) {
			vector<int> res;
			for (int i = 0; i < nums.size(); i++) {
				int n = nums[i], next = n - 1;
				if (next == i) continue;
				else nums[i] = 0;
				while (next >= 0 && nums[next] != next + 1) {
					// self = false;
					swap(n, nums[next]);
					next = n - 1;
				}
				if (next >= 0) res.emplace_back(nums[next]);
			}
			return res;
		}
	};

	void test() {
		vector<int> nums(
		{ 2,3,4,5,1 }
		);

		Solution sol;
		vector<int> res = sol.findDuplicates(nums);
		for (int i : res) cout << i << " ";
		cout << endl;

	}
}