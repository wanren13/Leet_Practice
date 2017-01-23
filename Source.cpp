#ifdef MSVC
#pragma warning(disable : 4503)
#endif
#pragma warning(disable : 4503)



////
//////------------------------------------------------------------------------
////
////
////class Field {};
////
////typedef std::map<std::string, Field> Screen;
////typedef std::map<std::string, Screen> WebApp;
////typedef std::map<std::string, WebApp> WebAppTest;
////typedef std::map<std::string, WebAppTest> Hello;
//
//
//
//
////struct ListNode {
////	int val;
////	ListNode *next;
////	ListNode(int x) : val(x), next(NULL) {}
////};
////
////void print(ListNode *li) {
////	while (li) {
////		cout << li->val << endl;
////		li = li->next;
////	}
////}
////
////
////class Solution {
////public:
////	int lengthOfLongestSubstring(string s) {
////		int length = s.length();
////		if (length == 0)
////			return 0;
////		int head = 0;
////		int max = 1;
////		int find = 0;
////		while (head < length) {
////			for (int i = 1; i < length - head; i++) {
////				string substr = s.substr(head, i);
////				char chartotest = s[head + i];
////				if (substr.find(chartotest) == string::npos) {
////					find = i + 1;
////					max = max>find ? max : find;
////				}
////				else {
////					break;
////				}
////			}
////			if (max >= length - head) {
////				break;
////			}
////			head++;
////		}
////		return max;
////	}
////};
//
////
////struct TreeNode {
////	int val;
////	TreeNode *left;
////	TreeNode *right;
////	TreeNode(int x) : val(x), left(NULL), right(NULL) {};
////};
////
////
////
////void inorderMorrisTraversal(TreeNode *root) {
////	TreeNode *cur = root, *prev = NULL;
////	while (cur != NULL)
////	{
////		if (cur->left == NULL)          // 1.
////		{
////			printf("%d ", cur->val);
////			cur = cur->right;
////		}
////		else
////		{
////			// find predecessor
////			prev = cur->left;
////			while (prev->right != NULL && prev->right != cur)
////				prev = prev->right;
////
////			if (prev->right == NULL)   // 2.a)
////			{
////				prev->right = cur;
////				cur = cur->left;
////			}
////			else                       // 2.b)
////			{
////				prev->right = NULL;
////				printf("%d ", cur->val);
////				cur = cur->right;
////			}
////		}
////	}
////}
////
////int main()
////{
////	TreeNode *root = new TreeNode(6);
////	root->left = new TreeNode(2);
////	root->right = new TreeNode(7);
////	root->left->left = new TreeNode(1);
////	root->left->right = new TreeNode(4);
////	root->right->right = new TreeNode(9);
////	root->left->right->left = new TreeNode(3);
////	root->left->right->right = new TreeNode(5);
////	root->right->right->left = new TreeNode(8);
////	inorderMorrisTraversal(root);
////	return 0;
////}
////
//
//
//
//
//
//class Solution {
//public:
//	vector<int> findSubstring(string s, vector<string>& words) {
//		vector<int> list;
//		int strlen;
//		int wordlen;
//		int listlen = words.size();
//		vector<bool> boollist
//		if (listlen) {
//			wordlen = words[0].length();
//			strlen = s.length();
//
//			for (int i = 0; i <= strlen - wordlen; i++) {
//				string sstr = s.substr(i, wordlen);
//				//if (sstr = )
//			}
//
//
//		}
//
//
//		return list;
//	}
//
//	void reset()
//
//};
//
//int main() {
//	string s = "barfoothefoobarman";
//
//	// ["foo", "bar"]
//	vector<string> words;
//	words.emplace_back("foo");
//	words.emplace_back("bar");
//
//	vector<int> list;
//
//	Solution sol;
//
//	list = sol.findSubstring(s, words);
//
//	for (int i : list) {
//		cout << i << endl;
//	}
//
//	return 0;
//}














//
//std::string s = "a_b_c";
//size_t n = std::count(s.begin(), s.end(), '_');
//
//
//
//
//
//
//
//
//
//class Solution {
//public:
//	string removeDuplicateLetters(string s) {
//		int min = 25;
//		int minIdx = 0;
//		int letter[26] = { 0 };
//		for (int i = 0; i < s.length(); i++) {
//			int pos = s[i] - 'a';
//			if (pos < min) {
//				min = pos;
//				minIdx = i;
//			}
//			letter[pos]++;
//		}
//
//		int del = 0;
//		int start = 0;
//		int end = 0;
//
//
//		for (int i = 0; i < s.length();) {
//			int pos = s[i] - 'a';
//			start = i;
//			end = i;
//
//			if (letter[pos] >= 2) {
//				end++;
//			}
//
//			if (s[end] > s[end + 1])
//
//
//
//				if (letter[pos].second - del > minIdx && i < minIdx) {
//					s.erase(i, 1);
//					minIdx -= del;
//				}
//				else {
//					if (i < s.length() - 1 && s[i] - s[i + 1] >= 0) {
//						s.erase(i, 1);
//						minIdx--;
//					}
//				}
//				letter[pos].first--;
//			} 
//			else {
//				i++;
//			}
//		}
//
//};


