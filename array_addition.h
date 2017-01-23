#pragma once

#include "allhead.h"

namespace array_addition {
	//class Solution {
	//public:
	//	vector<int> sum(vector<int> v1, vector<int> v2) {
	//		int base = 10;
	//		int size1 = v1.size();
	//		int size2 = v2.size();
	//		if (size1 == 0) return v1;
	//		if (size2 == 0) return v2;
	//		int size = max(size1, size2);
	//		v1.insert(v1.begin(), 0);
	//		v2.insert(v2.begin(), 0);
	//		vector<int> result(size, 0);
	//		int num1, num2;
	//		bool carry = false;
	//		int carrybit = 0;
	//		vector<int>::iterator iter1 = v1.end();
	//		vector<int>::iterator iter2 = v2.end();
	//		vector<int>::iterator iter3 = result.end();

	//		for (int i = 0; i < size; i++) {
	//			if (iter1 != v1.begin()) {
	//				iter1--;
	//				num1 = *iter1;
	//			}
	//			else {
	//				num1 = 0;
	//			}

	//			if (iter2 != v2.begin()) {
	//				iter2--;
	//				num2 = *iter2;
	//			}
	//			else {
	//				num2 = 0;
	//			}
	//			iter3--;
	//			int s = num1 + num2 + carrybit;
	//			carry = (s > base);
	//			if (carry) {
	//				*iter3 = s - base;
	//				carrybit = 1;
	//			}
	//			else {
	//				*iter3 = s;
	//				carrybit = 0;
	//			}
	//		}
	//		if (carry) result.insert(result.begin(), 1);
	//		
	//		return result;
	//	}
	//};

	//
	//void test() {

	//	Solution s;
	//	vector<int> v1;
	//	vector<int> v2;

	//	// vector<int>::iterator iter = v2.end() - 1;

	//	int n = 7, base = 10;
	//	for (int i = 0; i < n; i++) {
	//		int num = rand() % base;
	//		while (i == 0 && num == 0) num = rand() % base;
	//		v1.emplace_back(num);
	//	}

	//	// cout << *(v1.end() - 1) << endl;

	//	n = 10;

	//	for (int i = 0; i < n; i++) {
	//		int num = rand() % base;
	//		while (i == 0 && num == 0) num = rand() % base;
	//		v2.emplace_back(num);
	//	}

	//	for (int i : v1) {
	//		cout << i;
	//	}
	//	cout << endl << "+" << endl;

	//	for (int i : v2) {
	//		cout << i;
	//	}
	//	cout << endl;


	//	vector<int> result = s.sum(v1, v2);

	//	for (int i : result) {
	//		cout << i;
	//	}
	//	cout << endl;

	//}



class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* root = NULL;
		ListNode* temp = NULL;
		int num1 = 0, num2 = 0, num3 = 0, carrybit = 0;
		bool carry = false;
		while (l1 || l2) {
			if (l1) {
				num1 = l1->val;
				l1 = l1->next;
			}
			else {
				num1 = 0;
			}
			if (l2) {
				num2 = l2->val;
				l2 = l2->next;
			}
			else {
				num2 = 0;
			}
			num3 = num1 + num2 + carrybit;
			carry = (num3 > 9);
			if (carry) {
				num3 = num3 - 10;
				carrybit = 1;
			}
			else {
				carrybit = 0;
			}

			if (!temp) {
				root = new ListNode(num3);
				temp = root;
			}
			else {
				temp->next = new ListNode(num3);
				temp = temp->next;
			}
		}
		if (carry) temp->next = new ListNode(carrybit);

		return root;
	}
};

}