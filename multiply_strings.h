#pragma once

#include "allhead.h"

namespace multiply_strings {


	class Solution {
	public:
		string multiply(string num1, string num2) {
			if (num1 == "0" || num2 == "0") return "0";
			int len1 = num1.length(), len2 = num2.length(), off = 0;
			string res;
			if (num1[0] == '-' ^ num2[0] == '-') {
				res = "-";
				off = 1;
			}
			for (int i = 0; i < len1; i++) {
				if (num1[len1 - 1 - i] == '-') continue;
				int n1 = num1[len1 - 1 - i] - '0';
				int carry = 0;
				for (int j = 0; j < num2.length(); j++) {
					if (num1[len1 - 1 - i] == '-') continue;
					int n2 = num2[len2 - 1 - j] - '0';
					int nn = res.length() > i + j + off ? res[i + j + off] - '0' : 0;
					int n = (n1 * n2 + carry + nn) % 10;
					carry = (n1 * n2 + carry + nn) / 10;
					if (res.length() > i + j + off) res[i + j + off] = '0' + n;
					else res.push_back('0' + n);
				}
				if (carry != 0) res.push_back('0' + carry);
			}

			if (res[0] == '-') reverse(res.begin() + 1, res.end());
			else reverse(res.begin(), res.end());

			return res;
		}
	};



	//class Solution {
	//public:
	//	string multiply(string num1, string num2) {
	//		string res;
	//		int len1 = num1.length(), len2 = num2.length();
	//		if ((len1 == 1 && num1[0] == 0) || (len2 == 1 && num2[0] == 0)) return to_string(0);
	//		for (int i = 0; i < len1; i++) {
	//			int n1 = num1[len1 - 1 - i] - '0', k = 0, carry = 0;
	//			bool newdigit = true;

	//			for (int j = 0; j < num2.length(); j++) {
	//				int n2 = num2[len2 - 1 - j] - '0';

	//				k = i + j;
	//				newdigit = k >= res.length();

	//				int d = newdigit ? 0 : (res[k] - '0');

	//				int n = carry + d + n1 * n2;
	//				
	//				carry = n / 10;
	//				n = n % 10;
	//				char ch = '0' + n;
	//				if (newdigit) res.append(1, ch);
	//				else res[k] = ch;
	//			}
	//			if (carry) {
	//				char ch = '0' + carry;
	//				if (k + 1 < res.length()) res[k + 1] = ch;
	//				else res.append(1, ch);
	//			}
	//		}
	//		reverse(res.begin(), res.end());
	//		return res;
	//	}
	//};

	void test() {
		Solution sol;
		string num1 = "-1";
		string num2 = "123";
		string res = sol.multiply(num1, num2);

		cout << res << endl;
	}
}