//string str("(555) 555-5555");
//
//char chars[] = "()-";
//
//for (unsigned int i = 0; i < strlen(chars); ++i)
//{
//	// you need include <algorithm> to use general algorithms like std::remove()
//	str.erase(std::remove(str.begin(), str.end(), chars[i]), str.end());
//}
//
//// output: 555 5555555
//cout << str << endl;



































#include "linkedlist.h";
#include "fibonacci.h";
#include "heap.h";
#include "priority_queue.h"
#include "binary_tree.h"
#include "verify_preorder_serialization_of_a_binary_tree.h"
#include "valid_parenthesis.h"
#include "generate_parenthesis.h"
#include "letter_combinations.h"
#include "surrounded_regions.h"
#include "house_robber_iii.h"
#include "house_robber.h"
#include "balanced_binary_tree.h"
#include "BSTIterator.h"
#include "validBST.h"
#include "sortedlisttoBST.h"
#include "move_zeroes.h"
#include "merge_intervals.h"
#include "maximum_subarray.h"
#include "maximum_product_subarray.h"
#include "search_matrix.h"
#include "longest_consecutive_letters.h"
#include "singleton.h"
#include "find_smallest_base.h"
#include "array_addition.h"
#include "array_addone.h"
#include "length_of_last_word.h"
#include "string_to_integer.h"
#include "reverse_integer.h"
#include "add_binary.h"
#include "power_of_two.h"
#include "perfect_squares.h"
#include "count_primes.h"
#include "car_rental_design.h"
#include "inheritance_test.h"
#include "maximum_product_of_word_length.h"
#include "first_missing_positive.h"
#include "odd_even_linked_list.h"
#include "remove_linked_list_elements.h"
#include "remove_element.h"
#include "remove_duplicates_from_sorted_array.h"
#include "reverse_vowels_of_string.h"
#include "merge_k_sorted_lists.h"
#include "merge_two_sorted_lists.h"
#include "merge_sorted_arrays.h"
#include "insertion_sorted_list.h"
#include "set_matrix_zeroes.h"
#include "product_array_except_self.h"
#include "remove_duplicates_from_sorted_array_ii.h"
#include "three_sum.h"
#include "two_sum.h"
#include "three_sum_closest.h"
#include "minimum_size_subarray_sum.h"
#include "minimum_window_substring.h"
#include "first_bad_version.h"
#include "populating_next_right_pointers_in_each_node.h"
#include "course_schedule.h"
#include "array_test.h"
#include "directed_graph_test.h"
#include "unique_path_ii.h"
#include "jump_game.h"
#include "spiral_matrix.h"
#include "spiral_matrix_ii.h"
#include "search_a_2d_matrix.h"
#include "binary_search.h"
#include "hindex_ii.h"
#include "find_peak_element.h"
#include "summary_ranges.h"
//#include "combination_sum.h"
#include "combinations.h"
#include "remove_nth_node_from_end_of_list.h"
#include "reverse_linked_list.h"
#include "reverse_linked_list_ii.h"
#include "palindrome_number.h"
#include "palindrome_linked_list.h"
#include "top_k_frequent_elements.h"
#include "reorder_list.h"
#include "intersection_of_two_linked_lists.h"
#include "copy_list_with_random_pointer.h"
#include "integer_break.h"
#include "medianfinder.h"
#include "coin_change.h"
#include "reverse_words_in_a_string.h"
#include "maximal_rectangle.h"
#include "largest_rectangle_in_histogram.h"
#include "group_anagrams.h"
#include "intersection_of_two_arrays.h"
#include "valid_sudoku.h"
#include "longest_palindromic_substring.h"
#include "mySet.h"
#include "multiply_strings.h"
#include "decode_ways.h"
#include "simplify_path.h"
#include "flatten_binary_tree_to_linked_list.h"
#include "compare_version_numbers.h"
#include "range_sum_query_2d_immutable.h"
#include "longest_increasing_path_in_a_matrix.h"
#include "factorial_trailing_zeroes.h"
#include "count_and_say.h"
#include "range_sum_query_mutable.h"
#include "construct_binary_tree_from_preorder_and_inorder_traversal.h"
#include "serialize_and_deserialize_binary_tree.h"
#include "count_of_smaller_numbers_after_self.h"
#include "substring_with_concatenation_of_all_words.h"
#include "fraction_to_recurring_decimal.h"
#include "longest_substring_without_repeating_characters.h"
#include "sliding_window_maximum.h"
#include "search_insert.h"
//#include "implement_tire.h"
#include "add_and_search_word.h"
#include "LRU_cache.h"
#include "design_twitter.h"
#include "word_search.h"
#include "word_search_ii.h"
#include "maximum_submatrix.h"
#include "connect_cities.h"
#include "create_maximum_number.h"
#include "palindrome_pairs.h"
#include "permutations.h"
#include "longest_increasing_subsequence.h"
#include "kth_smallest_element_in_a_BST.h"
#include "search_for_a_range.h"
#include "russian_doll_envelope.h"
#include "increasing_triplet_subsequence.h"
#include "valid_perfect_square.h"
#include "interleaving_string.h"
#include "find_k_pairs_with_smallest_sums.h"
//#include "minimum_height_trees.h"
#include "game_of_life.h"
#include "best_time_to_buy_and_sell_stock_ii.h"
#include "longest_common_substring.h"
#include "candy.h"
#include "wiggle_subsequence.h"
#include "kth_smallest_element_in_a_sorted_matrix.h"
#include "contain_duplicate_iii.h"
#include "insert_delete_getrandom_duplicates_allowed.h"
#include "remove_duplicate_letters.h"
#include "edit_distance.h"
#include "remove_duplicates_from_sorted_list_ii.h"
#include "word_break.h"
#include "word_break_ii.h"
#include "lowest_common_ancestor_of_a_binary_search_tree.h"
#include "zigzag_conversion.h"
#include "container_with_most_water.h"
#include "reverse_nodes_in_k_group.h"
#include "practice.h"
#include "search_in_rotated_sorted_array.h"
#include "sort_colors.h"
#include "best_time_to_buy_and_sell_stock_iv.h"
#include "sum_root_to_leaf_numbers.h"
#include "binary_tree_preorder_traversal.h"
#include "subsets.h"
#include "permutations_ii.h"
#include "combination_sum_ii.h"
#include "restore_ip_addresses.h"
#include "combination_sum_iii.h"
#include "palindrome_partitioning.h"
#include "minimum_path_sum.h"
#include "dungeon_game.h"
#include "all_o_one_data_structure.h"
#include "findDuplicates.h"
#include "sort_characters__by_frequency.h"
#include "delete_node_in_a_bst.h"
#include "minimum_depth_of_binary_tree.h"
#include "four_sum_ii.h"
#include "LFU_cache.h"
#include "majority_element.h"
#include "gray_code.h"
#include "recover_binary_search_tree.h"
#include "construct_binary_tree_from_inorder_and_postorder_traversal.h"


