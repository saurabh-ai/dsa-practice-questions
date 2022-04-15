/*
Remove loop in Linked List 
Medium Accuracy: 47.96% Submissions: 100k+ Points: 4
Given a linked list of N nodes such that it may contain a loop.

A loop here means that the last node of the link list is connected to the node at position X. 
If the link list does not have any loop, X=0.

Remove the loop from the linked list, if it is present.  


Example 1:

Input:
N = 3
value[] = {1,3,4}
X = 2
Output: 1
Explanation: The link list looks like
1 -> 3 -> 4
     ^    |
     |____|    
A loop is present. If you remove it 
successfully, the answer will be 1. 
*/

// C++ program to detect and remove loop
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* next;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

// A utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL) {
		cout << head->key << " ";
		head = head->next;
	}
	cout << endl;
}

// Function to detect and remove loop
// in a linked list that may contain loop
void hashAndRemove(Node* head)
{
	// hash map to hash addresses of the linked list nodes
	unordered_map<Node*, int> node_map;
	// pointer to last node
	Node* last = NULL;
	while (head != NULL) {
		// if node not present in the map, insert it in the map
		if (node_map.find(head) == node_map.end()) {
			node_map[head]++;
			last = head;
			head = head->next;
		}
		// if present, it is a cycle, make the last node's next pointer NULL
		else {
			last->next = NULL;
			break;
		}
	}
}
/* Driver program to test above function*/
int main()
{
	Node* head = newNode(50);
	head->next = head;
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next->next;

	// printList(head);
	hashAndRemove(head);

	printf("Linked List after removing loop \n");
	printList(head);

	return 0;
}

