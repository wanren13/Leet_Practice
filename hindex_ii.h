#pragma once

#include "allhead.h"

namespace hindex_ii {
	class Solution {
	public:
		int hIndex(vector<int>& citations) {
			// int h = 0;
			// int size = citations.size();
			// while (h < size && citations[size - 1 - h] > h) h++;

			// return h;


			int start = 0, end = citations.size() - 1, mid;
			int h = 0, tmp = 0;
			if (end == -1) return h;
			// 1, 4, 7, 9
			while (start <= end) {
				mid = start + (end - start) / 2;
				tmp = citations.size() - mid;
				if (citations[mid] == tmp) return tmp;
				else if (citations[mid] < tmp)
					start = mid + 1;
				else {
					h = tmp;
					end = mid - 1;
				}
			}

			return citations[mid] == 0 ? 0 : h;
		}
	};

	void test() {
		Solution sol;
		vector<int> citations(
		//{ 1,4,5,7,9 }
		{0,0, 100}
		);
		cout << sol.hIndex(citations) << endl;
	}
}