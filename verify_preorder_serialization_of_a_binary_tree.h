#pragma once

#include <stack>
#include <iostream>


using namespace std;

namespace verify_preorder_serialization_of_a_binary_tree{
	
	//class Solution {
	//public:
	//	bool isValidSerialization(string preorder) {
	//		int len = preorder.length();
	//		int diff = 1, i = 0;
	//		while (i < len) {
	//			if (--diff < 0) return false;
	//			if (preorder[i] != '#') diff += 2;				
	//			while (i < len && preorder[i] != ',') {
	//				i++;
	//			}
	//			i++;
	//		}

	//		return diff == 0;
	//	}
	//};

	class Solution {
	public:
		bool isValidSerialization(string preorder) {
			int edge = 1;
			for (int i = 0; i < preorder.length(); i += 2) {
				if (--edge < 0) return false;
				if (preorder[i] != '#') edge += 2;
			}
			return edge == 0;
		}
	};


	void test() {
		//Solution sol;
		//string str =
		//	"9,3,4,#,#,1,#,#,2,#,6,#,#";
		//	// "#,7,6,9,#,#,#";
		//cout << (sol.isValidSerialization(str)?"Is valid serialization":"Is not valid serialization") << endl;

	}

}