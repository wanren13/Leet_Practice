#pragma once

#include "allhead.h"

namespace practice {
	void test() {
		vector<int> v({ 1,2,3,4,5,6,7,8 });
		auto first = v.begin(), next = v.begin() + 1, last = v.end();
		auto middle = next;
		while (first != next)
		{
			swap(*first++, *next++);
			if (next == last) next = middle;
			else if (first == middle) middle = next;
		}

		for (auto i : v) cout << i << " ";
		cout << endl;
	}
}