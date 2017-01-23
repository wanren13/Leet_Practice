#pragma once

#include "allhead.h"

namespace find_smallest_base {
	class Solution {
	public:
		vector<int> smallestbase (int n) {
			vector<int> v(n, 0);
			for (int i = 0; i < n; i++) {
				int base = 2;
				for (;;) {
					if (i < base) {
						v[i] = base;
						break;
					}
					if (i % base != 0) {
						if (isPalidrome(baseConvertion(i, base))) {
							v[i] = base;
							break;
						}
					}
					base++;
				}
			}
			return v;
		}

		vector<int> baseConvertion(int n, int base) {
			vector<int> num;
			while (n) {
				int d = n % base;
				num.insert(num.begin(), d);
				n = n / base;
			}
			return num;
		}



	//private:
		bool isPalidrome(vector<int> num) {
			int len = num.size();
			for (int i = 0; i < len; i++) {
				if (num[i] != num[len - 1 - i])
					return false;
			}
			return true;
		}
	};

	void test() {
		Solution s;
		// vector<int> bases = s.smallestbase(10000);
		vector<int> converted = s.baseConvertion(9997, 37);
		
		//int count = 0;
		//for (int i : bases) {
		//	cout << count++ << ":\t" << i << endl;
		//}
		
		// cout << bases[9997];
		cout << endl;
	}
}