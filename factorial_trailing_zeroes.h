#pragma once

#include "allhead.h"

namespace factorial_trailing_zeroes {
	class Solution {
	public:
		int trailingZeroes(int n) {
			// int tmp = n;
			// int p = -1;
			// while (tmp) {
			//     tmp /= 5;
			//     p++;
			// }

			// // 5 * X + 1
			// vector<int> zeros(p + 1, 0);
			// vector<int> nums(p + 1, 1);
			// int cnt = 1;
			// while (cnt <= p) {
			//     nums[cnt] = nums[cnt - 1] * 5;
			//     zeros[cnt] = zeros[cnt - 1] * 5 + 1;
			//     cnt++;
			// }

			// int res = 0;

			// while (n) {
			//     int r = n / nums[p];
			//     res += r * zeros[p];
			//     n = n % nums[p];
			//     p--;
			// }

			// return res;


			int res = 0;
			int r = 1;
			int d = 5;
			while (r > 4) {
				r = n / d;
				res += r;
				d *= 5;
			}

			return res;
		}
	};

	void test() {
		//Solution sol;
		//int n = 2147483647;
		//cout << sol.trailingZeroes(n) << endl;

		string str = "abc efg d\nff b\"jf    dfd fd\tfd";

		istringstream in(str);
		int i = 0;
		string word;
		while(in >> word) {
			cout << word << " " << i++ << endl;
		}
	}
}