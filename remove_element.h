#pragma once

#include "allhead.h"

namespace remove_element{
	class Solution {
	public:
		int removeElement(vector<int>& nums, int val) {
			/*int size = nums.size();
			nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
			return size - nums.size();*/

			int size = nums.size();

			for (int i = 0; i < nums.size();) {
				if (nums[i] == val) {
					nums.erase(nums.begin() + i);
				}
				else {
					i++;
				}
			}
			return size - nums.size();
		}
	};


	void test() {
		int arr[] =
			//{ 1,1,1,1 };
		{ 1,1,3 };
		vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
		Solution s;
		s.removeElement(nums, 1);
		for (int i : nums) {
			cout << i << " ";
		}
		cout << endl;
	}
}