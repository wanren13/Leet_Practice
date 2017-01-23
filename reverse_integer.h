#pragma once

#include "allhead.h"

namespace reverse_integer {
	//class Solution {
	//public:
	//	int reverse(int x) {
	//		int sign = (x < 0) ? -1 : 1;
	//		int result = 0, d = 0, base = 1, count = 0;
	//		vector<int> v;
	//		while (x) {
	//			count++;
	//			d = x % 10;
	//			v.emplace_back(abs(d));
	//			x /= 10;
	//		}

	//		if (count > 10) return 0;

	//		for (int i : v) {
	//			int fact = pow(10, --count);
	//			if (i * (fact / 10) + result / 10 > INT_MAX / 10
	//				|| (i * (fact / 10) + result / 10 == INT_MAX / 10 && v.back() > 7))
	//				return 0;
	//			result += i * fact;
	//		}

	//		return result * sign;
	//	}
	//};


	class Solution {
	public:
		int reverse(int x) {
			long res = 0;
			while (x) {
				res = res * 10 + x % 10;
				x /= 10;
			}
			return res > INT_MAX ? 0 : res;
		}
	};
	void test() {
		Solution s;
		int n = 1534236469;
		cout << s.reverse(123) << endl;
		cout << s.reverse(n) << endl;
	}
}