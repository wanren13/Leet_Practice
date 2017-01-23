#pragma once

#include "allhead.h"

namespace maximum_subarray {
	class Solution {
	public:
		int maxSubArray(vector<int>& nums) {
			int size = nums.size();
			if (size == 0)
				return 0;

			//int max = nums[0], sum;
			//for (int i = 0; i < size; i++) {
			//	max = max > nums[i] ? max : nums[i];
			//	sum = nums[i];
			//	for (int j = i + 1; j < size; j++) {
			//		sum += nums[j];
			//		max = max > sum ? max : sum;
			//	}
			//}

			//return max;



			int max_num = INT_MIN, sum = 0;
			for (int i = 0; i < size; i++) {
				sum = max(nums[i], nums[i] + sum);
				max_num = max(max_num, sum);
			}

			return max_num;
		}
	};

	void test() {
		int arr[] = { -2,1,-3,4,-1,2,1,-5,4 };
		vector<int> v(arr, arr + 9);
		cout << v.size() << endl;

		Solution s;

		cout << s.maxSubArray(v) << endl;




	}
}