#pragma once

#include "allhead.h"

namespace find_peak_element {
	//class Solution {
	//public:
	//	int findPeakElement(vector<int>& nums) {
	//		// int len = nums.size();
	//		// if (len == 0) return 0;
	//		// if (nums.size() == 1) return 0;
	//		// if (nums[0] > nums[1]) return 0;
	//		// if (nums[len - 1] > nums[len - 2]) return len - 1;

	//		// for (int i = 1; i < len - 1; i++) {
	//		//     if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) return i;
	//		// }
	//		// return 0;


	//		int len = nums.size();
	//		int start = 0, end = len - 1;

	//		while (start < end) {
	//			int mid1 = start + (end - start) / 2;
	//			int mid2 = mid1 + 1;
	//			if (nums[mid1] < nums[mid2]) start = mid2;
	//			if (nums[mid1] > nums[mid2]) end = mid1;
	//		}

	//		return start;
	//	}
	//};

	class Solution {
	public:
		int findPeakElement(vector<int>& nums) {
			int begin = 0, end = nums.size() - 1, mid = 0;
			while (begin < end) {
				mid = begin + (end - begin) / 2;
				if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
					break;
				else if (nums[mid] > nums[mid - 1]) begin = mid;
				else end = mid;
			}

			return mid;
		}
	};

	void test() {
		Solution sol;
		vector<int> v(
		// {1,2,3,1}
		{1, 2, 3}
			);
		cout << sol.findPeakElement(v) << endl;
	}
}