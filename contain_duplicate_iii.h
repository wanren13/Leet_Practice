#pragma once

#include "allhead.h"

namespace contain_duplicate_iii {
	//class Solution {
	//public:
	//	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	//		multimap<int, int> m;
	//		k = abs(k); t = abs(t);
	//		for (int i = 0; i < nums.size(); i++) {
	//			auto itlo = m.lower_bound(nums[i] - t);
	//			auto itup = m.upper_bound(nums[i] + t);
	//			for (auto it = itlo; it != itup; it++) {
	//				if (i - it->second <= k) return true;
	//			}
	//			m.insert(make_pair(nums[i], i));
	//		}
	//		return false;
	//	}
	//};


	class Solution {
	public:
		bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
			set<int> s;
			for (int i = 0; i < nums.size(); i++) {
				auto lb = s.lower_bound(nums[i] - t);
				if (lb != s.end() && *lb - nums[i] <= t) return true;
				if (i >= k) s.erase(nums[i - k]);
				s.insert(nums[i]);
			}

			return false;
		}
	};


	void test() {
		vector<int> nums(
			// {-1, -1}
		{ 0,1 }
		);
		int k = 0;
		int t = 1;
		Solution sol;
		cout << sol.containsNearbyAlmostDuplicate(nums, k, t) << endl;
		
	}
}