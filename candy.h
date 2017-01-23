#pragma once

#include "allhead.h"

namespace candy {
	class Solution {
	public:
		int candy(vector<int>& ratings) {
			if (ratings.empty()) return 0;
			int left = 1, right = 1;
			int leftcandy = 0, rightcandy = 0;

			int i = 1;
			while (i < ratings.size()) {
				if (ratings[i] >= ratings[i - 1]) {
					if (ratings[i] > ratings[i - 1]) left++;
					leftcandy += left;
				}
				else {
					leftcandy -= left;
					left = 1;
				}
				i++;
			}

			i = ratings.size() - 1;
			while (i > 0) {
				if (ratings[i - 1] >= ratings[i]) {
					if (ratings[i - 1] > ratings[i]) right++;
					rightcandy += right;
				}
				else right = 1;
				i--;
			}


			return leftcandy + rightcandy;
		}
	};

	void test() {

	}
}