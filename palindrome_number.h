#pragma once

#include "allhead.h"

namespace palindrome_number {
	//class Solution {
	//public:
	//	bool isPalindrome(int x) {
	//		//if (x < 0) return false;
	//		//int left, right;

	//		//int tens = 1;
	//		//int digits = 1;

	//		//while (tens < 100000001 && x / (10 * tens)) {
	//		//	tens *= 10;
	//		//	digits++;
	//		//}

	//		//int ln = x, rn = x;

	//		//while (digits > 0) {
	//		//	left = ln / tens;
	//		//	ln = ln % tens;
	//		//	tens /= 10;
	//		//	right = rn % 10;
	//		//	rn /= 10;
	//		//	if (left != right) return false;
	//		//	digits -= 2;
	//		//}

	//		//return true;


	//		int sum = 0;
	//		int n = x;
	//		while (n) {
	//			sum = sum * 10 + n % 10;
	//			n /= 10;
	//		}

	//		cout << sum << endl;

	//		return sum == n;


	//	}
	//};


	class Solution {
	public:
		bool isPalindrome(int x) {
			if (x < 0) return false;
			long re = 0;
			while (x) {
				re = 10 * re + x % 10;
				x /= 10;
			}
			return re == x;
		}
	};

	void test() {
		Solution sol;
		int x = 1410110141;
		cout << "Is" << (sol.isPalindrome(x) ? " " : " not ") << "palindrome number" << endl;
	}
}