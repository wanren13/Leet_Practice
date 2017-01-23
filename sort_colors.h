#pragma once

#include "allhead.h"

namespace sort_colors {
	class Solution {
	public:
		void sortColors(vector<int>& nums) {
			// int color[3] = {0};
			// for (int i : nums) color[i]++;
			// int idx = 0;
			// for (int i = 0; i < 3; i++) {
			//     for (int j = 0; j < color[i]; j++) nums[idx++] = i;
			// }
			int left = 0, right = nums.size() - 1;
			for (int i = 0; i <= right; i++) {
				while (nums[i] == 2 && i < right) swap(nums[i], nums[right--]);
				while (nums[i] == 0 && i > left) swap(nums[i], nums[left++]);
			}
		}
	};

	void test() {
		vector<int> nums(
			// {0,1,1,1,2,2,0,0,1,2,1}
			{1,2,0}
		);
		Solution sol;
		sol.sortColors(nums);
		for (int i : nums) cout << i << " ";
		cout << endl;
	}
}