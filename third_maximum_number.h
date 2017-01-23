#pragma once

#include "allhead.h"

namespace third_maximum_number {
	class Solution {
	public:
		int thirdMax(vector<int>& nums) {
			int three[3];
			for (int i = 0; i < 3; i++) three[i] = INT_MIN;

			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] > three[0]) {
					three[2] = three[1];
					three[1] = three[0];
					three[0] = nums[i];
				}
				else if (nums[i] > three[1] && nums[i] < three[0]) {
					three[2] = three[1];
					three[1] = nums[i];
				}
				else if (nums[i] > three[2] && nums[i] < three[1]) {
					three[2] = nums[i];
				}
			}

			return nums.size() < 3 ? three[0] : three[2];
		}
	};

	void test() {

	}
}