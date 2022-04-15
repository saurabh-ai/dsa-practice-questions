/*
Minimum Swaps to Sort 
Given an array of n distinct elements. Find the minimum number of swaps required 
to sort the array in strictly increasing order.

Example 1:

Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.

*/

// C++ program to find
// minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr,
		int i, int j)
{
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
// Return the minimum number
// of swaps required to sort
// the array
int minSwaps(vector<int>arr,
			int N)
{
int ans = 0;
vector<int>temp = arr;

// Hashmap which stores the
// indexes of the input array
map <int, int> h;

sort(temp.begin(), temp.end());
for (int i = 0; i < N; i++)
{
	h[arr[i]] = i;
}
for (int i = 0; i < N; i++)
{
	// This is checking whether
	// the current element is
	// at the right place or not
	if (arr[i] != temp[i])
	{
	ans++;
	int init = arr[i];

	// If not, swap this element
	// with the index of the
	// element which should come here
	swap(arr, i, h[temp[i]]);

	// Update the indexes in
	// the hashmap accordingly
	h[init] = h[temp[i]];
	h[temp[i]] = i;
	}
}
return ans;
}

// Driver class
int main()
{
// Driver program to
// test the above function
vector <int> a = {101, 758, 315,
					730, 472, 619,
					460, 479};
int n = a.size();

// Output will be 5
cout << minSwaps(a, n);
}

// This code is contributed by Stream_Cipher
