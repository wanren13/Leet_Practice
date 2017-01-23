#pragma once

#include "allhead.h"

namespace top_k_frequent_elements {
	class Solution {
	public:
		vector<int> topKFrequent(vector<int>& nums, int k) {
			unordered_map<int, int> m;
			for (int i : nums) m[i]++;
			auto cmp = [](const unordered_map<int, int>::iterator& it1, const unordered_map<int, int>::iterator& it2) {
				return it1->second > it2->second;
			};
			priority_queue<unordered_map<int, int>::iterator, vector<unordered_map<int, int>::iterator>, decltype(cmp)> q(cmp);
			for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++) q.push(it);
			vector<int> res;
			for (int i = 0; i < k; i++) {
				res.emplace_back(q.top()->first);
				q.pop();
			}
			return res;
		}
	};



	//bool bySecond (const unordered_map<int, int>::iterator & a, const unordered_map<int, int>::iterator& b){
	//	return a->second > b->second;
	//}
	//class Solution {
	//public:
	//	vector<int> topKFrequent(vector<int>& nums, int k) {
	//		unordered_map<int, int> m;
	//		vector<int> res;
	//		for (int i : nums) m[i]++;

	//		vector<unordered_map<int,int>::iterator> sorted;
	//		for (unordered_map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
	//			sorted.emplace_back(iter);
	//		}

	//		sort(sorted.begin(), sorted.end(), 
	//			[](const unordered_map<int, int>::iterator & a, const unordered_map<int, int>::iterator& b) {
	//			return a->second > b->second;
	//		});
	//		for (int i = 0; i < k; i++) {
	//			res.emplace_back(sorted[i]->first);
	//		}
	//		return res;
	//	}
	//};

	void test() {
		vector<int> arr(
		{1,2}
			);
		int k = 2;

		Solution sol;

		for (int i : sol.topKFrequent(arr, k))
			cout << i << " ";

		cout << endl;
	}
}