#pragma once

#include "allhead.h"

namespace LCCS {
	void printLCSS(const string& s2, int pos, int len) {
		cout << s2.substr(pos, len) << endl;
	}



	//int LCSS(string s1, string s2) {
	//	int len = 0;
	//	int len1 = s1.length();
	//	int len2 = s2.length();
	//	int maxi = 0;
	//	int maxj = 0;
	//	int maxlen = 0;
	//
	//	vector<int> v(s2.length() + 1, 0);
	//	vector<vector<int>> m(s1.length() + 1, v);
	//
	//	for (int i = 0; i < len1; i++) {
	//		for (int j = 0; j < len2; j++) {
	//			if (s1[i] == s2[j]) {
	//				int len = m[i][j] + 1;
	//				m[i + 1][j + 1] = len;
	//				if (maxlen < len) {
	//					maxlen = len;
	//					maxi = i;
	//					maxj = j;
	//				}
	//			}
	//			else
	//				m[i + 1][j + 1] = 0;
	//			// printMatrix(m, s1, s2);
	//			// system("pause");
	//		}
	//	}
	//
	//	printMatrix(m, s1, s2);
	//
	//	
	//	printLCSS(s2, maxj - maxlen + 1, maxlen);
	//	return maxlen;
	//}



	//int LCSS(string s1, string s2) {
	//
	//	int maxlen = 0;
	//	int len1 = s1.length();
	//	int len2 = s2.length();
	//	for (int i = 0; i < len1; i++) {
	//		for (int j = 0; j < len2; j++) {
	//			int k = 1;
	//			while (i + k <= len1 && j + k <= len2 && s1.substr(i, k) == s2.substr(j, k)) {
	//				k++;
	//			}
	//			maxlen = max(maxlen, k - 1);
	//		}
	//	}
	//	return maxlen;
	//}



	int LCSS(string s1, string s2) {
		int len1 = s1.length();
		int len2 = s2.length();

		if (len1 > 0 && len2 > 0) {
			if (s1[len1 - 1] == s2[len2 - 1]) {
				return LCSS(s1.substr(0, len1 - 1), s2.substr(0, len2 - 1)) + 1;
			}
			else {
				return LCSS(s1.substr(0, len1 - 1), s2.substr(0, len2 - 1));
			}
		}
		else {
			return 0;
		}
	}

}