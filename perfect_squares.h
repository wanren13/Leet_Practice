#pragma once

#include "allhead.h"

namespace perfect_squares{
	class Solution {
	public:
		int numSquares(int n) {
			if (n == 0) return 0;
			vector<int> squares(n + 1, 0);
			squares[0] = 0;
			int count = 1;
			int squareroot = 1;
			int nextsquare = 1;
			while (count <= n) {
				if (count == nextsquare) {
					squares[count] = 1;
					squareroot++;
					nextsquare = squareroot * squareroot;
				}
				else {
					priority_queue<int, vector<int>, greater<int>> q;
					for (int i = 1; i < squareroot; i++) {
						q.push(squares[count - i * i] + 1);
					}
					squares[count] = q.top();
				}
				cout << squares[count] << " ";
				count++;
			}

			return squares.back();
		}
	};

	void test() {
		Solution s;
		int n = 12;
		cout << "Number of perfect squares of " << n << " is " << s.numSquares(n) << endl;
	}
}