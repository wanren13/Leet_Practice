#pragma once

#include "allhead.h"

namespace jump_game {
	class Solution {
	public:
		bool canJump(vector<int>& nums) {
			int len = nums.size();
			int maxreach = nums[0];
			int i = 0;
			while (i <= maxreach && maxreach < len - 1) {
				maxreach = max(i + nums[i], maxreach);
				i++;
			}

			return maxreach >= len - 1;
		}
	};

	void test() {
		//int arr[] = { 3,2,1,0,4 };
		vector<int> nums(
		//{ 3, 2, 1, 0, 4 }
		// { 2,3,1,1,4 }
		{2,5,0,0,0}
			);
		Solution sol;
		cout << (sol.canJump(nums) ? "True" : "False") << endl;
	}
}