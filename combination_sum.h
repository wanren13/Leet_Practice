#pragma once

#include "allhead.h"

namespace combination_sum {
	class Solution {
	public:
		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			vector<vector<int>> res;
			int len = candidates.size();
			if (len == 0) return res;
			sort(candidates.begin(), candidates.end());
			
			int i = 0, j = 0;
			// deque<int> d;
			// vector<int> v;

			// int sum = 0;
			/*
			while (i < len) {
				int n = candidates[i];
				if (sum < target) {
					d.emplace_back(n);
					sum += n;
				}
				else {
					if (sum == target) {
						res.emplace_back(d.begin(), d.end());
					}
					int front = d.front();
					if (front == n) i++;
					sum -= front;
					d.pop_front();
				}
			}
			//*/
			int sum = 0;

			while (i < len) {
				vector<int> self;
				sum = 0;
				int max = 0;
				while (sum < target) {
					sum += candidates[i];
					self.emplace_back(candidates[i]);
					max++;
				}
				if (sum == target) res.emplace_back(self);

				vector<int> v;
				sum = 0;
				for (int j = 1; j < max; j++) {
					sum += candidates[i];
					v.emplace_back(candidates[i]);
				}


				j = i + 1;
				while (j < len) {
					sum = 0;
					while (sum < target) {

					}
				}
			}




			return res;
		}
	};

	void test () {
		vector<int> candidates(
		//	{2,3,6,7}
			{2,3,5}
		);

		int target = 7;

		Solution sol;
		vector<vector<int>> res = sol.combinationSum(candidates, target);

		for (auto v : res) {
			for (int i : v) {
				cout << i << " ";
			}
			cout << endl;
		}
	}
}