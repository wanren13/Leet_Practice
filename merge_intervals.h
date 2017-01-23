#pragma once

#include "allhead.h"

namespace merge_intervals {

	bool compareInvterval(const Interval& lhs, const Interval& rhs)
	{
		if (lhs.start != rhs.start)
			return lhs.start < rhs.start;
		else
			return lhs.end < rhs.end;
	}

	class Solution {
	public:
		vector<Interval> merge(vector<Interval>& intervals) {
			if (intervals.empty()) {
				return its;
			}
			sort(intervals.begin(), intervals.end(), compareInvterval);
			
			int ind = 0;
			int start, end;

			while (ind < intervals.size()) {
				start = intervals[ind].start;
				end = intervals[ind].end;
				while (ind + 1 < intervals.size() && intervals[ind + 1].start <= end) {
					ind++;
					end = end > intervals[ind].end ? end : intervals[ind].end;
				}
				if (ind == intervals.size()) break;				
				its.emplace_back(start, end);
				ind++;
			}
			
			return its;
		}
	private:
		vector<Interval> its;
	};

	void test() {

		// [[1,3],[15,18],[8,10],[2,6]]

		vector<Interval> vi;
		/*vi.emplace_back(1, 3);
		vi.emplace_back(15, 18);
		vi.emplace_back(8, 10);
		vi.emplace_back(2, 6);*/

		vi.emplace_back(1, 4);
		vi.emplace_back(2, 3);

		/*vi.emplace_back(2, 3);
		vi.emplace_back(4, 5);
		vi.emplace_back(6, 7);
		vi.emplace_back(8, 9);
		vi.emplace_back(1, 10);*/



		for (Interval i : vi) {
			cout << i << " ";
		}
		cout << endl;


		Solution s;
		vi = s.merge(vi);

		for (Interval i : vi) {
			cout << i << " ";
		}
		cout << endl;

	}
}
