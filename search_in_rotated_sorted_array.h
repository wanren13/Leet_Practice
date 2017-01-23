#pragma once

#include "allhead.h"

namespace search_in_rotated_sorted_array {
	class Solution {
	public:
		int search(vector<int>& nums, int target) {
			int begin = 0, end = nums.size() - 1;
			while (begin <= end) {
				int mid = begin + (end - begin) / 2;
				if (nums[mid] == target) return mid;
				else if (target < nums[mid]) {
					if (target <= nums[end] && nums[end] < nums[mid]) begin = mid + 1;
					else end = mid - 1;
				}
				else {
					if (target >= nums[begin] && nums[begin] > nums[mid]) end = mid - 1;
					else begin = mid + 1;
				}
			}
			return -1;
		}
	};

	void test() {
		Solution sol;
		vector<int> v(
		 { 4,5,6,7,0,1,2 }
		// {5,1,3}
			);
		int target = 2;
		cout << sol.search(v, target) << endl;
	}
}