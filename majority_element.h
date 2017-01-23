#pragma once

#include "allhead.h"

namespace majority_element {
	class Solution {
	public:
		int majorityElement(vector<int>& nums) {
			int major = nums[0], cnt = 1;
			for (int i = 1; i < nums.size(); i++) {
				if (cnt == 0) {
					major = nums[i];
					cnt = 1;
				}
				if (nums[i] != major) cnt--;
				else cnt++;
			}
			return major;
		}
	};

	void test() {
		Solution sol;
		vector<int> nums({ 1,1,2,2,2,1,1 });
		cout << sol.majorityElement(nums) << endl;
	}
}