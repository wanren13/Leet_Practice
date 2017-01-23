#pragma once

#include "allhead.h"

namespace knapsack {

	struct item {
		item() :w(0), v(0) {};
		item(int weight, int value) :w(weight), v(value) {};
		int w;
		int v;
		friend ostream& operator<<(ostream& os, const item& itm);
	};

	ostream& operator<<(ostream& os, const item& itm) {
		string str = "(" + to_string(itm.w) + "," + to_string(itm.v) + ")";
		os << str;
		return os;
	}

	void printItems(vector<item> v) {
		for (item i : v) {
			cout << "Value : " << i.v << " Weight: " << i.w << endl;
		}
	}

	//int knapsack(vector<item> items, int maxWeight) {
	//	if (items.size() == 0) {
	//		return 0;
	//	}
	//	else {
	//		int maxvalue = 0;
	//		for (int i = 0; i < items.size(); i++) {
	//			vector<item> tmp = items;
	//			item itm = items[i];
	//			tmp.erase(tmp.begin() + i);
	//			int val1 = 0, val2 = 0, value = 0;
	//			val1 = knapsack(tmp, maxWeight);
	//			if (maxWeight < itm.w)
	//				return val1;
	//			val2 = knapsack(tmp, maxWeight - itm.w) + itm.v;
	//			value = max(val1, val2);
	//			maxvalue = maxvalue > value ? maxvalue : value;
	//		}
	//		return maxvalue;
	//	}
	//}


	void printValues(const vector<vector<int>>& values, const vector<item>& items, int maxWeight) {
		cout << setw(10) << " ";

		for (int i = 0; i <= maxWeight; i++) {
			cout << left << setw(3) << i;
		}
		cout << endl;

		for (int i = 0; i < values.size(); i++) {
			if (i > 0) {
				cout << left << setw(10) << items[i - 1];
			}
			else {
				cout << setw(10) << " ";
			}
			vector<int> vals = values[i];
			for (int j : vals) {
				cout << left << setw(3) << j;
			}
			cout << endl;
		}
	}


	int knapsack(vector<item> items, int maxWeight) {

		vector<int> vals(maxWeight + 1, 0);
		vector<vector<int>> values(items.size() + 1, vals);

		if (items.size() == 0)
			return 0;
		else {
			for (int i = 0; i < items.size(); i++) {
				for (int w = 1; w <= maxWeight; w++) {
					item itm = items[i];
					values[i + 1][w] = itm.w > w ?
						values[i][w] :
						max(values[i][w], values[i][w - itm.w] + itm.v);
				}
			}
		}

		printValues(values, items, maxWeight);

		int i = items.size();
		int j = maxWeight - 1;

		vector<int> itemset(items.size(), 0);
		int maxVal = values.back().back();
		while (i > 0) {
			/*	if (values[i][j] == values[i - 1][j]) {
			i--;
			}
			else if (values[i][j] == values[i][j - 1]){
			j--;
			}
			else {
			itemset[i - 1] = 1;
			j -= items[i - 1].w;
			i--;
			}*/
			if (values[i][j] == values[i - 1][j]) {
				i--;
			}
			else {
				itemset[i - 1] = 1;
				j -= items[i - 1].w;
			}



		}

		cout << "Item chosen: ";
		for (int i : itemset) {
			cout << i << " ";
		}
		cout << endl;

		return maxVal;
	}



	void test() {
		//freopen("data.txt", "r", stdin);

		//int n, C;

		//while (scanf("%d %d", &n, &C) != EOF) {
		//	for (int i = 0; i<n; ++i)	scanf("%d %d", &V[i], &W[i]);

		//	for (int i = 0; i <= n; ++i) {
		//		for (int j = 0; j <= C; ++j) {
		//			d[i][j] = i == 0 ? 0 : d[i - 1][j];
		//			if (i>0 && j >= V[i - 1])	
		//				d[i][j] = max(d[i -1][j], d[i - 1][j - V[i - 1]] + W[i - 1]);
		//		}
		//	}
		//	printf("%d\n", d[n][C]);
		//}
		//fclose(stdin);
	}
}