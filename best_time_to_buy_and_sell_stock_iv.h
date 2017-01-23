#pragma once

#include "allhead.h"

namespace best_time_to_buy_and_sell_stock_iv {
	class Solution {
	public:
		int maxProfit(int k, vector<int>& prices) {
			priority_queue<int> profits;
			int begin = 0, end = 0;
			while (end < prices.size()) {
				while (end + 1 < prices.size() && prices[end + 1] >= prices[begin]) end++;
				if (end > begin) profits.push(prices[end] - prices[begin]);
				begin = ++end;
			}

			int maxProfit = 0;
			while (!profits.empty() && k-- > 0) {
				maxProfit += profits.top();
				profits.pop();
			}

			return maxProfit;
		}
	};




	void test() {
		Solution sol;
		int k = 3;
		vector<int> prices(
		{ 3, 2, 4, 1, 5, 2 }
		);

		cout << sol.maxProfit(k, prices) << endl;
	}
}