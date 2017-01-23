#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace generate_parenthesis {
	class Solution {
	// non-recursive version
	// public:
	//	vector<string> generateParenthesis(int n) {
	//		set<string> set0;
	//		set0.insert(string());
	//		mp[0] = set0;
	//		for (int i = 1; i <= n; i++) {
	//			set<string> ss;
	//			generateFirst(ss, i);
	//			for (int j = 1; j <= i - 1; j++) {
	//				int ind = i - j;
	//				set<string> seti = mp[ind];
	//				set<string> setj = mp[j];
	//				for (set<string>::iterator iteri = seti.begin(); iteri != seti.end(); iteri++) {
	//					for (set<string>::iterator iterj = setj.begin(); iterj != setj.end(); iterj++) {
	//						ss.insert(*iteri + *iterj);
	//					}
	//				}
	//			}
	//			mp[i] = ss;
	//		}
	//		v = vector<string>(mp[n].begin(), mp[n].end());
	//		return v;
	//	}
	//private:
	//	vector<string> v;
	//	map<int, set<string>> mp;
	//	void generateFirst(set<string>& ss, int n) {			
	//		for (int j = 0; j <= n - 1; j++) {
	//			set<string> s = mp[j];
	//			for (set<string>::iterator iter = s.begin(); iter != s.end(); iter++) {
	//				string str;
	//				for (int i = 0; i < n - j; i++) {
	//					str += "(";
	//				}
	//				str += *iter;
	//				for (int i = 0; i < n - j; i++) {
	//					str += ")";
	//				}
	//				ss.insert(str);
	//			}
	//		}
	//		
	//	}



	// Recursive version:
	public:
		vector<string> generateParenthesis(int n) {
			vector<string> res;
			addingpar(res, "", n, 0);
			return res;
		}
		void addingpar(vector<string> &v, string str, int n, int m) {
			if (n == 0 && m == 0) {
				// cout << "In 00 -- n: " << n << " m: " << m << " String: " << str << endl;
				v.push_back(str);
				return;
			}
			if (m > 0) { 
				// cout << "In m -- n: " << n << " m: " << m << " String: " << str << endl;
				addingpar(v, str + ")", n, m - 1); 
			}
			if (n > 0) { 
				// cout << "In n -- n: " << n << " m: " << m << " String: " << str << endl;
				addingpar(v, str + "(", n - 1, m + 1); 				
			}
		}
	};

	void test() {
		Solution sol;
		clock_t begin = clock();

		vector<string> v = sol.generateParenthesis(10);

		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		
		//for (string s : v) {
		//	cout << s << endl;
		//}
		cout << elapsed_secs << "s" << endl;
	}

}