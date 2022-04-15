/*
Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array. 

Examples: 

Input : arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125}    
        x = 5
Output : First Occurrence = 2
         Last Occurrence = 5

Input : arr[] = {1, 3, 5, 5, 5, 5, 7, 123, 125 }    
        x = 7
Output : First Occurrence = 6
         Last Occurrence = 6
*/

#include <bits/stdc++.h>
using namespace std;

void findFirstAndLast(int arr[], int n, int x)
{
	int first, last;
	// to store first occurrence
	first = lower_bound(arr, arr + n, x) - arr;
	// to store last occurrence
	last = upper_bound(arr, arr + n, x) - arr - 1;

	if (first == n) {
		first = -1;
		last = -1;
	}
	cout << "First Occurrence = " << first
		<< "\nLast Occurrence = " << last;
}

// Driver code
int main()
{
	int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
	int n = sizeof(arr) / sizeof(int);
	int x = 8;
	findFirstAndLast(arr, n, x);
	return 0;
}
