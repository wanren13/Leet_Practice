#pragma once

#include "allhead.h"

namespace find_k_pairs_with_smallest_sums {
	//class Solution {
	//public:
	//	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	//		vector<pair<int, int>> res;
	//		if (nums1.empty() || nums2.empty()) return res;
	//		int rk = sqrt(k);
	//		multimap<int, pair<int, int>> m;
	//		int maxval = INT_MAX;
	//		if (nums1.size() > k && nums2.size() > k) {
	//			maxval = min(nums1[0] + nums2[k - 1], nums2[0] + nums1[k - 1]);
	//			maxval = min(maxval, nums1[rk - 1] + nums2[rk - 1]);
	//		}
	//		else if (nums1.size() >= k && nums2.size() < k) {
	//			maxval = nums1[k - 1] + nums2[0];
	//			int n = nums2.size();
	//			maxval = min(maxval, nums1[(k + 1) / n - 1] + nums2[n - 1]);
	//		}

	//		else if (nums2.size() >= k && nums1.size() < k) {
	//			maxval = nums2[k - 1] + nums1[0];
	//			int n = nums1.size();
	//			maxval = min(maxval, nums2[(k + 1) / n - 1] + nums1[n - 1]);
	//		}

	//		for (int i = 0; i < nums1.size(); i++) {
	//			if (nums1[i] > maxval) break;
	//			for (int j = 0; j < nums2.size(); j++) {
	//				int sum = nums1[i] + nums2[j];
	//				if (sum > maxval) break;
	//				m.insert(pair<int, pair<int, int>>(sum, pair<int, int>(nums1[i], nums2[j])));
	//			}
	//		}

	//		int count = 0;
	//		for (multimap<int, pair<int, int>>::iterator iter = m.begin(); iter != m.end() && count < k; iter++) {
	//			res.emplace_back(iter->second);
	//			count++;
	//		}

	//		return res;
	//	}
	//};

	class Solution {
	public:
		vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
			vector<pair<int, int>> res;
			if (nums1.empty() || nums2.empty() || k <= 0) return res;

			auto cmp = [&nums1, &nums2](const pair<int, int>& p1, const pair<int, int>& p2) {
				return nums1[p1.first] + nums2[p1.second] > nums1[p2.first] + nums2[p2.second];
			};

			priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> min_heap(cmp);

			min_heap.emplace(0, 0);

			int count = 0;
			while (k--) {
				int idx1 = min_heap.top().first, idx2 = min_heap.top().second;
				min_heap.pop();
				res.emplace_back(nums1[idx1], nums2[idx2]);
				if (idx1 == nums1.size() - 1 && idx2 == nums2.size() - 1) break;
				if (idx1 < nums1.size() - 1) min_heap.emplace(idx1 + 1, idx2);
				if (idx1 == 0 && idx2 < nums2.size() - 1) min_heap.emplace(idx1, idx2 + 1);
			}

			return res;
		}
	};


	void test() {
		Solution sol;
		vector<int> nums1(
		{ 1, 1, 2 }
		// { 1, 2, 4, 5, 6 }
		);
		vector<int> nums2(
		{ 1, 2, 3 }
		// { 3, 5, 7, 9 }
		);
		int k = 10;
		vector<pair<int, int>> res = sol.kSmallestPairs(nums1, nums2, k);
		for (auto p : res) cout << p.first << "\t" << p.second << endl;




		list<int> l({ 1,2,3,4,5,6 });
		list<int>::iterator it = l.begin();
		for (int i = 0; i < 6; i++) {
			int n = *it;
			cout << n << " ";
			it = l.erase(it);
			l.insert(it, n);
		}
		cout << endl;

		it = l.begin();
		for (int i = 0; i < 6; i++) {
			cout << *it << " ";
			it++;
		}
		cout << endl;




	}
}