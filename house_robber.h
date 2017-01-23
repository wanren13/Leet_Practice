#pragma once
#include <vector>
#include <iostream>

using namespace std;

namespace house_robber {
	class Solution {
	public:
		int rob(vector<int>& nums) {
			if (nums.empty()) {
				return 0;
			}

			vector<int> maxrob(nums.size(), 0);
			for (int i = 0; i < nums.size(); i++) {
				if (i == 0)      maxrob[i] = nums[i];
				else if (i == 1) maxrob[i] = max(nums[0], nums[1]);
				else             maxrob[i] = max(maxrob[i - 1], maxrob[i - 2] + nums[i]);
			}
			return maxrob.back();
		}
	};

	void test() {
		vector<int> v;
		v.push_back(1);
		v.push_back(3);
		v.push_back(4);
		v.push_back(2);
		v.push_back(5);
		v.push_back(7);

		Solution s;
		cout << "Max rob is " << s.rob(v) << endl;

	}
}