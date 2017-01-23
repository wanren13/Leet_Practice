#pragma once

#include "allhead.h"

namespace reverse_vowels_of_string {
	class Solution {
	public:
		string reverseVowels(string s) {
			int front = 0;
			int back = s.length() - 1;
			unordered_set<char> vowels;
			vowels.insert('a');
			vowels.insert('e');
			vowels.insert('i');
			vowels.insert('o');
			vowels.insert('u');
			while (front < back) {
				while (front < back && vowels.find(tolower(s[front])) == vowels.end()) front++;
				while (front < back && vowels.find(tolower(s[back])) == vowels.end()) back--;
				char c = s[front];
				s[front] = s[back];
				s[back] = c;
				front++;
				back--;
			}
			return s;
		}
	};



	void test() {
		Solution s;
		string str = "hello";
		str = s.reverseVowels(str);
		cout << "Reversed string is " << str << endl;
	}
}