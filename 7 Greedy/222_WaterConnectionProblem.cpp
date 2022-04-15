/*
Water Connection Problem 
Medium Accuracy: 60.08% Submissions: 7368 Points: 4
There are n houses and p water pipes in Geek Colony. Every house has at most one pipe going into it and at most one pipe 
going out of it. Geek needs to install pairs of tanks and taps in the colony according to the following guidelines.  
1. Every house with one outgoing pipe but no incoming pipe gets a tank on its roof.
2. Every house with only one incoming and no outgoing pipe gets a tap.
The Geek council has proposed a network of pipes where connections are denoted by three input values: 
ai, bi, di denoting the pipe of diameter di from house ai to house bi.
Find a more efficient way for the construction of this network of pipes. Minimize the diameter of pipes 
wherever possible.
Note: The generated output will have the following format. The first line will contain t, denoting the total 
number of pairs of tanks and taps installed. The next t lines contain three integers each: house number of tank, 
house number of tap, and the minimum diameter of pipe between them.


Example 1:

Input:
n = 9, p = 6
a[] = {7,5,4,2,9,3}
b[] = {4,9,6,8,7,1}
d[] = {98,72,10,22,17,66} 
Output: 
3
2 8 22
3 1 66
5 6 10
Explanation:
Connected components are 
3->1, 5->9->7->4->6 and 2->8.
Therefore, our answer is 3 
followed by 2 8 22, 3 1 66, 5 6 10.
*/


// C++ program to find efficient
// solution for the network
#include <bits/stdc++.h>
using namespace std;

// number of houses and number
// of pipes
int n, p;

// Array rd stores the
// ending vertex of pipe
int rd[1100];

// Array wd stores the value
// of diameters between two pipes
int wt[1100];

// Array cd stores the
// starting end of pipe
int cd[1100];

// Vector a, b, c are used
// to store the final output
vector<int> a;
vector<int> b;
vector<int> c;

int ans;

int dfs(int w)
{
	if (cd[w] == 0)
		return w;
	if (wt[w] < ans)
		ans = wt[w];
	return dfs(cd[w]);
}

// Function performing calculations.
void solve(int arr[][3])
{
	int i = 0;

	while (i < p) {
		
		int q = arr[i][0], h = arr[i][1],
			t = arr[i][2];
		
		cd[q] = h;
		wt[q] = t;
		rd[h] = q;
		i++;
	}
	
	a.clear();
	b.clear();
	c.clear();
	
	for (int j = 1; j <= n; ++j)
	
		/*If a pipe has no ending vertex
		but has starting vertex i.e is
		an outgoing pipe then we need
		to start DFS with this vertex.*/
		if (rd[j] == 0 && cd[j]) {
			ans = 1000000000;
			int w = dfs(j);
			
			// We put the details of component
			// in final output array
			a.push_back(j);
			b.push_back(w);
			c.push_back(ans);
		}
		
	cout << a.size() << endl;
	for (int j = 0; j < a.size(); ++j)
		cout << a[j] << " " << b[j]
			<< " " << c[j] << endl;
}

// driver function
int main()
{
	n = 9, p = 6;

	memset(rd, 0, sizeof(rd));
	memset(cd, 0, sizeof(cd));
	memset(wt, 0, sizeof(wt));

	int arr[][3] = { { 7, 4, 98 },
					{ 5, 9, 72 },
					{ 4, 6, 10 },
					{ 2, 8, 22 },
					{ 9, 7, 17 },
					{ 3, 1, 66 } };

	solve(arr);
	return 0;
}

