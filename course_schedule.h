#pragma once

#include "allhead.h"

namespace course_schedule {
	class Solution {
	public:
		bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
			
			for (auto p : prerequisites) {
				adjList[p.first].emplace_back(p.second);
				vertices[p.first] = -1;
				vertices[p.second] = -1;
			}

			bool res;

			for (auto v : vertices) {
				if (vertices[v.first] == -1)
					if (!dfs(v.first, numCourses)) return false;
			}

			return numCourses == 0;
		}

	private:
		unordered_map<int, vector<int>> adjList;
		unordered_map<int, int> vertices;
		bool dfs(int v, int& numCourses) {
			vertices[v] = numCourses;
			numCourses--;
			cout << v << endl;
			for (int vertex : adjList[v]) {
				if (vertices[vertex] == -1)
					if (!dfs(vertex, numCourses)) return false;
				else if (vertices[vertex] > vertices[v]) {
					return false;
				}
			}
			return true;
		}
	};


	void test() {
		Solution sol;
		int numCourses = 2;
		vector<pair<int, int>> prerequisites;

		prerequisites.emplace_back(1, 0);
		prerequisites.emplace_back(0, 1);

		cout << (sol.canFinish(numCourses, prerequisites) ? "Can Finish" : "Can not Finish") << endl;
	}
}