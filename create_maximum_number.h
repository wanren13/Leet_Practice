#pragma once

#include "allhead.h"

namespace create_maximum_number {
	class Solution {
	public:
		vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
			vector<int> res(k, 0);
			int low = nums2.size() >= k ? 0 : k - nums2.size();
			int high = min((int)nums1.size(), k);
			for (int i = low; i <= high; i++) {
				vector<int> n1 = findMax(nums1, i);
				vector<int> n2 = findMax(nums2, k - i);
				vector<int> m = merge(n1, n2);
				if (!isGreater(res, m)) res = m;
			}
			return res;
		}

	private:
		vector<int> merge(vector<int>& n1, vector<int>& n2) {
			int len1 = n1.size(), len2 = n2.size();
			vector<int> res(len1 + len2);
			int i = 0, j = 0;
			for (int k = 0; k < res.size(); k++) {
				int ii = i, jj = j;
				while (ii < len1 && jj < len2 && n1[ii] == n2[jj]) {
					ii++;
					jj++;
				}
				res[k] = ii < len1 && jj < len2 ?
					(n1[ii] > n2[jj] ? n1[i++] : n2[j++]) :
					(ii < len1 ? n1[i++] : n2[j++]);
			}
			return res;
		}

		bool isGreater(vector<int>& res, vector<int>& m) {
			for (int i = 0; i < res.size(); i++) {
				if (res[i] != m[i]) return res[i] > m[i];
			}
			return true;
		}

		vector<int> findMax(vector<int> num, int n) {
			if (num.empty()) return num;
			vector<int>::iterator iter = num.begin() + 1;
			// while (iter != num.end() && n != num.size()) {
			while (n != num.size()) {
				if (iter == num.begin() || iter != num.end() && *iter <= *(iter - 1)) iter++;
				else iter = num.erase(iter - 1);
			}
			return num;
		}
	};

	void test() {

		vector<int> nums1(
			{ 3, 4, 6, 5 }
			// {6,7}
			// {8,9}
		// { 9, 3, 2, 1, 8, 7, 6 }
		// { 9, 8, 7, 6, 5, 4, 3 }
		// { 1, 2, 3, 4, 5, 6, 7 }
		// { 4, 4, 2, 2, 4, 4, 4 }
		// { 4, 4, 4, 4, 4, 4, 4 }
		);
		vector<int>  nums2(
			{ 9, 1, 2, 5, 8, 3 }
			// {6,0,4}
			// { 3,9 }
		);
		int k = 10;


		Solution sol;

		vector<int> res = sol.maxNumber(nums2, nums1, k);
		for (int i : res) cout << i << " ";
		cout << endl;

		//for (int i = 1; i < 7; i++) {
		//	vector<int> res = sol.findMax(nums1, i);

		//	for (int i : res) cout << i << " ";
		//	cout << endl;
		//}
	}
}