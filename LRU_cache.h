#pragma once

#include "allhead.h"

namespace LRU_cache {
	class LRUCache {
	public:
		LRUCache(int capacity) : _capacity(capacity) {

		}

		int get(int key) {
			if (m.find(key) == m.end()) return -1;
			int val = m[key]->v;
			l.erase(m[key]);
			m[key] = l.insert(l.end(), KV(key, val));
			return val;
		}

		void set(int key, int value) {
			auto it = l.insert(l.end(), KV(key, value));
			if (m.find(key) != m.end()) l.erase(m[key]);
			if (l.size() > _capacity) {
				m.erase(l.begin()->k);
				l.erase(l.begin());
			}
			m[key] = it;
		}
	private:
		int _capacity;
		struct KV {
			int k, v;
			KV(int kk, int vv) : k(kk), v(vv) {}
		};
		list<KV> l;
		unordered_map<int, list<KV>::iterator> m;
	};




	//class LRUCache {
	//public:
	//	LRUCache(int capacity) : cap(capacity) {}

	//	int get(int key) {
	//		if (m.find(key) == m.end()) return -1;
	//		KV kv = *m[key];
	//		l.erase(m[key]);
	//		m[key] = l.insert(l.end(), kv);
	//		return m[key]->v;
	//	}

	//	void set(int key, int value) {
	//		list<KV>::iterator it = l.insert(l.end(), KV(key, value));
	//		if (m.find(key) != m.end()) l.erase(m[key]);
	//		m[key] = it;
	//		if (m.size() > cap) {
	//			m.erase(l.front().k);
	//			l.pop_front();
	//		}
	//	}

	//	struct KV {
	//		int k, v;
	//		KV(int key, int val) : k(key), v(val) {}
	//	};
	//	list<KV> l;
	//	unordered_map<int, list<KV>::iterator> m;
	//	int cap;
	//};
	
	void test() {
		/*LRUCache lru(2);
		lru.set(2, 1);
		lru.set(2, 2);
		lru.get(2);
		lru.set(1, 1);
		lru.set(4, 1);
		lru.get(2);*/

		LRUCache lru(3);
		lru.set(1, 1);
		lru.set(2, 2);
		lru.set(3, 3);
		lru.set(4, 4);
		cout << lru.get(4) << endl;
		cout << lru.get(3) << endl;
		cout << lru.get(2) << endl;
		cout << lru.get(1) << endl;
		lru.set(5, 5);
		cout << lru.get(1) << endl;
		cout << lru.get(2) << endl;
		cout << lru.get(3) << endl;
		cout << lru.get(4) << endl;
		cout << lru.get(5) << endl;
	}
}