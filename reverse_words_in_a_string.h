#pragma once

#include "allhead.h"

namespace reverse_words_in_a_string {
	//class Solution {
	//public:
	//	void reverseWords(string &s) {
	//		string sc;
	//		int start = 0, end = 0;
	//		bool first = true;
	//		int len = s.length();
	//		string ins;
	//		while (start < len && end < len) {
	//			while(start < len && s[start] == ' ') start++;
	//			end = start;
	//			while (end < len && s[end] != ' ') end++;
	//			if (start == len) break;
	//			ins = s.substr(start, end - start);
	//			if (first) first = false;
	//			else ins += string(" ");
	//			sc.insert(0, ins);
	//			start = end;
	//		}
	//		s = sc;
	//	}
	//};

	class Solution {
	public:
		void reverseWords(string &s) {
			// shift words to left;
			int i = 0, j = 0;
			while (j < s.length()) {
				while (j < s.length() && s[j] == ' ') j++;
				while (j < s.length() && s[j] != ' ') {
					s[i++] = s[j];
					if (i != j) s[j] = ' ';
					j++;
				}
				j = ++i;
			}

			trimTail(s);
			reverseStr(s);
			int begin = 0, end = 0;
			while (end < s.length()) {
				end = begin;
				while (end + 1 < s.length() && s[end + 1] != ' ') end++;
				swapStr(s, begin, end);
				begin = end + 2;
			}
		}

		void reverseStr(string& s) {
			reverse(s.begin(), s.end());
		}

		void swapStr(string& s, int begin, int end) {
			while (begin < end) {
				swap(s[begin++], s[end--]);
			}
		}

		void trimTail(string& s) {
			while (!s.empty() && s.back() == ' ') s.pop_back();
		}
	};

	void test() {
		Solution sol;
		// string s = "    the          sky is               blue     ";
		string s = "a";
		sol.reverseWords(s);
		cout << s << endl;
	}
}