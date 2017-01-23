#pragma once

#include "allhead.h"

namespace array_addone {
	class Solution {
	public:
		vector<int> addOne(vector<int> v, int base) {
			bool carry = false;
			for (int i = v.size() - 1; i >= 0; i--) {
				carry = (v[i] + 1 == base);
				if (carry) {
					v[i] = 0;
				}
				else {
					v[i]++;
					break;
				}
			}

			if (carry) {
				v.insert(v.begin(), 1);
			}

			return v;
		}
	};

	void test() {
		Solution s;
		vector<int> v;

		int n = 20, base = 4;
		for (int i = 0; i < n; i++) {
			int num = rand() % base;
			while (i == 0 && num == 0) num = rand() % base;
			v.emplace_back(num);
		}

		for (int i : v) {
			cout << i;
		}
		cout << endl;

		vector<int> vchange = s.addOne(v, base);

		for (int i : vchange) {
			cout << i;
		}
		cout << endl;
	}
}