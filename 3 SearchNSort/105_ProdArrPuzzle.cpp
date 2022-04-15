/*
Product array puzzle 
Easy Accuracy: 47.32% Submissions: 68028 Points: 2
Given an array nums[] of size n, construct a Product Array P (of same size n) such 
that P[i] is equal to the product of all the elements of nums except nums[i].

 

Example 1:

Input:
n = 5
nums[] = {10, 3, 5, 6, 2}
Output:
180 600 360 300 900
Explanation: 
For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.
*/

// C++ program for the above approach
#include <iostream>
using namespace std;

long* productExceptSelf(int a[], int n)
{
	long prod = 1;
	long flag = 0;

	// product of all elements
	for (int i = 0; i < n; i++) {

		// counting number of elements
		// which have value
		// 0
		if (a[i] == 0)
			flag++;
		else
			prod *= a[i];
	}

	// creating a new array of size n
	long* arr = new long[n];

	for (int i = 0; i < n; i++) {

		// if number of elements in
		// array with value 0
		// is more than 1 than each
		// value in new array
		// will be equal to 0
		if (flag > 1) {
			arr[i] = 0;
		}

		// if no element having value
		// 0 than we will
		// insert product/a[i] in new array
		else if (flag == 0)
			arr[i] = (prod / a[i]);

		// if 1 element of array having
		// value 0 than all
		// the elements except that index
		// value , will be
		// equal to 0
		else if (flag == 1 && a[i] != 0) {
			arr[i] = 0;
		}

		// if(flag == 1 && a[i] == 0)
		else
			arr[i] = prod;
	}
	return arr;
}

// Driver Code
int main()
{
	int n = 5;
	int array[] = { 10, 3, 5, 6, 2 };

	long* ans;
	ans = productExceptSelf(array, n);

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	// cout<<"GFG!";
	return 0;
}

// This code is contributed by RohitOberoi.

