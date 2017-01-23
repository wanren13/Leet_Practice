#pragma once

#include "allhead.h"

namespace increasing_triplet_subsequence {
	class Solution {
	public:
		// DP
		// bool increasingTriplet(vector<int>& nums) {
		//     vector<int> counts(nums.size(), 1);
		//     int count = 1;
		//     for (int i = 1; i < nums.size(); i++) {
		//         for (int j = i - 1; j >= 0; j--) {
		//             if (nums[j] < nums[i]) {
		//                 counts[i] = max(counts[i], counts[j] + 1);
		//                 count = max(count, counts[i]);
		//                 if (count == 3) return true;
		//             }
		//         }
		//     }

		//     return false;
		// }


		// Binary Search
		bool increasingTriplet(vector<int>& nums) {
			cout << "***************************" << endl;
			vector<int> tails(nums.size());
			if (nums.empty()) return false;
			tails[0] = nums[0];
			int len = 1;
			for (int i = 1; i < nums.size(); i++) {
				if (nums[i] < tails[0]) tails[0] = nums[i];
				else if (nums[i] > tails[len - 1]) {
					tails[len++] = nums[i];
					if (len > 2) return true;
				}
				else {
					int begin = 0, end = len - 1;
					while (begin < end) {
						int mid = begin + (end + 1 - begin) / 2;
						if (nums[mid] >= nums[i]) begin = mid;
						else end = mid - 1;
					}
					tails[end] = nums[i];
				}
				for (int i : tails) cout << i << " ";
				cout << endl;
			}

			return false;
		}
	};

	void test() {
		vector<int> nums(
		{ 2,5,3,4,5 }
		);
		Solution sol;
		cout << sol.increasingTriplet(nums) << endl;
	}
}