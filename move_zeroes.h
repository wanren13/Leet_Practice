#pragma once

#include "allhead.h"

namespace move_zeroes {
	class Solution {
	public:
		void moveZeroes(vector<int>& nums) {
			/*vector<int>::iterator begin = nums.begin();
			vector<int>::iterator end = nums.end();
			int offset = 0;
			int totaloffset = 0;

			while (begin != end) {
				begin = nums.begin();
				end = nums.end;
				while (*(begin + offset)) offset++;
				totaloffset += offset;
				if (totaloffset == nums.size()) break;
				rotate(begin, begin + offset, end);
			}*/

			int zero = 0, nonzero = 0;

			while (zero < nums.size() && nonzero < nums.size()) {
				while (nums[zero] != 0 && zero != nums.size()) zero++;
				while (nums[nonzero] == 0 && nonzero != nums.size()) nonzero++;
				if (zero == nums.size() || nonzero == nums.size()) break;
				if (zero < nonzero) {
					int tmp = nums[zero];
					nums[zero] = nums[nonzero];
					nums[nonzero] = tmp;
					zero++;
				}				
				nonzero++;
			}
		}
	};

	void test() {

		vector<int> v;
		
		v.push_back(1);
		v.push_back(0);
		v.push_back(1);
		//v.push_back(0);
		//v.push_back(3);
		//v.push_back(12);


		cout << "Old nums is ";
		for (int i : v) {
			cout << i << " ";
		}
		cout << endl;

		Solution s;
		s.moveZeroes(v);


		cout << "New nums is ";
		for (int i : v) {
			cout << i << " ";
		}
		cout << endl;

		//std::vector<int> myvector;

		//// set some values:
		//for (int i = 1; i<10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

		//std::rotate(myvector.begin(), myvector.begin() + 3, myvector.begin() + 5);
		//// 4 5 6 7 8 9 1 2 3
		//// print out content:
		//std::cout << "myvector contains:";
		//for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		//	std::cout << ' ' << *it;
		//std::cout << '\n';
	}
}