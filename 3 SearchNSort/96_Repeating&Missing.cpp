/*
Given an unsorted array of size n. Array elements are in the range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. Find these two numbers.

Examples: 

 Input: arr[] = {3, 1, 3}
Output: Missing = 2, Repeating = 3
Explanation: In the array, 
2 is missing and 3 occurs twice 

Input: arr[] = {4, 3, 6, 2, 1, 1}
Output: Missing = 5, Repeating = 1
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Input:
	vector<int> arr = {4, 3, 6, 2, 1, 1};
	int n = arr.size();
	
	// Declaring output variables
	// Note : arr[i]-1 is used instead of arr[i] as we want to use all 64 bits
	int bitOr = (1 << (arr[0]-1));
	int repeating, missing;
	
	// Performing XOR as well as Checking repeating number
	for(int i=1; i<n; i++){
		// If OR operation with 1 gives same output that means, we already have 1 at that position
		if((bitOr | (1 << (arr[i]-1))) == bitOr) {
			repeating = arr[i];
			continue;
		}
		bitOr = (bitOr | (1 << (arr[i]-1)));
	}
	
	// Checking missing number
	for(int i=0; i<n; i++){
		// property: OR with 0 yield 1 hence value of bitOr changes
		if((bitOr | (1 << i)) != bitOr) {
			missing = i+1;
			break;
		}
	}
	
	cout << "Repeating : " << repeating << "\nMissing : " << missing;
	return 0;
}
