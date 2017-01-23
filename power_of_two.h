#pragma once

#include "allhead.h"

namespace power_of_two {
	class Solution {
	public:
		bool isPowerOfTwo(int n) {
			if (n <= 0) return false;
			return !(n&(n - 1));
		}
	};

	void test() {
		int n = 1;
		cout << ((n / (n >> 1) == 2) ? "True" : "False") << endl;
	}
}