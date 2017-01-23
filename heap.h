#pragma once
#include "allhead.h"

namespace heapspace {
	using namespace std;
	template <class T>
	class Heap {
	public:
		void insert(T n) {
			v.emplace_back(n);
			heapfyMax();
		}

		T pop() {
			if (size() == 0)
				return -1;
			int top = v.front();
			v[0] = v.back();
			v.pop_back();

			int hsize = size();

			int n = 0;

			while (2 * n + 1 < hsize) {
				int parent, leftChild, rightChild;
				parent= v[n];
				leftChild = v[2 * n + 1];
				rightChild = (2 * n + 2 < hsize) ? v[2 * n + 2] : (leftChild - 1);
				if (leftChild > rightChild) {
					if (leftChild > parent) {
						v[n] = leftChild;
						v[2 * n + 1] = parent;
						n = 2 * n + 1;
					}
					else {
						break;
					}
				}
				else {
					if (rightChild > parent) {
						v[n] = rightChild;
						v[2 * n + 2] = parent;
						n = 2 * n + 2;
					}
					else {
						break;
					}
				}
			}

			return top;
		}

		void printHeap() {
			int hsize = size();
			int start = 0;
			int power2 = 1;
			int iter = 1;
			while (iter < hsize) {
				iter = start + power2;
				iter = iter > hsize ? hsize : iter;
				for (int i = start; i < iter; i++) {
					cout << left << setw(4) << v[i] << " ";
				}
				cout << endl;
				start = iter;
				power2 = 2 * power2;
			}
		}
		
	private:
		vector<T> v;
		int size() {
			return v.size();
		}
		void heapfyMax() {
			int hsize = size();
			if (hsize > 1) {
				int last = hsize - 1, parent;
				do {
					parent = (last - 1) / 2;
					if (v[last] > v[parent]) {
						int tmp = v[last];
						v[last] = v[parent];
						v[parent] = tmp;
					}
					else {
						break;
					}
					last = parent;
				} while (parent != 0);
			}
		}
		
	};

	void test() {
		Heap<int> heap;
		heap.insert(3);
		heap.insert(4);
		heap.insert(5);
		heap.insert(6);
		heap.insert(7);
		heap.insert(8);
		heap.insert(9);
		heap.insert(10);
		heap.insert(11);
		heap.insert(12);
		cout << "*************print heap***********" << endl;
		heap.printHeap();
		cout << "*************heap pop***********" << endl;
		cout << heap.pop() << endl;
		cout << "*************print heap***********" << endl;
		heap.printHeap();
		cout << "*************heap pop***********" << endl;
		cout << heap.pop() << endl;
		cout << "*************print heap***********" << endl;
		heap.printHeap();
		cout << "*************heap pop***********" << endl;
		cout << heap.pop() << endl;
		cout << "*************print heap***********" << endl;
		heap.printHeap();
		cout << "*************heap pop***********" << endl;
		cout << heap.pop() << endl;
		cout << "*************print heap***********" << endl;
		heap.printHeap();
		cout << "*************heap pop***********" << endl;
		cout << heap.pop() << endl;
		cout << "*************print heap***********" << endl;
		heap.printHeap();
		cout << "*************heap pop***********" << endl;
		cout << heap.pop() << endl;
		cout << "*************print heap***********" << endl;
		heap.printHeap();
		cout << "*************heap pop***********" << endl;
		cout << heap.pop() << endl;
		cout << "*************print heap***********" << endl;
		heap.printHeap();
		cout << "*************heap pop***********" << endl;
		cout << heap.pop() << endl;
		cout << "*************print heap***********" << endl;
		heap.printHeap();
		cout << "*************heap pop***********" << endl;
		cout << heap.pop() << endl;
	}
}