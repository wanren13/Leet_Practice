#pragma once

namespace maximum_product_subarray {	
	class Solution {
	public:
		int maxProduct(vector<int>& nums) {
			int size = nums.size();
			if (size == 0)
				return 0;

			priority_queue<int> q;

			int max_num = INT_MIN, min_num = INT_MAX, minproduct = 1, maxproduct = 1, prod1, prod2;
			for (int i = 0; i < size; i++) {
				prod1 = nums[i] * maxproduct;
				prod2 = nums[i] * minproduct;
				q.push(prod1);
				q.push(prod2);
				q.push(nums[i]);

				maxproduct = q.top();
				q.pop();
				q.pop();
				minproduct = q.top();
				q.pop();
				max_num = max(max_num, maxproduct);
			}

			return max_num;
		}
	};
	
	void test() {
		int arr[] = {-2, 3, 4};
		vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
		Solution s;
		cout << s.maxProduct(v) << endl;

	}
}