#pragma once

#include "allhead.h"

namespace add_binary {
	//class Solution {
	//public:
	//	string addBinary(string a, string b) {
	//		int base = 2;
	//		int len1 = a.length() - 1;
	//		int len2 = b.length() - 1;
	//		char c1 = '0', c2 = '0';
	//		int d1 = 0, d2 = 0, d3 = 0, carrybit = 0;
	//		bool carry = false;
	//		string res;
	//		while (len1 > -1 || len2 > -1) {
	//			if (len1 > -1) {
	//				d1 = a[len1] - '0';
	//				len1--;
	//			}
	//			else {
	//				d1 = 0;
	//			}
	//			if (len2 > -1) {
	//				d2 = b[len2] - '0';
	//				len2--;
	//			}
	//			else {
	//				d2 = 0;
	//			}
	//			d3 = d1 + d2 + carrybit;
	//			carry = (d3 >= base);
	//			if (carry) {
	//				d3 = d3 - base;
	//				carrybit = 1;
	//			}
	//			else {
	//				carrybit = 0;
	//			}
	//			res.insert(res.begin(), '0' + d3);
	//		}
	//		if (carry) res.insert(res.begin(), '0' + 1);
	//		return res;
	//	}
	//};


	class Solution {
	public:
		string addBinary(string a, string b) {
			int i = a.length() - 1, j = b.length() - 1, carry = 0;
			string res;
			while (i >= 0 || j >= 0 || carry) {
				int n1 = i < 0 ? 0 : (a[i--] - '0');
				int n2 = j < 0 ? 0 : (b[j--] - '0');
				int sum = n1 + n2 + carry;
				carry = sum / 2;
				res.push_back(sum % 2 + '0');
			}

			reverse(res.begin(), res.end());
			return res;
		}
	};


	void test() {
		Solution s;
		string num1 = "0"; //"110101";
		string num2 = "0"; //"10110";
		cout << s.addBinary(num1, num2) << endl;


	}
}