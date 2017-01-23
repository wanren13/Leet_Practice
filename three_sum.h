#pragma once

#include "allhead.h"

namespace three_sum{
	class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			vector<vector<int>> res;
			for (int i = 0; i < nums.size() - 2; i++) {
				int begin = i + 1, end = nums.size() - 1;
				while (begin < end) {
					while (begin + 1 < end && nums[begin] == nums[begin + 1]
						&& end - 1 > begin && nums[end] == nums[end - 1]) {
							begin++;
							end--;
					}
					int sum = nums[i] + nums[begin] + nums[end];
					if (sum == 0) {
						res.emplace_back(vector<int>({ nums[i], nums[begin], nums[end] }));
						begin++;
						end--;
					}
					else if (sum < 0) begin++;
					else end--;
				}
			}

			return res;


















			//sort(nums.begin(), nums.end());

			//int len = nums.size();
			//vector<vector<int>> v;
			//// -4, -1, -1, 0, 1, 2
			//int i = 0;
			//while(i < len - 2) {
			//	int target = -1 * nums[i];
			//	int start = i + 1, end = len - 1;
			//	while (start < end) {
			//		int res = nums[start] + nums[end];
			//		if (res == target) {
			//			v.emplace_back(vector<int>({ nums[i], nums[start], nums[end] }));
			//			do { start++; } while (start < end && nums[start] == nums[start - 1]);
			//			do { end--; } while (start < end && nums[end] == nums[end + 1]);
			//		}
			//		else if (res < target) start++;
			//		else end--;
			//	}
			//	// i++;
			//	do { i++; } while (i < len && nums[i - 1] == nums[i]);
			//}
			//return v;
		}
	};

	void test() {
		Solution s;
		// vector<int> v({ -1,0,1,2,-1,-4 });
		vector<int> v({ -4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0 });
		// vector<int> v({ -2,0,1,1,2 });
		// vector<int> v({ 0,0,0 });
		// vector<int> v({ 1,1,-2 });
		// vector<int> v({ -2,0,0,2,2 });
		vector<vector<int>> res = s.threeSum(v);
		for (auto v : res) {
			for (int i : v) {
				cout << i << " ";
			}
			cout << endl;
		}
	}
}