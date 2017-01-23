#pragma once

#include "allhead.h"

namespace remove_duplicates_from_sorted_array {
	class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			int cnt = 0;

			//1,1,2,2,3
			for (int i = 0; i < int(nums.size()) - 1; i++) {
				if (nums[i] == nums[i + 1]) cnt++;
				else {
					nums[i + 1 - cnt] = nums[i + 1];
				}
			}

			return nums.size() - cnt;
		}
	};

	void test() {
		int arr[] =
		{ 1,1,1,1 };
		vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
		nums.clear();
		Solution s;
		s.removeDuplicates(nums);
		for (int i : nums) {
			cout << i << " ";
		}
		cout << endl;
	}
}