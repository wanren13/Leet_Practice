#pragma once

#include "allhead.h"

namespace search_for_a_range {
	class Solution {
	public:
		// built-in
		// vector<int> searchRange(vector<int>& nums, int target) {
		//     vector<int>::iterator l = lower_bound(nums.begin(), nums.end(), target);
		//     vector<int>::iterator r = upper_bound(nums.begin(), nums.end(), target);
		//     return vector<int>({*l == target ? l - nums.begin() : -1, *(r - 1) == target ? r - 1 - nums.begin() : -1});
		// }

		vector<int> searchRange(vector<int>& nums, int target) {
			int l = lower(nums, target);
			int u = upper(nums, target);
			return vector<int>({ l, u });
		}

		int lower(const vector<int>& nums, int target) {
			int begin = 0, end = nums.size() - 1;
			while (begin <= end) {
				int mid = begin + (end - begin) / 2;
				if (nums[mid] >= target) end = mid;
				else begin = mid + 1;
			}
			cout << "Low begin: " << end << endl;
			return nums[end] == target ? end : -1;
		}

		int upper(const vector<int>& nums, int target) {
			int begin = 0, end = nums.size() - 1;
			while (begin <= end) {
				int mid = begin + (end + 1 - begin) / 2;
				if (nums[mid] <= target) begin = mid;
				else end = mid - 1;
			}
			cout << "up end: " << end << endl;
			return nums[begin] == target ? begin : -1;
		}
	};


	//class Solution {
	//public:
	//	vector<int> searchRange(vector<int>& nums, int target) {
	//		//if (nums.end()) return vector<int>({-1, -1});
	//		auto lower = lower_bound(nums.begin(), nums.end(), target);
	//		auto upper = upper_bound(nums.begin(), nums.end(), target);
	//		int l = lower != nums.end() && *lower == target ? lower - nums.begin() : -1;
	//		int u = l == -1 ? -1 : upper - nums.begin() - 1;
	//		return vector<int>({ l, u });

	//		// int begin = 0, end = nums.size() - 1;
	//		// while (begin < end) {

	//		// }


	//	}
	//};

	void test() {
		vector<int>nums(
		// {1}
			{1,2,2,2,2,3,3}
		);
		int target = 2;
		Solution sol;
		vector<int> res = sol.searchRange(nums, target);
		cout << res[0] << " " << res[1] << endl;
	}
}