// C++ implementation of the approach
/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

Examples:  

Input: arr[]   = {2, 0, 2}
Output: 2
Explanation:
The structure is like below


We can trap 2 units of water in the middle gap.

Input: arr[]   = {3, 0, 2, 0, 4}
Output: 7
Explanation:
Structure is like below
 
 
 */



#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum
// water that can be stored
int maxWater(int height[], int n)
{
	
	// Stores the indices of the bars
	stack <int> st;

	// Stores the final result
	int ans = 0;

	// Loop through the each bar
	for(int i = 0; i < n; i++)
	{
		
		// Remove bars from the stack
		// until the condition holds
		while ((!st.empty()) &&
			(height[st.top()] < height[i]))
		{
			
			// Store the height of the top
			// and pop it.
			int pop_height = height[st.top()];
			st.pop();

			// If the stack does not have any
			// bars or the the popped bar
			// has no left boundary
			if (st.empty())
				break;

			// Get the distance between the
			// left and right boundary of
			// popped bar
			int distance = i - st.top() - 1;

			// Calculate the min. height
			int min_height = min(height[st.top()],
								height[i]) -
							pop_height;

			ans += distance * min_height;
		}

		// If the stack is either empty or
		// height of the current bar is less than
		// or equal to the top bar of stack
		st.push(i);
	}
	return ans;
}

// Driver code
int main()
{
	
	int arr[] = { 0, 1, 0, 2, 1, 0,
				1, 3, 2, 1, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	cout << maxWater(arr, n);

	return 0;
}

// The code is contributed by Soumitri Chattopadhyay
