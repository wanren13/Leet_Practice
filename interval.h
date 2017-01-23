#pragma once

#include "allhead.h"

struct Interval {
	int start;
    int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	friend ostream& operator<< (ostream& os, const Interval& interval);
};

ostream& operator<< (ostream& os, const Interval& interval) {
	string i = "[" + to_string(interval.start) + ", " + to_string(interval.end) + "]";
	os << i;
	return os;
}
