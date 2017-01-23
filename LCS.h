#pragma once

#include "allhead.h"

namespace LCS {
	map<pair<string, string>, int> lmap;
	string lcs;

	//int LCS(string s1, string s2) {	
	//	if (s1.length() > 0 && s2.length() > 0) {
	//
	//		//pair<string, string> p1(s1, s2);
	//		//pair<string, string> p2(s2, s1);
	//
	//		//if ((p1.first == p2.first && p1.second == p2.second)
	//		//	|| (p1.first == p2.second && p1.second == p2.first))
	//
	//		string sub1 = s1.substr(0, s1.length() - 1);
	//		string sub2 = s2.substr(0, s2.length() - 1);
	//		if (s1.back() == s2.back()) {
	//			cout << s1.back();
	//			pair<string, string> p;
	//			if (s1 < s2)
	//				p = pair<string, string>(s1, s2);
	//			else
	//				p = pair<string, string>(s2, s1);
	//			if(lmap.find(p) == lmap.end())
	//				lmap[p] = LCS(sub1, sub2) + 1;
	//			return lmap[p];
	//		}
	//		else {
	//			pair<string, string> p1;
	//			pair<string, string> p2;
	//			if (sub1 < s2)
	//				p1 = pair<string, string>(sub1, s2);
	//			else
	//				p1 = pair<string, string>(s2, sub1);
	//			if (lmap.find(p1) == lmap.end())
	//				lmap[p1] = LCS(sub1, s2);
	//
	//			if (s1 < sub2)
	//				p2 = pair<string, string>(s1, sub2);
	//			else
	//				p2 = pair<string, string>(sub2, s1);
	//			if (lmap.find(p2) == lmap.end())
	//				lmap[p2] = LCS(s1, sub2);
	//
	//			return max(lmap[p1], lmap[p2]);
	//		}
	//	}
	//	else
	//		return 0;	
	//}


	//struct cmpByPair {
	//	bool operator()(const pair<string, string>& p1, const pair<string, string>& p2) const {
	//		
	//		
	//		return  true;
	//	}
	//};


	// map <int, map<int, int>> m;

	//int LCS(string s1, string s2) {
	//	int len = 0;
	//	int len1 = s1.length();
	//	int len2 = s2.length();
	//
	//	for (int i = 0; i < len1; i++) {
	//		// int j = 0;
	//		bool found = false;
	//		for (int j = 0; j < len2; j++) { 
	//			if (!found) {
	//				found = (s1[i] == s2[j]);
	//				if (i == 0 && j == 0) {
	//					len = 0;
	//				}
	//				else if (j == 0) {
	//					len = m[i - 1][j];
	//				}
	//				else if (i == 0) {
	//					len = m[i][j - 1];
	//				}
	//				else {
	//					len = max(m[i][j - 1], m[i - 1][j]);
	//				}
	//
	//				m[i][j] = s1[i] == s2[j] ? len + 1 : len;
	//			}
	//			else {
	//				m[i][j] = m[i][j - 1];
	//			}
	//		}
	//	}
	//
	//	return m[len1 - 1][len2 - 1];
	//}


	/*void printMatrix(map<int, map<int, int>>& m) {
	map<int, map<int, int>>::iterator i;
	map<int, int>::iterator j;
	for (i = m.begin(); i != m.end(); i++) {
	for (j = i->second.begin(); j != i->second.end(); j++) {
	cout << j->second << " ";
	}
	cout << endl;
	}
	}*/

	void printMatrix(const vector<vector<int>>& m, const string& s1, const string& s2) {
		cout << "    ";
		for (int i = 0; i < (int)s2.length(); i++) {
			cout << s2[i] << " ";
		}
		cout << endl;
		int j = 0;
		bool firstline = true;
		for (vector<int> v : m) {
			if (!firstline) {
				cout << s1[j] << " ";
				j++;
			}
			else {
				firstline = false;
				cout << "  ";
			}
			for (int i : v) {
				cout << i << " ";
			}

			cout << endl;
		}
	}


	void printLCS(const vector<vector<int>>& m, const string& s2) {
		int row = m.size() - 1;
		int col = m[0].size() - 1;
		vector<vector<int>> m1 = m;
		string str;

		while (m[row][col] > 0) {

			//while (m[row - 1][col] == m[row][col]) {
			//	row--;
			//}
			//while (m[row][col - 1] == m[row][col]) {
			//	col--;
			//}

			//m1[row][col] = 9;
			//string s1 = "GCGCAATG";
			//printMatrix(m1, s1, s2);
			//system("pause");
			//str.insert(0, s2.substr(col - 1, 1));
			//row--;
			//col--;


			if (m[row - 1][col] == m[row][col]) {
				row--;
			}
			else if (m[row][col - 1] == m[row][col]) {
				col--;
			}
			else {
				/*m1[row][col] = 9;
				string s1 = "GCGCAATG";
				printMatrix(m1, s1, s2);*/
				// system("pause");
				str.insert(0, s2.substr(col - 1, 1));
				row--;
				col--;
			}

		}

		cout << str << endl;
	}


	int LCS(string s1, string s2) {
		int len = 0;
		int len1 = s1.length();
		int len2 = s2.length();

		vector<int> v(s2.length() + 1, 0);

		vector<vector<int>> m(s1.length() + 1, v);

		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				if (s1[i] == s2[j])
					m[i + 1][j + 1] = m[i][j] + 1;
				else
					m[i + 1][j + 1] = max(m[i][j + 1], m[i + 1][j]);
				// printMatrix(m, s1, s2);
				// system("pause");
			}
		}

		printMatrix(m, s1, s2);

		printLCS(m, s2);
		return m[len1][len2];
	}
}