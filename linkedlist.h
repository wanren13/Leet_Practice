#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

namespace linkedlist {
	using namespace std;	

	struct Node {
		Node() :val(0), next(NULL) {}
		Node(int v, Node* n): val(v), next(n){}
		int val;
		Node* next;
	};

	void printList (Node* head) {
		while (head) {
			cout << head->val << " ";
			head = head->next;
		}
		cout << endl;
	}

	void generateList(Node** head, int size, int range) {
		*head = new Node();
		(*head)->val = rand() % range;
		Node* tmp = *head;
		for (int i = 0; i < size - 1; i++) {
			Node* newNode = new Node();
			newNode->val = rand() % range;
			tmp->next = newNode;
			tmp = tmp->next;
		}		
	}

	void generateOrderList(Node** head, int size) {
		*head = new Node();
		Node* tmp = *head;
		for (int i = 1; i < size; i++) {
			Node* newNode = new Node();
			newNode->val = i;
			tmp->next = newNode;
			tmp = tmp->next;
		}
	}

	bool findLoop(Node* head) {
		Node* slow = head;
		Node* fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast && fast != NULL) {
				return true;
			}
		}
		return false;
	}

	Node* findOverLap(Node* head) {
		Node* slow = head;
		Node* fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast && fast != NULL) {
				break;
			}
		}

		if (fast == NULL) {
			return fast;
		}

		slow = head;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}

		return slow;
	}

	Node* reverseList(Node* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		
		Node* curr = head->next;
		head->next = NULL;
		Node* next = curr->next;		
		Node* prehead = head;
		while (curr) {
			head = curr;
			head->next = prehead;
			prehead = head;
			curr = next;
			if (curr)
				next = curr->next;
		}
		return head;
	}

	Node* reverseListRec(Node* head) {
		// Node* newhead;
		if (head == NULL || head->next == NULL) {
			return head;
		}
		else {
			Node* newhead = reverseListRec(head->next);
			head->next = NULL;
			Node* tmp = newhead;
			while (tmp->next) {
				tmp = tmp->next;
			}
			tmp->next = head;
			return newhead;
		}
	}

	void destroyList(Node** head) {
		Node* next;
		while (*head) {
			next = (*head)->next;
			delete *head;
			*head = next;
		}
	}


	void test(){
		srand(time(NULL));
		Node* loophead = new Node();

		Node* node1 = new Node();
		node1->val = 1;
		loophead->next = node1;

		Node* node2 = new Node();
		node2->val = 2;
		node1->next = node2;

		node2->next = new Node(3, new Node(4, node2));

		cout << (findLoop(loophead) ? "True" : "False") << endl;
		Node* overlap = findOverLap(loophead);
		if (overlap) {
			cout << "Overlap: " << overlap->val << endl;
		}
		else {
			cout << "No overlap" << endl;
		}

		Node* listhead = NULL;
		generateOrderList(&listhead, 10);

		//cout << (findLoop(listhead) ? "True" : "False") << endl;
		//overlap = findOverLap(listhead);
		//if (overlap) {
		//	cout << "Overlap: " << overlap->val << endl;
		//}
		//else {
		//	cout << "No overlap" << endl;
		//}

		printList(listhead);
		Node* revList = reverseList(listhead);
		printList(revList);

		// destroyList(&loophead);
		//destroyList(&listhead);

		/*
		using namespace fibonacci;
		int num = 5000;

		clock_t start = clock();
		cout << fib(num) << endl;
		// your test
		cout << "Time for normal fibonacci: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;

		start = clock();
		//cout << fibRec(num) << endl;
		cout << "Time for normal fibonacci: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
		*/
	}
}