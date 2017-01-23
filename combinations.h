#pragma once

#include "allhead.h"

namespace combinations {
	//class Solution {
	//public:
	//	vector<vector<int>> combine(int n, int k) {
	//		vector<vector<int>> res;
	//		
	//		for (int i = 1; i <= n; i++)
	//			combinationUtility(res, vector<int>(), i, n, k);
	//		
	//		
	//		/*
	//		int first = 1;
	//		int offset = 1;

	//		vector<int> v;
	//		for (int i = 1; i < n; i++) {
	//			for (int inc = 0; inc < n - i; inc++) {
	//				for (int j = 0; j < k; j++) {
	//					int num = i + k;
	//					v.emplace_back(num);
	//				}
	//			}
	//		}
	//		res.emplace_back(v);
	//		first += offset;
	//		




	//		for (int i = 1; i < n; i++) {
	//			for (int inc = 0; inc < n - i; inc++) {
	//				for (int j = 0; j < k; j++) {
	//					int num = i + k;
	//					v.emplace_back(num);
	//				}
	//			}
	//		}


	//		int first = 1, curr = 1;
	//		int len = 1;
	//		while (first <= n) {
	//			curr = first;
	//			while (curr <= n) {
	//				v.emplace_back(curr);


	//				
	//			}
	//			first++;
	//		}





	//		//*/
	//		
	//		return res;
	//		
	//	}

	//	void combinationUtility(vector<vector<int>>& comb, vector<int> v, int start, int n, int len) {
	//		int size = v.size();
	//		if (size == len) {
	//			comb.emplace_back(v);
	//			return;
	//		}
	//		v.emplace_back(start);
	//		for (int i = start + 1; i <= n; i++) {
	//			// if (n - i + 1 >= len - size) 
	//				combinationUtility(comb, v, i, n, len);
	//		}
	//	}



	//};
	
	class Solution {
	public:
		vector<vector<int>> combine(int n, int k) {
			vector<vector<int>> res;
			vector<int> comb;
			helper(res, comb, 1, n, k);
			return res;
		}

		void helper(vector<vector<int>>& res, vector<int>& comb, int start, int& n, int& k) {
			if (comb.size() == k) {
				res.emplace_back(comb);
				return;
			}
			for (int i = start; i <= n; i++) {
				comb.emplace_back(i);
				helper(res, comb, i + 1, n, k);
				comb.pop_back();
			}
		}
	};


	void test() {
		Solution sol;
		int n = 4;
		int k = 2;
		vector<vector<int>> res = sol.combine(4, 2);
		for (auto v : res) {
			for (int i : v) {
				cout << i << " ";
			}
			cout << endl;
		}
	}
}