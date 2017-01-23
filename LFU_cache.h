#pragma once

#include "allhead.h"

namespace LFU_cache{
	class LFUCache {
	public:
		LFUCache(int capacity) : _capacity(capacity) {

		}

		int get(int key) {
			if (iters.find(key) == iters.end()) return -1;
			KVF kvf = *iters[key];
			freqlist[kvf.f].erase(iters[key]);
			if (freqlist[kvf.f].empty()) freqlist.erase(kvf.f);
			kvf.f++;
			iters[key] = freqlist[kvf.f].insert(freqlist[kvf.f].end(), kvf);
			return kvf.v;
		}

		void set(int key, int value) {
			if (iters.find(key) == iters.end()) {
				iters[key] = freqlist[1].insert(freqlist[1].end(), KVF(key, value));
			}
			else {
				KVF kvf = *iters[key];
				freqlist[kvf.f].erase(iters[key]);
				if (freqlist[kvf.f].empty()) freqlist.erase(kvf.f);
				kvf.f++;
				kvf.v = value;
				iters[key] = freqlist[kvf.f].insert(freqlist[kvf.f].end(), kvf);
			}
			if (iters.size() > _capacity) {
				KVF kvf2del = *freqlist.begin()->second.begin();
				freqlist[kvf2del.f].erase(iters[kvf2del.k]);
				if (freqlist[kvf2del.f].empty()) freqlist.erase(kvf2del.f);
				iters.erase(kvf2del.k);
			}
		}

		void printIters() {
			cout << "Print Iters" << endl;
			for (auto it : iters) {
				cout << "K: " << it.first << " k: " << it.second->k << " v: " << it.second->v << " f: " << it.second->f << endl;
			}
		}

		void printFreqList() {
			cout << "Print Freq List" << endl;
			for (auto it : freqlist) {
				cout << "F: " << it.first << endl;
				for (auto kvf : it.second) {
					cout << " k: " << kvf.k << " v: " << kvf.v << " f: " << kvf.f << endl;
				}
			}
		}


	private:
		int _capacity;
		struct KVF {
			int k, v, f;
			KVF(int kk, int vv) : k(kk), v(vv), f(1) {}
		};
		//list<KVF> l;
		typedef list<KVF>::iterator iter;
		unordered_map<int, list<KVF>> freqlist;
		unordered_map<int, iter> iters;
	};

	/**
	* Your LFUCache object will be instantiated and called as such:
	* LFUCache obj = new LFUCache(capacity);
	* int param_1 = obj.get(key);
	* obj.set(key,value);
	*/

	void test() {
		LFUCache lfu(2);
		lfu.set(1, 1);
		lfu.set(2, 2);
		cout << lfu.get(1) << endl;
		lfu.set(3, 3);
		cout << lfu.get(2) << endl;
		cout << lfu.get(3) << endl;
		lfu.set(4, 4);
		cout << lfu.get(1) << endl;
		cout << lfu.get(3) << endl;
		cout << lfu.get(4) << endl;
	}
}

