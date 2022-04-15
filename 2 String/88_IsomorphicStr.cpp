/*Two strings str1 and str2 are called isomorphic if there is a one-to-one mapping possible for every character of str1 to 
every character of str2. And all occurrences of every character in ‘str1’ map to the same character in ‘str2’.*/


// C# program to check if two strings
// areIsIsomorphic

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 26

// This function returns true if
// str1 and str2 are isomorphic
bool areIsomorphic(string str1, string str2)
{
	int n = str1.length(), m = str2.length();

	// Length of both strings must be
	// same for one to one
	// correspondence
	if (n != m)
		return false;

	// For counting the previous appearances of character in
	// both the strings
	int count[MAX_CHARS] = { 0 };
	int dcount[MAX_CHARS] = { 0 };

	// Process all characters one by one
	for (int i = 0; i < n; i++) {
		count[str1[i] - 'a']++;
		dcount[str2[i] - 'a']++;

		// For string to be isomorphic the previous counts
		// of appearances of
		// current character in both string must be same if
		// it is not same we return false.
		if (count[str1[i] - 'a'] != dcount[str2[i] - 'a'])
			return false;
	}
	return true;
}

// Driver Code
int main()
{
	cout << areIsomorphic("aab", "xxy") << endl;
	cout << areIsomorphic("aab", "xyz") << endl;
	return 0;
}

