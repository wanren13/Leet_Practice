#pragma once

#include "allhead.h"

namespace length_of_last_word {
	class Solution {
	public:
		int lengthOfLastWord(string s) {
			int end = s.length() - 1;
			while (end > -1 && s[end] == ' ') end--;
			if (end == -1) return 0;
			int start = end;
			for (; start >= 0; start--) {
				if (start - 1 >= 0) {
					if (s[start - 1] == ' ') break;
				}
				else break;
			}

			return end - start + 1;
		}
	};


	int lengthOfLastWord(const char* s) {
		int len = 0;
		while (*s) {
			if (*s++ != ' ')
				++len;
			else if (*s && *s != ' ')
				len = 0;

		}
		return len;
	}


	void test (){
		Solution s;
		string str = "Hello World";
		char* cstr = "Hello World";
		// cout << s.lengthOfLastWord(str) << endl;
		cout << lengthOfLastWord(cstr) << endl;
	}
}