#pragma once

#include "allhead.h"

namespace first_missing_positive {
	class Solution {
	public:
		int firstMissingPositive(vector<int>& nums) {
			int missing = 1;
			if (nums.empty()) return missing;
			int len = nums.size();
			int i = 0;
			while (i < len) {
				int n = nums[i];
				if (n < 1 || n > len) {
					nums[i] = -1;
					i++;
				}
				else if (nums[n - 1] == n) {
					if (n - 1 != i) nums[i] = -1;
					i++;
				}
				else {
					int tmp = nums[n - 1];
					nums[n - 1] = n;
					nums[i] = tmp;
				}
			}

			if (nums[0] != 1) return 1;

			i = 0;
			for (; i < len; i++) {
				if (nums[i] < 0) return i + 1;
			}

			return i + 1;
		}
	};

	void test() {
		Solution s;
		int arr[] =
		{ 3,3,1,4,0 };
		// { 1, 1 };
		// { 10, 12, 9, 8, 1, 1, 0 };
		// {1, 2, 3};
		vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
		// [10,12, 9, 8, 1, 1, 0]
		cout << "First Integer is " << s.firstMissingPositive(nums) << endl;
	}
}