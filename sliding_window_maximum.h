#pragma once

#include "allhead.h"

namespace sliding_window_maximum {
	//class Solution {
	//public:
	//	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	//		deque<int> buffer;
	//		vector<int> res;

	//		for (auto i = 0; i < nums.size(); ++i)
	//		{
	//			while (!buffer.empty() && nums[i] >= nums[buffer.back()]) buffer.pop_back();
	//			buffer.push_back(i);

	//			if (i >= k - 1) res.push_back(nums[buffer.front()]);
	//			if (buffer.front() <= i - k + 1) buffer.pop_front();
	//		}
	//		return res;
	//	}
	//};


	class Solution {
	public:
		vector<int> maxSlidingWindow(vector<int>& nums, int k) {
			deque<int> dq;
			vector<int> res;
			int begin = 0, end = 0;

			for (end = 0; end < k; end++) {
				while (!dq.empty() && nums[dq.back()] < nums[end]) dq.pop_back();
				dq.push_back(end);
			}

			while (end < nums.size()) {
				res.emplace_back(nums[dq.front()]);
				while (!dq.empty() && nums[dq.back()] < nums[end]) dq.pop_back();
				dq.push_back(end);
				end++; begin++;
				if (!dq.empty() && dq.front() < begin) dq.pop_front();
			}

			return res;
		}
	};


	void test() {
		vector<int> num({ 1,3,-1,-3,5,3,6,7 });
		int k = 3;
		Solution sol;
		vector<int> res = sol.maxSlidingWindow(num, k);
		for (int i : res) cout << i << " ";
		cout << endl;
	}

}