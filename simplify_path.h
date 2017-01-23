#pragma once

#include "allhead.h"

namespace simplify_path {
	class Solution {
	public:
		string simplifyPath(string path) {
			string res;
			if (path.empty() || path[0] != '/') return res;
			vector<string> p;
			int start = 0, end = 0;
			char curr, prev = '/', pprev = '/';
			bool twodots = false;
			// "/a/b/c"
			int i = 0;

			while (i < path.length()) {
				curr = path[i];
				if (curr == '/') {
					if (prev == '.' && pprev == '.') {
						if (p.empty()) return res;
						else p.pop_back();
					}
					else if (prev != '/' && prev != '.') {
						// int len = end - start + 1;
						p.emplace_back(path.substr(start, end - start));
					}

					if (i < path.length() - 1 && path[i + 1] != '.' && path[i + 1] != '/') {
						start = end + 1;
					}
				}
				else end = i + 1;
				pprev = prev;
				prev = curr;
				i++;
			}
			if (i == end) p.emplace_back(path.substr(start, end - start));

			for (string s : p)
				res = res + "/" + s;

			return res;
		}
	};

	void test() {
		string path = "/a//../bfile/dfoldr/efff/../cddd////";
		Solution sol;
		cout << sol.simplifyPath(path) << endl;
	}
}