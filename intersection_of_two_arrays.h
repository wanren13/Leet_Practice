#pragma once

#include "allhead.h"

namespace intersection_of_two_arrays {
	class Solution {
	public:
		vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
			vector<int> res;
			int len1 = nums1.size(), len2 = nums2.size();
			if (!len1 || !len2) return res;
			if (len1 < len2) swap(nums1, nums2);
			sort(nums1.begin(), nums1.end());
			int curr = nums2[0] - 1;
			for (int i = 0; i < nums2.size(); i++) {
				if (nums2[i] != curr) {
					curr = nums2[i];
					int start = 0, end = nums1.size() - 1;
					while (start <= end) {
						int mid = start + (end - start) / 2;
						if (nums1[mid] == curr) {
							res.emplace_back(curr);
							break;
						}
						else if (nums1[mid] < curr) start = mid + 1;
						else end = mid - 1;
					}
				}
			}

			return res;
		}
	};

	void test() {
		Solution sol;
		vector<int> nums1({ 3,1,2 });
		vector<int> nums2({ 1,3 });
		vector<int> res = sol.intersection(nums1, nums2);
		for (int i : res) {
			cout << i << " ";
		}
	}
}