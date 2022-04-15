/*
Reverse a Linked List in groups of given size. 
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in 
the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should be 
considered as a group and must be reversed (See Example 2 for clarification).

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.
*/

// CPP program to reverse a linked list
// in groups of given size
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
};

/* Reverses the linked list in groups
of size k and returns the pointer
to the new head node. */
Node* reverse(Node* head, int k)
{
	// base case
	if (!head)
		return NULL;
	Node* current = head;
	Node* next = NULL;
	Node* prev = NULL;
	int count = 0;

	/*reverse first k nodes of the linked list */
	while (current != NULL && count < k) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	/* next is now a pointer to (k+1)th node
	Recursively call for the list starting from current.
	And make rest of the list as next of first node */
	if (next != NULL)
		head->next = reverse(next, k);

	/* prev is new head of the input list */
	return prev;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print linked list */
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	/* Created Linked list
	is 1->2->3->4->5->6->7->8->9 */
	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	cout << "Given linked list \n";
	printList(head);
	head = reverse(head, 3);

	cout << "\nReversed Linked list \n";
	printList(head);

	return (0);
}

// This code is contributed by rathbhupendra
