#pragma once

#include "allhead.h"

namespace minimum_window_substring {
	//class Solution {
	//public:
	//	string minWindow(string s, string t) {
	//		vector<int> m(256, -1);
	//		queue<pair<char, int>> q;

	//		int cnt = 0;
	//		for (char c : t) {
	//			if (m[c]) cnt++;
	//			m[c] = 0;
	//		}

	//		int start = 0, end = 0, minlen = INT_MAX, minstart = 0;
	//		int cn = 0;

	//		for (int i = 0; i < s.length(); i++) {
	//			char c = s[i];
	//			if (m[c] >= 0) {
	//				if (!q.empty() && q.front().first == c) {
	//					q.pop();
	//					m[c]--;
	//					if (m[c] == 0) cn--;
	//				}

	//				q.push(pair<char, int>(c, i));
	//				if (m[c] == 0) cn++;
	//				m[c]++;

	//				if (cn == cnt) {
	//					start = q.front().second;
	//					char rm = q.front().first;
	//					if (i + 1 - start < minlen) {
	//						minstart = start;
	//						minlen = i + 1 - start;
	//					}
	//					q.pop();
	//					m[rm]--;
	//					if (m[rm] == 0) cn--;
	//				}
	//			}
	//		}

	//		return s.substr(minstart, minlen);
	//	}
	//};

	

	 class Solution {
	 	public:
	 		string minWindow(string s, string t) {
	 			vector<int> map(128, 0);
	 			for (auto c : t) map[c]++;
	 			int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
	 			while (end<s.size()) {
	 				if (map[s[end++]]-->0) counter--; //in t
	 				while (counter == 0) { //valid
	 					if (end - begin<d)  d = end - (head = begin);
	 					if (map[s[begin++]]++ == 0) counter++;  //make it invalid
	 				}
	 			}
	 			return d == INT_MAX ? "" : s.substr(head, d);
	 		}
	 	};




	void test() {
		Solution sol;
		string s = "ADOBECODEBANC";
		string t = "CBA";
		cout << sol.minWindow(s, t) << endl;
	}
}


