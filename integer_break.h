#pragma once

#include "allhead.h"

namespace integer_break {
	class Solution {
	public:
		int integerBreak(int n) {
			static vector<int> res({ 0, 1 });
			// priority_queue<int> q;
			int size = res.size();
			while (size < n + 1) {
				int maxproduct = INT_MIN;
				for (int i = 1; i <= size / 2; i++) {
					int j = size - i;
					maxproduct = max(i * j, max(maxproduct, i * res[j]));
				}
				res.emplace_back(maxproduct);
				size++;
			}

			for (int i : res) {
				cout << i << endl;
			}

			return res[n];
		}
	};
	
	
	void test() {
		Solution sol;
		cout << sol.integerBreak(14) << endl;
	}
}