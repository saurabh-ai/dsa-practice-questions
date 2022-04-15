/*
Coin Change 
Medium Accuracy: 47.19% Submissions: 68465 Points: 4
Given a value N, find the number of ways to make change for N cents, if we have infinite supply 
of each of S = { S1, S2, .. , SM } valued coins.


Example 1:

Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.
*/

#include <bits/stdc++.h>
using namespace std;

int coinchange(vector<int>& a, int v, int n,
			vector<vector<int> >& dp)
{
	if (v == 0)
		return dp[n][v] = 1;
	if (n == 0)
		return 0;
	if (dp[n][v] != -1)
		return dp[n][v];
	if (a[n - 1] <= v) {
		// Either Pick this coin or not
		return dp[n][v] = coinchange(a, v - a[n - 1], n, dp)
						+ coinchange(a, v, n - 1, dp);
	}
	else // We have no option but to leave this coin
		return dp[n][v] = coinchange(a, v, n - 1, dp);
}
int32_t main()
{
	int tc = 1;
	// cin >> tc;
	while (tc--) {
		int n, v;
		n = 3, v = 4;
		vector<int> a = { 1, 2, 3 };
		vector<vector<int> > dp(n + 1, vector<int>(v + 1, -1));
		int res = coinchange(a, v, n, dp);
		cout << res << endl;
	}
}
// This Code is Contributed by
// Harshit Agrawal NITT

