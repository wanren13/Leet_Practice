#pragma once

#include <iostream>
#include <vector>
#include <map>

using namespace std; 

namespace letter_combinations {
	//class Solution {
	//public:
	//	vector<string> letterCombinations(string digits) {
	//		if (digits.length() == 0) {
	//			return v;
	//		}
	//		size_t invalid_pos = digits.find("0");
	//		if (invalid_pos != string::npos) return v;
	//		invalid_pos = digits.find("1");
	//		if (invalid_pos != string::npos) return v;
	//		m['2'] = "abc"; m['3'] = "def"; m['4'] = "ghi";
	//		m['5'] = "jkl"; m['6'] = "mno"; m['7'] = "pqrs";
	//		m['8'] = "tuv"; m['9'] = "wxyz";

	//		v.emplace_back(string());
	//		vector<string> tmp;

	//		for (int i = 0; i < digits.length(); i++) {
	//			char d = digits[i];
	//			for (string s : v) {
	//				for (char c : m[d]) {
	//					string ts = s;
	//					ts.append(1, c);
	//					tmp.emplace_back(ts);
	//				}
	//			}
	//			v = tmp;
	//			tmp.clear();
	//		}
	//		return v;
	//	}
	//private:
	//	map<char, string> m;
	//	vector<string> v;
	//};


	class Solution {
	public:
		vector<string> letterCombinations(string digits) {
			vector<string> res;
			if (digits.empty()) return res;
			deque<string> q({ "" });
			string dict[] = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

			int i = 0;
			while (i < digits.size()) {
				int n = q.size();
				int num = digits[i] - '0';
				if (num < 2) return res;
				string word = dict[num];
				for (char c : word) {
					string tmp = q.front();
					q.pop_front();
					for (int j = 0; j < n; j++) q.push_back(tmp + c);
				}
				i++;
			}
			res.assign(q.begin(), q.end());
			return res;
		}
	};



	void test() {
		Solution s;

		vector<string> v = s.letterCombinations("23");

		for (string s : v) {
			cout << s << " ";
		}

		cout << endl;
	}
}