#pragma once

#include "allhead.h"

namespace array_test {
	//void array_func(int arr[]) {
	//	cout << "Array size is " << sizeof(arr) / sizeof(int) << endl;
	//	arr[0] = 3;
	//	arr[1] = 2;
	//	arr[2] = 1;
	//}

	void reftest(int& i) {
		i++;
	}

	
	void test() {
		//istringstream is("1, 2,3,4");
		//int i;
		//string s;
		//while (is >> s) {
		//	cout << s << endl;
		//	if (is.peek() == ',') is.ignore();
		//}

		for (int i = 0; i < 10; i++) {
			i += 2;
			cout << i << endl;
		}
	}
}