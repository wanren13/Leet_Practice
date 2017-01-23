#pragma once

#include "allhead.h"

namespace remove_duplicates_from_sorted_array_ii {
	class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			//vector<int> shift(nums.size(), 0);
			if (nums.empty()) return 0;
			nums.emplace_back(nums.back() + 1);
			int shift = 0;
			int len = nums.size();
			int i = 0, j = 1, dist = 0;
			while (j < len) {
				dist = j - i;
				if (nums[i] != nums[j]) {
					if (dist > 2) {
						shift += (dist - 2);
					}
					i = j;
				}
				nums[j - shift] = nums[j];
				j++;
			}

			return len - shift - 1;
		}
	};

	void test() {
		vector<int> v(
		//{ 1,1,1,1,2,2,3,3,3 }
		{1}
		);
		Solution s;
		int n = s.removeDuplicates(v);

		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
}