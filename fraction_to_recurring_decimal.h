#pragma once

#include "allhead.h"

namespace fraction_to_recurring_decimal {
	class Solution {
	public:
		string fractionToDecimal(int numerator, int denominator) {
			if (numerator == 0) return "0";

			string res;

			if (numerator < 0 ^ denominator < 0) res += "-";

			int n = abs(numerator);
			int d = abs(denominator);

			res += to_string(n / d);

			long r = n % d;

			if (r == 0) return res;
			else res += ".";

			unordered_map<int, int> m;
			for (; r; r %= d) {
				if (m.find(r) != m.end()) {
					res.insert(m[r], 1, '(');
					res += ")";
					break;
				}

				m[r] = res.size();

				r *= 10;
				res += to_string(r / d);
			}

			return res;
		}
	};


	void test() {
		Solution sol;
		int n = 1;
		int d = 6;
		cout << sol.fractionToDecimal(n, d) << endl;
	}
}