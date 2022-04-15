/*
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i]amount of money present in it.

Example 1:

Input:
n = 6
a[] = {5,5,10,100,10,5}
Output: 110
Explanation: 5+100+5=110
*/

// C++ program to find the maximum stolen value
#include <iostream>
using namespace std;

// calculate the maximum stolen value
int maxLoot(int *hval, int n)
{
	if (n == 0)
		return 0;

	int value1 = hval[0];
	if (n == 1)
		return value1;

	int value2 = max(hval[0], hval[1]);
	if (n == 2)
		return value2;

	// contains maximum stolen value at the end
	int max_val;

	// Fill remaining positions
	for (int i=2; i<n; i++)
	{
		max_val = max(hval[i]+value1, value2);
		value1 = value2;
		value2 = max_val;
	}

	return max_val;
}

// Driver to test above code
int main()
{
	// Value of houses
	int hval[] = {6, 7, 1, 3, 8, 2, 4};
	int n = sizeof(hval)/sizeof(hval[0]);
	cout << "Maximum loot possible : "
		<< maxLoot(hval, n);
	return 0;
}
