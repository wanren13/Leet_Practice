#pragma once

#include "allhead.h"

namespace directed_graph_test {
	class graph {
	public:
		void addVertex(int v) {
			adj[v] = vector<int>();
		}

		void addEdge(int start, int end) {
			adj[start].emplace_back(end);
		}

		void DFS() {
			if (adj.empty()) return;
			int size = adj.size();
			unordered_map<int, bool> visited;
			stack<int> s;
			for (auto node : adj) {
				visited[node.first] = false;
			}

			for (auto n : adj) {
				int v = n.first;
				if (!visited[v]) {
					visited[v] = true;
					s.push(v);
				}
				while (!s.empty()) {
					v = s.top();
					s.pop();
					cout << v << " ";
					for (int i : adj[v]) {
						if (!visited[i]) {
							visited[i] = true;
							s.push(i);
						}
					}
				}
			}

			cout << endl;
		}

		void RECUR_DFS() {
			unordered_map<int, bool> visited;
			for (auto node : adj) {
				visited[node.first] = false;
			}

			for (auto n : adj) {
				int v = n.first;
				RECUR_DFS_UTILITY(v, visited);
			}
			cout << endl;
		}

		void RECUR_DFS_UTILITY(int v, unordered_map<int, bool>& visited) {
			if (!visited[v]) {
				cout << v << " ";
				visited[v] = true;
				for (int i : adj[v]) {
					RECUR_DFS_UTILITY(i, visited);
				}
			}
		}


		void POSTORDER_DFS() {
			unordered_map<int, bool> visited;
			for (auto node : adj) {
				visited[node.first] = false;
			}

			for (auto n : adj) {
				int v = n.first;
				POSTORDER_DFS_UTILITY(v, visited);
			}
			cout << endl;
		}

		void POSTORDER_DFS_UTILITY(int v, unordered_map<int, bool>& visited) {
			if (!visited[v]) {
				for (int i : adj[v]) {
					POSTORDER_DFS_UTILITY(i, visited);
				}
				cout << v << " ";
				visited[v] = true;
			}
		}

		void BFS() {
			if (adj.empty()) return;
			int size = adj.size();
			unordered_map<int, bool> visited;
			queue<int> q;
			for (auto node : adj) {
				visited[node.first] = false;
			}

			for (auto n : adj) {
				int v = n.first;
				if (!visited[v]) {
					visited[v] = true;
					q.push(v);
				}
				while (!q.empty()) {
					v = q.front();
					q.pop();
					cout << v << " ";
					for (int i : adj[v]) {
						if (!visited[i]) {
							visited[i] = true;
							q.push(i);
						}
					}
				}
			}

			cout << endl;
		}

		void topological_sort_stack() {
			unordered_map<int, bool> visited;
			for (auto node : adj) {
				visited[node.first] = false;
			}

			stack<int> s;

			for (auto n : adj) {
				int v = n.first;
				topological_sort_stack_UTILITY(v, visited, s);
			}

			while (!s.empty()) {
				cout << s.top() << " ";
				s.pop();
			}

			cout << endl;
		}

		void topological_sort_stack_UTILITY(int v, unordered_map<int, bool>& visited, stack<int>& s) {
			if (!visited[v]) {
				for (int i : adj[v]) {
					topological_sort_stack_UTILITY(i, visited, s);
				}
				s.push(v);
				visited[v] = true;
			}
		}

		void printGraph() {
			for (auto node : adj) {
				cout << node.first << ": ";
				for (auto adjNode : node.second) {
					cout << adjNode << " ";
				}
				cout << endl;
			}
		}


	private:
		unordered_map<int, vector<int>> adj;
	};



	void test() {
		graph g;
		//g.addEdge(0, 1);
		//g.addEdge(0, 2);
		//g.addEdge(0, 3);
		//g.addEdge(1, 6);
		//g.addEdge(4, 6);
		//g.addEdge(5, 7);

		g.addEdge(5, 0);
		g.addEdge(5, 2);
		g.addEdge(2, 3);
		g.addEdge(3, 1);
		g.addEdge(4, 0);
		g.addEdge(4, 1);
		g.addVertex(7);


		g.printGraph();
		cout << endl << "BFS: " << endl;
		g.BFS();
		cout << endl << "DFS: " << endl;
		g.DFS();
		cout << endl << "RECUR_DFS: " << endl;
		g.RECUR_DFS();
		cout << endl << "POSTORDER_DFS: " << endl;
		g.POSTORDER_DFS();
		cout << endl << "TOPOLOGICAL_SORT(Stack): " << endl;
		g.topological_sort_stack();
	}
}