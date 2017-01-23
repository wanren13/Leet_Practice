#pragma once

#include "allhead.h"

namespace longest_palindromic_substring {
	//class Solution {
	//public:
	//	string longestPalindrome(string s) {

		//	string res;
		//	int len = s.length();
		//	if (len < 2) return s;
		//	int left = 0, right = 0, i = 0;
		//	while (i < len) {
		//		string s1, s2;

		//		// odd
		//		left = i - 1, right = i + 1;
		//		s1 = s1 + s[i];
		//		while (left >= 0 && right < len) {
		//			char lc = s[left--], rc = s[right++];
		//			if (lc == rc) s1 = lc + s1 + rc;
		//		}

		//		// even
		//		left = i, right = i + 1;
		//		while (left >= 0 && right < len) {
		//			char lc = s[left--], rc = s[right++];
		//			if (lc == rc) s2 = lc + s2 + rc;
		//		}

		//		if (s1.length() > res.length() || s2.length() > res.length()) {
		//			if (s1.length() > s2.length()) res = s1;
		//			else res = s2;
		//		}


		//		cout << "i: " << i << "   s1: " << s1 << "   s2: " << s2 << endl;

		//		i++;
		//	}

		//	return res;


			//int len = s.length();
			//int start = 0, end;
			//int maxlen = 0, ms = 0;
			//while (start < len && len - start > maxlen) {
			//	int cnt = 0;
			//	end = len - 1;
			//	while (start + cnt < end - cnt) {
			//		if (s[start + cnt] != s[end - cnt]) {
			//			// end -= cnt;
			//			end--;
			//			cnt = 0;
			//		}
			//		else cnt++;
			//	}
			//	int plen = end - start + 1;
			//	if (maxlen < plen) {
			//		maxlen = plen;
			//		ms = start;
			//	}
			//	start++;
			//}

			//return s.substr(ms, maxlen);









	//	}
	//};

	class Solution {
	public:
		string longestPalindrome(string s) {
			int l = 0, r = 0, left = 0, right = 0, len = s.length(), longest = 0, start = 0, end = 0;
			while (r < len) {
				while (r + 1 < len && s[l] == s[r + 1]) r++;
				left = l; right = r;
				while (left - 1 >= 0 && right + 1 < len && s[left - 1] == s[right + 1]) {
					left--;
					right++;
				}
				if (right - left + 1 > longest) {
					start = left;
					end = right;
					longest = right -left + 1;
				}
				l = r = r + 1;
			}
			return s.substr(start, end - start + 1);
		}
	};


	char* longestPalindrome(char* s) {
		int len = strlen(s);
		if (len < 2) return s;
		int left = 0, right = 0;
		for (int i = 0; len - 1 - i > (right - left + 1) / 2;) {
			int l = i; int r = i;
			while (r < len - 1 && s[r + 1] == s[r]) r++;
			i = r + 1;
			while (l > 0 && r < len - 1 && s[l - 1] == s[r + 1]) {
				r++;
				l--;
			}
			if (r - l > right - left) {
				left = l;
				right = r;
			}
		}
		s[right + 1] = '\0';
		return s + left;
	}

	void test() {
//		string s = "fdriwohjjfuhjhsfuijwfhfhjfkieueruifjhfjbha";
		string s = "babad";
		Solution sol;
		s = sol.longestPalindrome(s);
		cout << s << endl;



		s = "abcdedfg";
		cout << s.substr(2, 0) << endl;



		// string::iterator iter = s.end();
		// cout << *(iter - 1) << endl;
	}
}