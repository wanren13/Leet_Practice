#pragma once

#include "allhead.h"

namespace search_insert {
	class Solution {
	public:
		int searchInsert(vector<int>& nums, int target) {
			int pos = 0, begin = 0, end = nums.size();

			while (begin < end) {
				pos = begin + (end - begin) / 2;
				if (nums[pos] >= target) end = pos;
				else begin = pos + 1;
			}

			return pos;
		}
	};

	void test() {
		vector<int> nums(
		{1,3,5,6}
		);
		int target = 5;
		Solution sol;
		cout << sol.searchInsert(nums, target) << endl;
	}
}