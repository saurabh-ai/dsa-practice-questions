/*
Given an array Arr of N positive integers, find K largest elements from the array.  The output elements should be 
printed in decreasing order.

Example 1:

Input:
N = 5, K = 2
Arr[] = {12, 5, 787, 1, 23}
Output: 787 23
Explanation: 1st largest element in the
array is 787 and second largest is 23.
*/

#include <bits/stdc++.h>
using namespace std;

//picks up last element between start and end
int findPivot(int a[], int start, int end)
{
	
	// Selecting the pivot element
	int pivot = a[end];

	// Initially partition-index will be
	// at starting
	int pIndex = start;

	for (int i = start; i < end; i++) {
	
		// If an element is lesser than pivot, swap it.
		if (a[i] <= pivot) {
			swap(a[i], a[pIndex]);
		
			// Incrementing pIndex for further
			// swapping.
			pIndex++;
		}
	}

	// Lastly swapping or the
	// correct position of pivot
	swap(a[pIndex], a[end]);
	return pIndex;
}


//THIS PART OF CODE IS CONTRIBUTED BY - rjrachit
//Picks up random pivot element between start and end
int findRandomPivot(int arr[], int start, int end)
{
	int n = end - start + 1;
	// Selecting the random pivot index
	int pivotInd = random()%n;
	swap(arr[end],arr[start+pivotInd]);
	int pivot = arr[end];
	//initialising pivoting point to start index
	pivotInd = start;
	for (int i = start; i < end; i++) {
	
		// If an element is lesser than pivot, swap it.
		if (arr[i] <= pivot) {
			swap(arr[i], arr[pivotInd]);
		
			// Incrementing pivotIndex for further
			// swapping.
			pivotInd++;
		}
	}

	// Lastly swapping or the
	// correct position of pivot
	swap(arr[pivotInd], arr[end]);
	return pivotInd;
}
//THIS PART OF CODE IS CONTRIBUTED BY - rjrachit

void SmallestLargest(int a[], int low, int high, int k,
					int n)
{
	if (low == high)
		return;
	else {
		int pivotIndex = findRandomPivot(a, low, high);

		if (k == pivotIndex) {
			cout << k << " smallest elements are : ";
			for (int i = 0; i < pivotIndex; i++)
				cout << a[i] << " ";

			cout << endl;

			cout << k << " largest elements are : ";
			for (int i = (n - pivotIndex); i < n; i++)
				cout << a[i] << " ";
		}

		else if (k < pivotIndex)
			SmallestLargest(a, low, pivotIndex - 1, k, n);

		else if (k > pivotIndex)
			SmallestLargest(a, pivotIndex + 1, high, k, n);
	}
}

// Driver Code
int main()
{
	int a[] = { 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };
	int n = sizeof(a) / sizeof(a[0]);

	int low = 0;
	int high = n - 1;

	// Lets assume k is 3
	int k = 4;

	// Function Call
	SmallestLargest(a, low, high, k, n);

	return 0;
}

