/*
Sort by Set Bit Count 
Given an array of integers, sort the array (in descending order) according to count of set 
bits in binary representation of array elements. 

Note: For integers having same number of set bits in their binary representation, sort 
according to their position in the original array i.e., a stable sort.

 
Example 1:
Input: 
arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
Output:
15 7 5 3 9 6 2 4 32
Explanation:
The integers in their binary
representation are:
15 - 1111
7  - 0111
5  - 0101
3  - 0011
9  - 1001
6  - 0110
2  - 0010
4  - 0100
32 - 10000
hence the non-increasing sorted order is:
{15}, {7}, {5, 3, 9, 6}, {2, 4, 32}
*/

// C++ program to implement
// simple approach to sort
// an array according to
// count of set bits.
#include<bits/stdc++.h>
using namespace std;

// Function to count setbits
int setBitCount(int num){
	int count = 0;
	while ( num )
	{
		if ( num & 1)
		count++;
		num >>= 1;
	}
	return count;
}

// Function to sort By SetBitCount
void sortBySetBitCount(int arr[], int n)
{
	multimap< int, int > count;

	// Iterate over all values and
	// insert into multimap
	for( int i = 0 ; i < n ; ++i )
	{
		count.insert({(-1) *
			setBitCount(arr[i]), arr[i]});
	}

	for(auto i : count)
	cout << i.second << " " ;
	cout << "\n" ;
}

// Driver Code
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	sortBySetBitCount(arr, n);
}

// This code is contributed by Ashok Karwa
