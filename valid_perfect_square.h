#pragma once

#include "allhead.h"

namespace valid_perfect_square {
	// class Solution {
	// public:
	//     bool isPerfectSquare(int num) {
	//         if (num < 1) return false;
	//         int i = 1;
	//         while (num > 0) {
	//             num -= i;
	//             i += 2;
	//         }

	//         return num == 0;
	//     }
	// };


	class Solution {
	public:
		bool isPerfectSquare(int num) {
			if (num < 1) return false;
			int begin = 1, end = num;
			while (begin <= end) {
				long long mid = begin + (end - begin) / 2;
				long long sqr = mid * mid;
				if (sqr == num) return true;
				else if (sqr < num) end = mid - 1;
				else begin = mid + 1;
			}

			return false;
		}
	};

	void test() {
		Solution sol;
		int num = 9;
		cout << sol.isPerfectSquare(num) << endl;
	}
}