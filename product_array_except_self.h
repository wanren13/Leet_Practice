#pragma once

#include "allhead.h"

namespace product_array_except_self {
	class Solution {
	public:
		vector<int> productExceptSelf(vector<int>& nums) {
			int n = nums.size();
			vector<int> v(n, 1);

			// int prod = 1, zerocount = 0;
			// for (int i : nums) {
			//     if (i == 0) zerocount++; 
			//     else prod *= i;
			// }

			// for (int i : nums) {
			//     if (zerocount > 0) {
			//         if (i == 0 && zerocount == 1) {
			//             v.emplace_back(prod);
			//         }
			//         else
			//             v.emplace_back(0);
			//     }
			//     else {
			//         v.emplace_back(prod / i);
			//     }
			// }


			for (int i = 1; i < n; i++) {
				v[i] = v[i - 1] * nums[i - 1];
			}

			int right = 1;

			for (int i = n - 2; i >= 0; i--) {
				v[i] = right * v[i + 1];
				right *= nums[i + 1];
			}

			return v;
		}
	};

	void test() {
		vector<int> v({ 0,0 });
		Solution s;
		vector<int> res;

		res = s.productExceptSelf(v);

		for (auto i : res) {
			cout << i << " ";
		}

		cout << endl;
	}
}