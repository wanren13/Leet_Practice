#pragma once

#include "allhead.h"

namespace zigzag_conversion {
	class Solution {
	public:
		string convert(string s, int numRows) {
			if (numRows < 2) return s;
			string res;
			vector<string> v(numRows);
			int row = 0, nextrow = 1;
			for (char c : s) {
				v[row] += c;
				row += nextrow;
				nextrow = row == numRows ? -1 : row == 0 ? 1 : nextrow;
			}
			for (string str : v) res += str;

			return res;
		}
	};

	void test() {
		string s = "PAYPALISHIRING";
		int numRows = 3;
		Solution sol;
		cout << sol.convert(s, numRows) << endl;
	}
}