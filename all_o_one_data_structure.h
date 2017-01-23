#pragma once

#include "allhead.h"

namespace all_o_one_data_structure {
	class AllOne {
	public:
		/** Initialize your data structure here. */
		AllOne() {
		}

		/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
		void inc(string key) {
			if (iters.find(key) == iters.end()) {
				if (ones.empty() || ones.begin()->first != 1) ones.insert(ones.begin(), make_pair(1, KeySet()));
				ones.begin()->second.insert(key);
				iters[key] = ones.begin();
			}
			else {
				Ones::iterator it, next;
				it = next = iters[key];
				next++;
				if (next != ones.end() && next->first == it->first + 1) next->second.insert(key);
				else next = ones.insert(next, make_pair(iters[key]->first + 1, KeySet({ key })));
				iters[key] = next;
				it->second.erase(key);
				if (it->second.empty()) ones.erase(it);
			}
		}

		/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
		void dec(string key) {
			if (iters.find(key) != iters.end()) {
				Ones::iterator it, prev;
				prev = it = iters[key];
				if (it != ones.begin()) prev--;
				if (it->first != 1) {
					if (it == ones.begin() || prev->first != it->first - 1) 
						prev = ones.insert(it, make_pair(iters[key]->first - 1, KeySet()));
					prev->second.insert(key);
					iters[key] = prev;
				}
				else iters.erase(key);
				it->second.erase(key);
				if (it->second.empty()) ones.erase(it);
			}
		}

		/** Returns one of the keys with maximal value. */
		string getMaxKey() {
			return ones.empty() ? "" : *ones.rbegin()->second.begin();
		}

		/** Returns one of the keys with Minimal value. */
		string getMinKey() {
			return ones.empty() ? "" : *ones.begin()->second.begin();
		}
	private:
		typedef unordered_set<string> KeySet;
		typedef list<pair<int, KeySet>> Ones;
		Ones ones;
		unordered_map<string, Ones::iterator> iters;
	};

	/**
	* Your AllOne object will be instantiated and called as such:
	* AllOne obj = new AllOne();
	* obj.inc(key);
	* obj.dec(key);
	* string param_3 = obj.getMaxKey();
	* string param_4 = obj.getMinKey();
	*/

	/**
	* Your AllOne object will be instantiated and called as such:
	* AllOne obj = new AllOne();
	* obj.inc(key);
	* obj.dec(key);
	* string param_3 = obj.getMaxKey();
	* string param_4 = obj.getMinKey();
	*/


	void test() {
		AllOne allone;
		//allone.inc("hello");
		//allone.inc("hello");
		//allone.inc("world");
		//allone.inc("world");
		//allone.inc("hello");
		//allone.dec("world");
		//cout << allone.getMaxKey() << endl;
		//cout << allone.getMinKey() << endl;
		//allone.inc("world");
		//allone.inc("world");
		//allone.inc("leet");
		//cout << allone.getMaxKey() << endl;
		//cout << allone.getMinKey() << endl;
		//allone.inc("leet");
		//allone.inc("leet");
		//cout << allone.getMaxKey() << endl;
		//cout << allone.getMinKey() << endl;

		//allone.inc("hello");
		//allone.inc("goodbye");
		//allone.inc("hello");
		//allone.inc("hello");
		//cout << allone.getMaxKey() << endl;
		//allone.inc("leet");
		//allone.inc("code");
		//allone.inc("leet");
		//allone.dec("hello");
		//allone.inc("leet");
		//allone.inc("code");
		//allone.inc("code");
		//cout << allone.getMaxKey() << endl;


		//["AllOne", "inc", "inc", "inc", "inc", "inc", "dec", "dec", "getMaxKey", "getMinKey"]
		//[[], ["a"], ["b"], ["b"], ["b"], ["b"], ["b"], ["b"], [], []]

		allone.inc("a");
		allone.inc("b");
		allone.inc("b");
		allone.inc("b");
		allone.inc("b");
		allone.dec("b");
		allone.dec("b");
		cout << allone.getMaxKey() << endl;
		cout << allone.getMinKey() << endl;
	}
}