#pragma once

#include "allhead.h"

namespace two_sum {
	//class Solution {
	//public:
	//	vector<int> twoSum(vector<int>& nums, int target) {
	//		// sort(nums.begin(), nums.end());
	//		vector<int> res(2, 0);
	//		/*int i, j;
	//		bool found = false;
	//		for (i = 0; i < nums.size() - 1; i++) {
	//		    for (j = i + 1; j < nums.size(); j++) {
	//		        if ((nums[i] + nums[j]) == target) {
	//		            found = true;
	//		            break;
	//		        }
	//		    }
	//		    if (found) break;
	//		}

	//		res[0] = i;
	//		res[1] = j;*/

	//		unordered_map<int, int> m;
	//		for (int i = 0; i < nums.size(); i++) {
	//			m[nums[i]] = i;
	//		}

	//		for (int i = 0; i < nums.size(); i++) {
	//			int ftar = target - nums[i];
	//			unordered_map<int, int>::iterator iter = m.find(ftar);
	//			if (iter != m.end() && m[ftar] != i) {
	//				res[0] = i;
	//				res[1] = m[ftar];
	//				break;
	//			}
	//		}

	//		return res;
	//	}
	//};

	class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			unordered_map<int, int> m;
			vector<int> res;
			for (int i = 0; i < nums.size(); i++) m[nums[i]] = i;
			for (int i = 0; i < nums.size(); i++) {
				int n = target - nums[i];
				if (m.find(n) != m.end() && m[n] > i) {
					res.emplace_back(i);
					res.emplace_back(m[n]);
					break;
				}
			}
			return res;
		}
	};


	void test() {
		Solution s;
		vector<int> nums({ 3,2,4 });
		int target = 6;
		vector<int> res = s.twoSum(nums, target);
		for (int i : res) {
			cout << i << " ";
		}
		cout << endl;
	}
}