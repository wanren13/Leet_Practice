#pragma once

#include "allhead.h"

namespace summary_ranges {
	class Solution {
	public:
		vector<string> summaryRanges(vector<int>& nums) {
			vector<string> res;
			if (nums.empty()) return res;
			string to = "->";
			// nums.emplace_back(nums.back() + 2);
			int start = nums[0], curr = nums[0], end = nums[0];
			for (int i = 1; i < nums.size(); i++) {
				curr = nums[i];
				if (curr > end + 1) {
					if (start == end) res.emplace_back(to_string(start));
					else res.emplace_back(to_string(start) + to + to_string(end));
					start = curr;
				}
				end = curr;
			}

			if (start == end) res.emplace_back(to_string(start));
			else res.emplace_back(to_string(start) + to + to_string(end));
			
			return res;
		}
	};

	void test() {
		Solution sol;
		vector<int> nums(
		{0}
			);
		vector<string> v = sol.summaryRanges(nums);

		for (string s : v) {
			cout << s << " ";
		}
		cout << endl;
	}
}