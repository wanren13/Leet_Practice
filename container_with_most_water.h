#pragma once

#include "allhead.h"

namespace container_with_most_water {
	class Solution {
	public:
		int maxArea(vector<int>& height) {
			int left = 0, right = (int)height.size() - 1, area = 0;
			while (left < right) {
				int l = height[left], r = height[right];
				area = max(area, (right - left) * min(l, r));
				if (l < right) left++;
				else right--;
			}
			return area;
		}
	};

	void test() {
		vector<int> height(
		{ 10,14,10,4,10,2,6,1,6,12 }
		);
		Solution sol;
		cout << sol.maxArea(height) << endl;

	}
}