#pragma once

#include "allhead.h"

namespace coin_change {
	class Solution {
	public:
		int coinChange(vector<int>& coins, int amount) {
			if (amount == 0) return 0;
			if (coins.empty()) return -1;
			vector<int> amts(amount, INT_MAX);
			sort(coins.begin(), coins.end());

			for (int i : coins) {
				if (i - 1 < amount) amts[i - 1] = 1;
			}

			for (int i = 0; i < amount; i++) {
				if (amts[i] != 1) {
					int n = -1;
					for (int j : coins) {
						if (i >= j) {
							int amt = amts[i - j];
							if (amt == -1) continue;
							amts[i] = min(amts[i], amts[i - j] + 1);
							n = amts[i];
						}
					}
					amts[i] = n;
				}
			}

			//for (int i : amts) cout << i << endl;

			return amts[amount - 1];
		}
	};

	void test() {
		vector<int> coins(
		// { 2147483647 }
		{186, 419, 83, 408}
			);
		int amount = 6249;

		Solution sol;

		cout << sol.coinChange(coins, amount);
	}
}