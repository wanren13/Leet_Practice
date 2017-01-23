#pragma once

#include "allhead.h"

namespace count_primes {
	class Solution {
	public:
		int countPrimes(int n) {
		//	if (n <= 1) return 0;
		//	int res = 0;
		//	for (int i = 2; i <= n; i++) {
		//		if (isPrime(i)) res++;
		//	}
		//	return res;
		//}

		//bool isPrime(int n) {
		//	if (n == 2) return true;
		//	for (int i = 2; i < n; i++) {
		//		if (n % i == 0) {
		//			return false;
		//		}
		//	}
		//	return true;
		//}

			if (n <= 2) return 0;

			vector<bool> isPrime(n + 1, true);

			for (int i = 2; i * i < n; i++) {
				if (!isPrime[i]) continue;
				for (int j = i * i; j < n; j += i) {
					isPrime[j] = false;
				}
			}

			int res = 0;

			for (int i = 2; i < n; i++) {
				if (isPrime[i]) {
					res++;
					cout << i << " ";
				}
			}
			cout << endl;
			
			return res;
		}
	};

	void test() {
		Solution s;
		cout << "Number of prime numbers is " << s.countPrimes(10) << endl;
	}
}