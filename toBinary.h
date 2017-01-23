#pragma once

#include "allhead.h"

namespace toBinary {

	string toBinary(int n) {

		string s = string();
		string one = "1";
		string zero = "0";

		while (n) {
			s.insert(0, n % 2 == 0 ? zero : one);
			n /= 2;
		}
		return s;
	}

	void test() {

	}
}