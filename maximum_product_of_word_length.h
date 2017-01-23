#pragma once

#include "allhead.h"

namespace maximum_product_of_word_length {
	class Solution {
	public:
		int maxProduct(vector<string>& words) {
			unordered_map<int, int> maxlen;
			int result = 0;
			for (string word : words) {
				int mask = 0;
				for (char c : word)
					mask |= 1 << (c - 'a');
				maxlen[mask] = max(maxlen[mask], (int)word.size());
				for (auto maskAndLen : maxlen)
					if (!(mask & maskAndLen.first))
						result = max(result, (int)word.size() * maskAndLen.second);
			}
			return result;
		}
	};

	void test() {
		Solution s;
		vector<string> words;
		words.emplace_back("abcd");
		words.emplace_back("aef");

		cout << s.maxProduct(words) << endl;

	}




}