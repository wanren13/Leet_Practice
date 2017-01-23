#pragma once

#include "allhead.h"

namespace longest_consecutive_letters {

	int lcl(string str) {
		if (str.empty())
			return 0;
		int maxcount = 0, currcount = 0, lastcount = 0;
		char currchar, lastchar = str[0];
		for (int i = 0; i < str.length(); i++) {
			currchar = str[i];
			if (currchar == lastchar) {
				currcount++;
			}
			else {
				maxcount = max(currcount + lastcount, maxcount);
				lastcount = currcount;
				currcount = 1;
			}
			lastchar = currchar;
		}
		if (lastcount == 0) return 0;
		maxcount = max(currcount + lastcount, maxcount);
		return maxcount;
	}

	void test() {
		//string str = "aabbbbccc";

		string str = "aaaabbbbcddeeeeeeeeee";
		cout << "Length of longest consecutive string of " << str << " is " << lcl(str) << endl;
	}
}