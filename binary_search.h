#pragma once

#include "allhead.h"

namespace binary_search {
	
	bool binary(vector<int> v, int target) {
		int start = 0, end = v.size() - 1;
		
		// 0, 1

		while (start <= end) {
			int mid = start + (end - start) / 2;
			if (v[mid] == target) return true;
			else if (v[mid] > target) end = mid - 1;
			else start = mid + 1;
		}
		return false;
	}
		
	void test() {
		vector<int> v;

		for (int i = 0; i < 100; i++) {
			int n = rand() % 1000 + 1;
			v.emplace_back(n);
		}

		sort(v.begin(), v.end());

		cout << "Array is :" << endl;
		for (int i : v) {
			cout << i << " ";
		}
		cout << endl;

		while (1) {
			cout << "Input a number to search: ";
			int n;
			cin >> n;
			cout << (binary(v, n) ? "True" : "False") << endl;;
		}
	}
}