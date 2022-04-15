/*
Permutation refers to the process of arranging all the members of a given set to form a sequence. The number of permutations on 
a set of n elements is given by n! , where “!” represents factorial. 

The Permutation Coefficient represented by P(n, k) is used to represent the number of ways to obtain an ordered subset having 
k elements from a set of n elements.
Mathematically it’s given as: 
 

permu

Image Source : Wiki
Examples : 

P(10, 2) = 90
P(10, 3) = 720
P(10, 0) = 1
P(10, 1) = 10
*/

// A O(n) time and O(1) extra
// space solution to calculate
// the Permutation Coefficient
#include <iostream>
using namespace std;

int PermutationCoeff(int n, int k)
{
	int P = 1;

	// Compute n*(n-1)*(n-2)....(n-k+1)
	for (int i = 0; i < k; i++)
		P *= (n-i) ;

	return P;
}

// Driver Code
int main()
{
	int n = 10, k = 2;
	cout << "Value of P(" << n << ", " << k
		<< ") is " << PermutationCoeff(n, k);

	return 0;
}

