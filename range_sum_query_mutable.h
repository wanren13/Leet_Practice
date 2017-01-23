#pragma once

#include "allhead.h"

namespace range_sum_query_mutable {
	//class NumArray {
	//public:
	//	NumArray(vector<int> &nums) {
	//		int len = nums.size();
	//		bitree.resize(len + 1, 0);

	//		for (int i = 0; i < len; i++) {
	//			int idx = i + 1;
	//			while (idx < len + 1) {
	//				bitree[idx] += nums[i];
	//				idx = idx + (idx & -idx);
	//			}
	//		}
	//	}

	//	void update(int i, int val) {
	//		int len = bitree.size();
	//		int idx = i + 1;

	//		while (idx < len) {
	//			bitree[idx] += val;
	//			idx = idx + (idx & -idx);
	//		}
	//	}

	//	int sumRange(int i, int j) {
	//		int sumi = 0, sumj = 0;
	//		int idxi = i, idxj = j + 1;

	//		while (idxi) {
	//			sumi += bitree[idxi];
	//			idxi = idxi - (idxi & -idxi);
	//		}

	//		while (idxj) {
	//			sumj += bitree[idxj];
	//			idxj = idxj - (idxj & -idxj);
	//		}

	//		return sumj - sumi;
	//	}
	//private:
	//	vector<int> bitree;
	//};



	//class NumArray {
	//public:
	//	NumArray(vector<int> &nums): v(nums) {
	//		int size = pow(2, ceil(log2(nums.size())));
	//		if (size != 0) segtree.resize(2 * size - 1);
	//		int len = v.size();
	//		constructTree(0, len - 1, 0);
	//		for (int i : segtree) cout << i << " ";
	//		cout << endl;
	//	}

	//	void update(int i, int val) {
	//		int diff = val - v[i];
	//		v[i] = val;
	//		int len = v.size();
	//		updateTree(0, len - 1, i, 0, diff);
	//	}

	//	int sumRange(int i, int j) {
	//		int len = v.size();
	//		return getSum(0, len - 1, i, j, 0);
	//	}
	//private:
	//	vector<int> segtree;
	//	vector<int>& v;
	//	int constructTree(int start, int end, int idx) {
	//		if (start > end) return 0;
	//		if (start == end) segtree[idx] = v[start];
	//		else {
	//			int mid = start + (end - start) / 2;
	//			segtree[idx] = constructTree(start, mid, idx * 2 + 1) +
	//				constructTree(mid + 1, end, idx * 2 + 2);
	//		}
	//		return segtree[idx];
	//	}

	//	void updateTree(int start, int end, int i, int idx, int diff) {
	//		if (segtree.empty()) return;
	//		if (i < start || i > end) return;
	//		segtree[idx] += diff;
	//		if (start == end) return;
	//		int mid = start + (end - start) / 2;
	//		updateTree(start, mid, i, idx * 2 + 1, diff);
	//		updateTree(mid + 1, end, i, idx * 2 + 2, diff);
	//	}

	//	int getSum(int start, int end, int rstart, int rend, int idx) {
	//		if (segtree.empty()) return 0;
	//		if (rstart > end || rend < start) return 0;
	//		else if (rstart <= start && rend >= end) return segtree[idx];
	//		else {
	//			int mid = start + (end - start) / 2;
	//			return getSum(start, mid, rstart, rend, idx * 2 + 1) +
	//				getSum(mid + 1, end, rstart, rend, idx * 2 + 2);
	//		}
	//	}

	//};


	class NumArray {
	public:
		NumArray(vector<int> &nums) {
			int size = nums.size();
			segtree.resize(2 * size);
			for (int i = size; i < 2 * size; i++) segtree[i] = nums[i - size];
			for (int i = size - 1; i > 0; i--) segtree[i] = segtree[i * 2] + segtree[i * 2 + 1];
		}

		void update(int i, int val) {
			int pos = i + segtree.size() / 2;
			int diff = val - segtree[pos];
			while (pos) {
				segtree[pos] += diff;
				pos /= 2;
			}
		}

		int sumRange(int i, int j) {
			int n = segtree.size() / 2;
			i += n;
			j += n;
			int sum = 0;
			while (i <= j) {
				if ((i % 2) == 1) sum += segtree[i];
				if ((j % 2) == 0) sum += segtree[j];
				i = (i + 1) / 2;
				j = (j - 1) / 2;
			}
			return sum;
		}
	private:
		vector<int> segtree;
	};

















































/*



	class NumArray {
	public:
		NumArray(vector<int> &nums) {
			int len = nums.size();
			v = nums;
			bitree.resize(len + 1, 0);

			for (int i = 0; i < len; i++) {
				int idx = i + 1;
				while (idx < len + 1) {
					bitree[idx] += nums[i];
					idx = idx + (idx & -idx);
				}
			}
		}

		void update(int i, int val) {
			int len = bitree.size();
			int idx = i + 1;

			while (idx < len) {
				bitree[idx] += val - v[i];
				idx = idx + (idx & -idx);
			}

			v[i] = val;
		}

		int sumRange(int i, int j) {
			int sumi = 0, sumj = 0;
			int idxi = i, idxj = j + 1;

			while (idxi) {
				sumi += bitree[idxi];
				idxi = idxi - (idxi & -idxi);
			}

			while (idxj) {
				sumj += bitree[idxj];
				idxj = idxj - (idxj & -idxj);
			}

			return sumj - sumi;
		}
	private:
		vector<int> bitree;
		vector<int> v;
	};




	class NumArray {
	public:
		NumArray(vector<int> &nums) {
			int size = nums.size();
			segtree.resize(2 * size);
			for (int i = size; i < 2 * size; i++) segtree[i] = nums[i - size];
			for (int i = size - 1; i > 0; i--) segtree[i] = segtree[i * 2] + segtree[i * 2 + 1];
		}

		void update(int i, int val) {
			int pos = i + segtree.size() / 2;
			int diff = val - segtree[pos];
			while (pos) {
				segtree[pos] += diff;
				pos /= 2;
			}
		}

		int sumRange(int i, int j) {
			int n = segtree.size() / 2;
			i += n;
			j += n;
			int sum = 0;
			while (i <= j) {
				if ((i % 2) == 1) sum += segtree[i];
				if ((j % 2) == 0) sum += segtree[j];
				i = (i + 1) / 2;
				j = (j - 1) / 2;
			}
			return sum;
		}
	private:
		vector<int> segtree;
	};


*/















	// Your NumArray object will be instantiated and called as such:
	// NumArray numArray(nums);
	// numArray.sumRange(0, 1);
	// numArray.update(1, 10);
	// numArray.sumRange(1, 2);

	void test() {
		vector<int> v(
		// {1,2,5}
			{ -28,-39,53,65,11,-56,-65,-39,-43,97 }
			);
		NumArray arr(v);
		cout << arr.sumRange(0, 2) << endl;
		cout << arr.sumRange(4, 4) << endl;
		cout << arr.sumRange(2, 4) << endl;
		cout << arr.sumRange(3, 3) << endl;
		arr.update(4, 5);
		arr.update(1, 7);
		arr.update(0, 8);
		cout << arr.sumRange(1, 2) << endl;
		cout << arr.sumRange(4, 4) << endl;
		arr.update(3, 4);
	}

}