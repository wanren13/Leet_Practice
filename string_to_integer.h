#pragma once

#include "allhead.h"

namespace string_to_integer {
	class Solution {
	public:
		int myAtoi(string str) {
			long long result = 0;
			if (str.empty()) return (int)result;
			int base = 10;
			int len = str.length();
			int d = 0;
			int decimal_index = len, digit_index = -1, sign_index = -1;
			long long sign = 1;
			for (int i = 0; i < len; i++) {
				if (decimal_index == len && str[i] == '.') {
					decimal_index = i;
				}
				if (digit_index != -1 && !isdigit(str[i])) {
					decimal_index = i;
					break;
				}
				if (sign_index == -1 && (str[i] == '+' || str[i] == '-')) {
					if (str[i] == '-') sign = -1;
					sign_index = i;
				}
				if (digit_index == -1 && sign_index == -1 && !isdigit(str[i])) {
					if (str[i] != ' ')
						return 0;
				}
				if (digit_index != -1 && !isdigit(str[i])) {
					decimal_index = i;
				}
				if (digit_index == -1 && isdigit(str[i])) {
					digit_index = i;
				}
			}

			//cout << "decimal_index: " << decimal_index << endl;
			//cout << "digit_index: " << digit_index << endl;
			//cout << "sign_index: " << sign_index << endl;
			//cout << "sign: " << sign << endl;

			if (digit_index == -1 || (sign_index != -1 && digit_index - sign_index != 1)) return 0;
			//int num_digits = decimal_index - digit_index;

			for (int i = digit_index; i < decimal_index; i++) {
				d = str[i] - '0';
				result += (long long)d * pow(base, decimal_index - i - 1) * sign;
				if (result >(long long)INT_MAX) return INT_MAX;
				if (result < (long long)INT_MIN) return INT_MIN;
			}

			return (int)result;
		}
	};

	void test() {
		Solution s;
		string str = "18446744073709551617";
		cout << s.myAtoi(str) << endl;
		// int n1 = 2147483640;
		// int n2 = 8;
		//long long n1 = 2147483640;
		//long long n2 = 8;
		//long long n3 = n1 + n2;
		//cout << n1 << endl;
		//cout << n1 + n2 << endl;
		//cout << n3 << endl;
		//cout << sizeof(long long) << endl;

	}
}