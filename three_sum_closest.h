#pragma once

#include "allhead.h"

namespace three_sum_closest {
	class Solution {
	public:
		int threeSumClosest(vector<int>& nums, int target) {

			sort(nums.begin(), nums.end());
			int closest = 0, diff = INT_MAX, i = 0, n = nums.size();
			while (i < n - 2) {
				int begin = i + 1, end = n - 1;
				while (begin < end) {
					int sum = nums[i] + nums[begin] + nums[end];
					if (sum == target) return sum;
					else if (sum > target) do { end--; } while (begin < end && nums[end] == nums[end + 1]);
					else do { begin++; } while (begin < end && nums[begin] == nums[begin - 1]);
					int d = max(sum, target) - min(sum, target);
					if (d < diff) {
						diff = d;
						closest = sum;
					}
				}
				do { i++; } while (i < n - 2 && nums[i] == nums[i - 1]);
			}
			return closest;














			//sort(nums.begin(), nums.end());

			//// priority_queue<int, vector<int>, greater<int>> pq;
			//map<int, int> m;
			//int len = nums.size();
			//// vector<int> nums({ 1,2,4,8,16,32,64,128 });
			//int i = 0, start, end;
			//while (i < len - 2) {
			//	start = i + 1;
			//	end = len - 1;
			//	int needle = target - nums[i];
			//	while (start < end) {
			//		int sum = nums[start] + nums[end];
			//		if (sum == needle) return target;
			//		else if (sum < needle) start++; // do { start++; } while (start + 1 < len && nums[start + 1] == nums[start]);
			//		else end--; // do { end--; } while (end - 1 >= 0 && nums[end - 1] == nums[end]);
			//		m[abs(needle - sum)] = sum + nums[i];
			//	}
			//	i++;
			//}

			//return m.begin()->second;
		}
	};

	void test() {
		Solution s;
		// vector<int> nums({ -1,2,1,-4 });
		// vector<int> nums({ 1,1,1,0 });
		// vector<int> nums({ 1,2,4,8,16,32,64,128 });
		vector<int> nums({ 13,2,0,-14,-20,19,8,-5,-13,-3,20,15,20,5,13,14,-17,-7,12,-6,0,20,-19,-1,-15,-2,8,-2,-9,13,0,-3,-18,-9,-9,-19,17,-14,-19,-4,-16,2,0,9,5,-7,-4,20,18,9,0,12,-1,10,-17,-11,16,-13,-14,-3,0,2,-18,2,8,20,-15,3,-13,-12,-2,-19,11,11,-10,1,1,-10,-2,12,0,17,-19,-7,8,-19,-17,5,-5,-10,8,0,-12,4,19,2,0,12,14,-9,15,7,0,-16,-5,16,-12,0,2,-16,14,18,12,13,5,0,5,6 });
		int target = -59;
		cout << s.threeSumClosest(nums, target) << endl;
	}
}