#pragma once

#include "allhead.h"

namespace wiggle_subsequence {
	class Solution {
	public:
		int wiggleMaxLength(vector<int>& nums) {
			if (nums.size() < 2) return nums.size();
			int i = 2;
			int res = 1;
			while (i < nums.size()) {
				int begin = i - 1;
				while (i < nums.size() && nums[i] >= nums[i - 1]) i++;
				if (begin != i - 1 && nums[begin] < nums[i - 1]) res++;

				begin = i - 1;
				while (i < nums.size() && nums[i] <= nums[i - 1]) i++;
				if (begin != i - 1 && nums[begin] > nums[i - 1]) res++;
			}
			return res;
		}
	};

	void test() {
		vector<int> nums(
		{1,7,4,9,2,5}
		);
		Solution sol;
		cout << sol.wiggleMaxLength(nums) << endl;
	}
}