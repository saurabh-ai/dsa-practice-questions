/*
Given a m x n rectangle, how many squares are there in it?

Examples : 

Input:  m = 2, n = 2
Output: 5
There are 4 squares of size 1x1 + 1 square of size 2x2.

Input: m = 4, n = 3
Output: 20
There are 12 squares of size 1x1 + 
          6 squares of size 2x2 + 
          2 squares of size 3x3.
*/

// C++ program to count squares
// in a rectangle of size m x n
#include <iostream>
using namespace std;

// Returns count of all squares
// in a rectangle of size m x n
int countSquares(int m, int n)
{

	// If n is smaller, swap m and n
	if (n < m) {
		int temp = m;
		m = n;
		n = temp;
	}

	// Now n is greater dimension,
	// apply formula
	return n * (n + 1) * (3 * m - n + 1) / 6;
}

// Driver Code
int main()
{
	int m = 4, n = 3;
	cout << "Count of squares is " << countSquares(m, n);
}

// This code is contributed by 29AjayKumar
