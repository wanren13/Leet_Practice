#pragma once

#include "allhead.h"

namespace merge_sorted_arrays {
	//class Solution {
	//public:
	//	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	//		vector<int>::iterator iter2 = nums2.begin();
	//		for (vector<int>::iterator iter1 = nums1.begin(); iter1 != nums1.end(); iter1++) {
	//			if (iter2 == nums2.end()) return;
	//			if (*iter1 > *iter2) {
	//				iter1 = nums1.insert(iter1, *iter2);
	//				iter2++;
	//			}
	//		}
	//	}
	//};

	class Solution {
	public:
		void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
			int k = m + n - 1;
			for (int i = m - 1, j = n - 1; i >= 0 || j >= 0;) {
				if (i >= 0 && j >= 0) nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
				else if (i >= 0) nums1[k--] = nums1[i--];
				else nums1[k--] = nums2[i--];
			}
		}
	};

	void test() {
		Solution s;
		vector<int> nums1(
		// { 1,3,5 }
		{0}
		);
		vector<int> nums2(
		// { 2,2,2 }
		{ 1 }
		);
		s.merge(nums1, 0, nums2, 1);
		for (int i : nums1) {
			cout << i << " ";
		}
		cout << endl;
	}
}