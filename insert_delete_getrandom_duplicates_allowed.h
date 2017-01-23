#pragma once

#include "allhead.h"

namespace insert_delete_getrandom_duplicates_allowed {
	// class RandomizedCollection {
	// public:
	//     /** Initialize your data structure here. */
	//     RandomizedCollection() {

	//     }

	//     /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	//     bool insert(int val) {
	//         auto it = m.find(val);
	//         nums.emplace_back(val);
	//         m[val].insert(nums.size() - 1);
	//         return it == m.end() || it->second.size() == 1;
	//     }

	//     /** Removes a value from the collection. Returns true if the collection contained the specified element. */
	//     bool remove(int val) {
	//         auto it = m.find(val);
	//         if (it == m.end() || it->second.empty()) return false;
	//         int last = nums.back(), idx = *m[val].begin();
	//         nums.pop_back();
	//         nums[idx] = last;
	//         m[val].erase(idx);
	//         m[last].insert(idx);
	//         m[last].erase(nums.size());
	//         return true;
	//     }

	//     /** Get a random element from the collection. */
	//     int getRandom() {
	//         return nums[rand() % nums.size()];
	//     }
	//     private:
	//     unordered_map<int, unordered_set<int>> m;
	//     vector<int> nums;

	// };

	// /**
	//  * Your RandomizedCollection object will be instantiated and called as such:
	//  * RandomizedCollection obj = new RandomizedCollection();
	//  * bool param_1 = obj.insert(val);
	//  * bool param_2 = obj.remove(val);
	//  * int param_3 = obj.getRandom();
	//  */


	class RandomizedCollection
	{
	public:
		/** Initialize your data structure here. */
		RandomizedCollection() { }

		/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
		bool insert(int val)
		{
			mNums.push_back(val);
			LUT[val].push_back(mNums.size() - 1);
			return LUT[val].size() == 1;
		}

		/** Removes a value from the collection. Returns true if the collection contained the specified element. */
		bool remove(int val)
		{
			if (LUT[val].size() != 0)
			{
				int idx = LUT[val].back();
				//Put the last number in the position of idx and delete the last element.
				mNums[idx] = mNums[mNums.size() - 1];
				mNums.pop_back();
				//Update LUT.
				LUT[mNums[idx]].back() = idx;
				LUT[val].pop_back();
				return true;
			}
			return false;
		}

		/** Get a random element from the collection. */
		int getRandom()
		{
			return mNums[rand() % mNums.size()];
		}
	private:
		vector<int> mNums;
		map<int, vector<int>> LUT;
	};

	void test() {
		RandomizedCollection rand;
		rand.insert(1);
		rand.insert(2);
		rand.insert(2);
		rand.remove(1);
		rand.remove(2);
		rand.remove(2);
	}
}