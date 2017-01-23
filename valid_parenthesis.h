#pragma once
#include <iostream>
#include <stack>
#include <set>
using namespace std;
namespace valid_parenthesis {
	class Solution {
	public:
		bool isValid(string s) {
			stack<char> stackc;
			set<char> setc;
			int i = 0;
			setc.insert('(');
			setc.insert('[');
			setc.insert('{');
			while (i < s.length()) {
				char c = s[i++];
				if (setc.find(c) != setc.end()) {
					stackc.push(c);
				}
				else {
					if (c == ')' || c == ']' || c == '}') {
						if (stackc.empty()) {
							return false;
						}
						else {
							char top = stackc.top();
							if ((top == '(' && c == ')') ||
								(top == '[' && c == ']') ||
								(top == '{' && c == '}')) {
								stackc.pop();
							}
							else if (top == '(' && (c == ']' || c == '}') ||
								top == '[' && (c == ')' || c == '}') ||
								top == '{' && (c == ')' || c == ']'))
								return false;
						}
					}
				}
			}

			return stackc.empty();
		}
	};


	void test() {
		Solution sol;
		cout << sol.isValid("(])") << endl;
	}
}