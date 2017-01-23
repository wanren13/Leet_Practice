#pragma once

#include "allhead.h"

namespace minimum_size_subarray_sum {
	class Solution {
	public:
		int minSubArrayLen(int s, vector<int>& nums) {
			int sum = 0, res = nums.size(), i1 = 0, i2 = -1, len = nums.size();
			// 2 3 1 2 4 3
			while (++i2 < len) {
				sum += nums[i2];
				if (sum >= s) {
					if (i2 - i1 + 1 < res) res = i2 - i1 + 1;
					while (sum - nums[i1] >= s) {
						sum -= nums[i1++];
						if (i2 - i1 + 1 < res) res = i2 - i1 + 1;
						if (res == 1) return res;
					}
				}				
			}

			return sum >= s ? res : 0;
		}
	};

	void test() {
		// vector<int> nums({ 2,3,5,2,4,3 });
		// vector<int> nums({ 2 });
		// vector<int> nums({ 2, 3, 1, 1, 1, 1, 1 });
		vector<int> nums({ 1, 4, 4 });
		// vector<int> nums;
		int s = 4;
		Solution sol;
		cout << sol.minSubArrayLen(s, nums) << endl;
	}
}