#pragma once

#include "allhead.h"

namespace quick_sort {
	class Solution
	{
	public:
		void qsort(vector<int>& nums) {

		}

		void qsort_help(vector<int>& nums, int begin, int end) {
			int l = begin + 1, r = end;
			while (l < r) {
				while (nums[l] < nums[begin]) l++;
				while (nums[r] > nums[begin]) r--;
				if (l < r) swap(nums[l++], nums[r--]);
			}

			if (begin < j) qsort_help(nums, le)
		}
	};

	void test() {
		Solution sol;
		vector<int> nums(
		{5,3,1,3,4,5,6,7}
			);
		sol.qsort(nums);

		for (int i : nums) {

		}
	}
}