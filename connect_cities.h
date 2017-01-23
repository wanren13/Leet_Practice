#pragma once


#include "allhead.h"

namespace connect_cities {
	class Solution {
	public:
		vector<int> connect(const vector<int>& cities) {
			int numOfCities = cities.size();
			vector<int> connections(numOfCities, -1);

			vector<int> left(numOfCities + 1, INT_MIN);
			vector<int> right(numOfCities + 1, INT_MAX);

			// connect every pair
			for (int i = 0; i < numOfCities; i++) {
				
				// find max to in left cities and min in right cities
				int cityL = INT_MIN, cityR = INT_MAX;
				int idxL = i + 1;
				while (idxL > 1) {
					cityL = max(cityL, left[idxL]);
					idxL -= idxL & -idxL;
				}

				int idxR = numOfCities - i;
				while (idxR > 1) {
					cityR = min(cityR, right[idxR]);
					idxR -= idxR & -idxR;
				}

				if (cityL < cities[i] && cities[i] < cityR) {

					cout << "North:\t" << i << "\t----\t" << "South\t" << cities[i] << endl;
					connections[i] = cities[i];
					// update both trees
					idxL = i + 1;
					while (idxL <= numOfCities) {
						left[idxL] = cities[i];
						idxL += idxL & -idxL;
					}

					idxR = numOfCities - i;
					while (idxR <= numOfCities) {
						right[idxR] = cities[i];
						idxR += idxR & -idxR;
					}
				}
				else
					cout << "North:\t" << i << "\txxxx\t" << "South\t" << cities[i] << endl;
			}
			return connections;
		}
	};

	void test() {
		vector<int> cities(20);
		for (int i = 0; i < cities.size(); i++) cities[i] = i;
		random_shuffle(cities.begin(), cities.end());

		Solution sol;
		cout << "Connecting..." << endl << endl;
		sol.connect(cities);
	}

	/*
	Test Result:

	North:  0       ----	South   10
	North : 1       xxxx    South   5
	North : 2       xxxx    South   2
	North : 3       xxxx    South   4
	North : 4       ----	South   14
	North : 5       ----	South   17
	North : 6       xxxx    South   7
	North : 7       ----	South   19
	North : 8       xxxx    South   13
	North : 9       xxxx    South   12
	North : 10      xxxx    South   0
	North : 11      xxxx    South   15
	North : 12      xxxx    South   6
	North : 13      xxxx    South   1
	North : 14      xxxx    South   8
	North : 15      xxxx    South   3
	North : 16      xxxx    South   16
	North : 17      xxxx    South   18
	North : 18      xxxx    South   11
	North : 19      xxxx    South   9
	*/
}