#pragma once

#include "allhead.h"

namespace longest_substring_without_repeating_characters {
	class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			if (s.empty()) return 0;
			int idx[128] = { 0 };
			// for (int i = 0; i < 128; i++) idx[i] = -1;
			int len = INT_MIN, begin;
			for (int i = 0; i < s.length(); i++) {
				char c = s[i];
				begin = idx[c];
				idx[c] = i;
				len = max(len, i - begin + 1);
			}

			return len < 0 ? 0 : len;
		}
	};



	//class Solution {
	//public:
	//	int lengthOfLongestSubstring(string s) {
	//		int idx[256];
	//		fill(idx, idx + 256, -1);
	//		int longest = 0, begin = 0, end = 0;
	//		while (end < s.length()) {
	//			int i = idx[s[end]];
	//			idx[s[end]] = end;
	//			if (i != -1) begin = i + 1;
	//			else longest = max(longest, end - begin + 1);
	//			end++;
	//		}

	//		return longest;
	//	}
	//};



	//class Solution {
	//public:
	//	int lengthOfLongestSubstring(string s) {
	//		vector<int> m(256, 0);
	//		int len = 0, end = 0, begin = 0;

	//		while (end < s.length()) {
	//			if (m[s[end++]]++ == 0) len = max(len, end - begin);
	//			while (m[s[end - 1]] > 1) m[s[begin++]]--;
	//		}

	//		return len;
	//	}
	//};

	void test() {
		Solution sol;
		string s = "pwwkew";
			// "tmmzuxt";
			//"abcabcbb";
		//"abba";
		cout << sol.lengthOfLongestSubstring(s) << endl;
	}
}