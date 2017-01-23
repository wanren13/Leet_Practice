#pragma once

#include "allhead.h"

namespace copy_list_with_random_pointer {
	class Solution {
	public:
		RandomListNode *copyRandomList(RandomListNode *head) {
			unordered_map<RandomListNode*, RandomListNode*> visited;

			RandomListNode newhead = RandomListNode(0);
			RandomListNode* curr = &newhead;

			while (head) {
				if (visited.find(head) != visited.end())
					curr->next = visited[head];
				else {
					curr->next = new RandomListNode(head->label);
					visited[head] = curr->next;
				}

				curr = curr->next;

				RandomListNode* random = head->random;
				RandomListNode* tmp = curr;
				while (random) {
					if (visited.find(random) != visited.end()) {
						tmp->random = visited[random];
						break;
					}
					else {
						tmp->random = new RandomListNode(random->label);
						visited[random] = tmp->random;
						tmp = tmp->random;
						random = random->random;
					}
				}
				
				head = head->next;
			}

			return newhead.next;
		}
	};

	void test() {
		Solution sol;
		RandomListNode* head = new RandomListNode(1);
		//head->next = new RandomListNode(2);
		//head->next->random = head;
		//head->next->next = new RandomListNode(3);
		//head->random = head->next->next;
		//head->next->next->random = head->next->next;
		head = sol.copyRandomList(head);
	}
}