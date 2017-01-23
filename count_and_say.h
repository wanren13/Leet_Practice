#pragma once

#include "allhead.h"

namespace count_and_say {
	//class Solution {
	//public:
	//	string countAndSay(int n) {
	//		static vector<string> v({ "1" });
	//		int len = v.size();
	//		// if (n <= len) return v[n - 1];
	//		while (len < n) {
	//			string s = v[len - 1], ss;
	//			int i = 1;
	//			int cnt = 1;
	//			char prev = s[0];
	//			while (i < s.length()) {
	//				if (s[i] == prev) cnt++;
	//				else {
	//					ss.append(to_string(cnt) + to_string(prev));
	//					cnt = 1;
	//				}
	//				prev = s[i];
	//				i++;
	//			}
	//			ss.append(to_string(cnt) + to_string(prev));

	//			v.emplace_back(ss);

	//			len++;
	//		}

	//		for (auto s : v) cout << s << endl;

	//		return v[n - 1];
	//	}
	//};


	class Solution {
	public:
		string countAndSay(int n) {
			string res = "1";
			if (n < 2) return res;
			while (--n) {
				string s;
				int i = 0;
				while (i < res.length()) {
					int cnt = 1;
					char c = res[i];
					while (++i < res.length() && res[i] == res[i - 1]) cnt++;
					s = to_string(cnt) + c;
				}
				swap(res, s);
			}
			return res;
		}
	};

	void test() {
		Solution sol;
		cout << sol.countAndSay(4) << endl;
	}
}