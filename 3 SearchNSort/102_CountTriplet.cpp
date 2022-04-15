/*
Count triplets with sum smaller than X 
Medium Accuracy: 49.96% Submissions: 29732 Points: 4
Given an array arr[] of distinct integers of size N and a value sum, the task is to 
find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) 
smaller than the given value sum.


Example 1:


Input: N = 4, sum = 2
arr[] = {-2, 0, 1, 3}
Output:  2
Explanation: Below are triplets with 
sum less than 2 (-2, 0, 1) and (-2, 0, 3). 
*/

// C++ program to count triplets with sum smaller than a given value
#include<bits/stdc++.h>
using namespace std;

int countTriplets(int arr[], int n, int sum)
{
	// Sort input array
	sort(arr, arr+n);

	// Initialize result
	int ans = 0;

	// Every iteration of loop counts triplet with
	// first element as arr[i].
	for (int i = 0; i < n - 2; i++)
	{
		// Initialize other two elements as corner elements
		// of subarray arr[j+1..k]
		int j = i + 1, k = n - 1;

		// Use Meet in the Middle concept
		while (j < k)
		{
			// If sum of current triplet is more or equal,
			// move right corner to look for smaller values
			if (arr[i] + arr[j] + arr[k] >= sum)
				k--;

			// Else move left corner
			else
			{
				// This is important. For current i and j, there
				// can be total k-j third elements.
				ans += (k - j);
				j++;
			}
		}
	}
	return ans;
}

// Driver program
int main()
{
	int arr[] = {5, 1, 3, 4, 7};
	int n = sizeof arr / sizeof arr[0];
	int sum = 12;
	cout << countTriplets(arr, n, sum) << endl;
	return 0;
}
