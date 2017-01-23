#pragma once

#include "allhead.h"

namespace best_time_to_buy_and_sell_stock_ii {
	class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			int maxp = 0;
			for (int i = 0; i < prices.size() - 1; i++) {
				if (prices[i + 1] > prices[i]) maxp += prices[i + 1] - prices[i];
			}

			return maxp;
		}
	};

	void test() {
		Solution sol;
		vector<int> prices;
		cout << sol.maxProfit(prices) << endl;

	}
}