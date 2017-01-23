#pragma once

#include "allhead.h"

namespace four_sum_ii{
	class Solution {
	public:
		int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
			// sort(A.begin(), A.end());
			// sort(B.begin(), B.end());
			// sort(C.begin(), C.end());
			// sort(D.begin(), D.end());
			// int res = 0, n = A.size();

			// for (int i = 0; i < A.size(); i++) {
			//     // if (i > 0 && A[i] == A[i - 1]) continue;
			//     for (int j = 0; j < B.size(); j++) {
			//         // if (j > 0 && B[j] == B[j - 1]) continue;
			//         int c = 0, d = n - 1;
			//         while (c < n && d >= 0) {
			//             int sum = A[i] + B[j] + C[c] + D[d];
			//             if (sum > 0) d--;
			//             else if (sum < 0) c++;
			//             else {
			//                 res++;
			//                 d--;
			//                 c++;
			//                 // do {d--;} while(d >= 0 && D[d] == D[d + 1]);
			//                 // do {c++;} while(c < n  && C[c] == C[c - 1]);
			//             }
			//         }
			//     }
			// }
			// return res;

			unordered_map<int, int> m;//, mcd;
			int res = 0;
			for (int a : A) {
				for (int b : B) {
					m[a + b]++;
				}
			}

			for (int c : C) {
				for (int d : D) {
					int target = -c * d;
					if (m.find(target) != m.end()) res += m[target];
				}
			}

			return res;
		}
	};

	void test() {
		vector<int> A({ 1,2 });
		vector<int> B({ -2,-1 });
		vector<int> C({ -1,2 });
		vector<int> D({ 0,2 });

		Solution sol;
		cout << sol.fourSumCount(A, B, C, D) << endl;
	}
}