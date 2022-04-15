/*
Implement two stacks in an array 
Easy Accuracy: 49.76% Submissions: 71563 Points: 2
Your task is to implement  2 stacks in one array efficiently.

Example 1:
Input:
push1(2)
push1(3)
push2(4)
pop1()
pop2()
pop2()

Output:
3 4 -1

Explanation:
push1(2) the stack1 will be {2}
push1(3) the stack1 will be {2,3}
push2(4) the stack2 will be {4}
pop1()   the poped element will be 3 
from stack1 and stack1 will be {2}
pop2()   the poped element will be 4 
from stack2 and now stack2 is empty
pop2()   the stack2 is now empty hence -1 .
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

class twoStacks {
	int* arr;
	int size;
	int top1, top2;

public:
	twoStacks(int n) // constructor
	{
		size = n;
		arr = new int[n];
		top1 = -1;
		top2 = size;
	}

	// Method to push an element x to stack1
	void push1(int x)
	{
		// There is at least one empty space for new element
		if (top1 < top2 - 1) {
			top1++;
			arr[top1] = x;
		}
		else {
			cout << "Stack Overflow";
			exit(1);
		}
	}

	// Method to push an element x to stack2
	void push2(int x)
	{
		// There is at least one empty
		// space for new element
		if (top1 < top2 - 1) {
			top2--;
			arr[top2] = x;
		}
		else {
			cout << "Stack Overflow";
			exit(1);
		}
	}

	// Method to pop an element from first stack
	int pop1()
	{
		if (top1 >= 0) {
			int x = arr[top1];
			top1--;
			return x;
		}
		else {
			cout << "Stack UnderFlow";
			exit(1);
		}
	}

	// Method to pop an element from second stack
	int pop2()
	{
		if (top2 < size) {
			int x = arr[top2];
			top2++;
			return x;
		}
		else {
			cout << "Stack UnderFlow";
			exit(1);
		}
	}
};

/* Driver program to test twoStacks class */
int main()
{
	twoStacks ts(5);
	ts.push1(5);
	ts.push2(10);
	ts.push2(15);
	ts.push1(11);
	ts.push2(7);
	cout << "Popped element from stack1 is "
		<< ts.pop1();
	ts.push2(40);
	cout << "\nPopped element from stack2 is "
		<< ts.pop2();
	return 0;
}