int main() {
	srand(time(NULL));
	//	using namespace combination_sum;
	//	using namespace combinations;
	//	using namespace copy_list_with_random_pointer;
	//	using namespace maximal_rectangle;
	//	using namespace largest_rectangle_in_histogram;
	//	using namespace decode_ways;
	//	using namespace simplify_path;
	//	using namespace longest_increasing_path_in_a_matrix;
	using namespace find_peak_element;
	//  using namespace majority_element;
	//  using namespace recover_binary_search_tree;
	//	using namespace kth_smallest_element_in_a_BST;
	//	using namespace russian_doll_envelop;
	// using namespace increasing_triplet_subsequence;
	// using namespace interleaving_string;
	// using namespace directed_graph_test;
	// using namespace course_schedule;
	// using namespace minimum_height_trees;
	// using namespace kth_smallest_element_in_a_sorted_matrix;
	// using namespace contain_duplicate_iii;
	// using namespace word_break_ii;
	//using namespace lowest_common_ancestor_of_a_binary_search_tree;
	clock_t begin = clock();

	test();

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "\nRunning time : " << elapsed_secs << endl;

	//char c = 'b';
	//string str = string();
	//string::iterator biter = str.begin();
	//string::iterator eiter = str.end();
	//


	//if (biter == eiter) {
	//	cout << "Hello there1" << endl;
	//}


	//str = "abc";


	//if (eiter == str.end()) {
	//	cout << "Hello there2" << endl;
	//}


	// iter++;
	// cout << *iter << endl;

	//iter++; // = str.end();
	//if (iter == str.end()) {
	//	cout << "Hi there" << endl;
	//}

	//str.insert(iter, c);

	//iter++;

	//cout << str << endl;

	return 0;
}


