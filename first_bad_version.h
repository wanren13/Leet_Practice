#pragma once

#include "allhead.h"

namespace first_bad_version {
	// Forward declaration of isBadVersion API.
	bool isBadVersion(int version)
	{	
		int v = 6;
		return version >= v;
	}


	class Solution {
	public:
		int firstBadVersion(int n) {
			int start = 1, mid, end = n;
			while (start < end) {
				mid = start + (end - start) / 2;
				if (isBadVersion(mid)) end = mid - 1;
				else start = mid + 1;
			}
			return isBadVersion(start) ? start : start + 1;
		}
	};

	void test() {
		Solution sol;
		int n = 8;
		cout << sol.firstBadVersion(n) << endl;
	}
}