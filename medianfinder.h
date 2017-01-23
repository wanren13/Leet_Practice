#pragma once

#include "allhead.h"

namespace medianfinder {
	class MedianFinder {
	public:
		priority_queue<int> left;
		priority_queue<int, vector<int>, greater<int>> right;
		bool mid;
		double m;

		MedianFinder() :m(0), mid(false) {};

		// Adds a number into the data structure.
		void addNum(int num) {
			int lsize = left.size(), rsize = right.size();
			if (lsize == 0) {
				if (!mid) m = num;
				else {
					if (num < (int)m) {
						left.push(num);
						right.push(int(m));
					}
					else {
						left.push(int(m));
						right.push(num);
					}
				}
			}
			else {
				int lval = left.top(), rval = right.top();
				if (mid) {
					if (num < (int)m) {
						left.push(num);
						right.push(int(m));
					}
					else {
						left.push(int(m));
						right.push(num);
					}
				}
				else {
					if (num >= lval && num <= rval) m = num;
					else if (num < lval) {
						left.push(num);
						m = left.top();
						left.pop();
					}
					else {
						right.push(num);
						m = right.top();
						right.pop();
					}
				}				
			}
			mid = !mid;
		}

		// Returns the median of current data stream
		double findMedian() {
			if (mid) return m;
			else {
				if (left.size()) return (left.top() + right.top()) / 2.0;
				else return 0;
			}
		}
	};

	// Your MedianFinder object will be instantiated and called as such:
	// MedianFinder mf;
	// mf.addNum(1);
	// mf.findMedian();

	void test() {
		MedianFinder mf;
		mf.addNum(2);
		cout << mf.findMedian() << endl;
		mf.addNum(3);
		cout << mf.findMedian() << endl;
		mf.addNum(4);
		cout << mf.findMedian() << endl;
		mf.addNum(5);
		cout << mf.findMedian() << endl;
		mf.addNum(6);
		cout << mf.findMedian() << endl;

	}

}