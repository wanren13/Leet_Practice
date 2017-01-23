#pragma once

#include "allhead.h"

namespace longest_increasing_subsequence {
	//class Solution {
	//public:
	//	int lengthOfLIS(vector<int>& nums) {
	//		vector<int> lis(nums.size(), 1);
	//		int longest = 1;
	//		for (int i = 1; i < nums.size(); i++) {
	//			for (int j = 0; j < i; j++) {
	//				if (nums[i] >= nums[j]) {
	//					lis[i] = max(lis[i], lis[j] + 1);
	//					longest = max(longest, lis[i]);
	//				}
	//			}
	//		}
	//		return longest;
	//	}
	//};


	//class Solution {
	//public:
	//	int lengthOfLIS(vector<int>& nums) {
	//		vector<int> lis(nums.size());
	//		lis[0] = nums[0];
	//		int len = 1;
	//		for (int i = 1; i < nums.size(); i++) {
	//			if (nums[i] < lis[0]) lis[0] = nums[i];
	//			else if (nums[i] > lis[len - 1]) lis[len++] = nums[i];
	//			else {
	//				int begin = 0, end = len - 1, mid = 0;
	//				while (begin <= end) {
	//					int mid = begin + (end - begin) / 2;
	//					if (lis[mid] > nums[i]) end = mid - 1;
	//					else begin = mid + 1;
	//				}
	//				lis[mid + 1] = nums[i];
	//			}
	//		}
	//		return nums.empty()? 0: len;
	//	}
	//};


	//class Solution {
	//public:
	//	int lengthOfLIS(vector<int>& nums) {
	//		vector<int> lis(nums.size());
	//		lis[0] = nums[0];
	//		int len = 1;
	//		for (int i = 1; i < nums.size(); i++) {
	//			if (nums[i] < lis[0]) lis[0] = nums[i];
	//			else if (nums[i] > lis[len - 1]) lis[len++] = nums[i];
	//			else {
	//				int begin = 0, end = len - 1, mid = 0;
	//				while (begin <= end) {
	//					int mid = begin + (end - begin) / 2;
	//					if (lis[mid] > nums[i]) end = mid - 1;
	//					else begin = mid + 1;
	//				}
	//				lis[mid + 1] = nums[i];
	//			}
	//		}
	//		return nums.empty() ? 0 : len;
	//	}
	//};

	class Solution {
	public:
		int lengthOfLIS(vector<int>& nums) {
			int res = 0;
			for (int i = 0; i < nums.size(); i++) {
				int last = INT_MIN, curr = nums[i], l = 1;
				for (int j = i + 1; j < nums.size(); j++) {
					if (nums[j] > last) {
						if (nums[j] > curr) {
							l++;
							last = curr;
						}
						curr = nums[j];
					}
				}
				res = max(res, l);
			}

			return res;
		}
	};

	void test() {
		vector<int> nums(
		//{ 2, 5, 3, 7, 11, 8, 10, 13, 6 }
			//{ 10,9,2,5,3,7,101,180 }
		 {1, 8, 9, 2, 3, 4, 5}
		);

		Solution sol;

		cout << sol.lengthOfLIS(nums) << endl;
	}
}