// C++ program to remove consecutive
// duplicates from a given string.
#include <bits/stdc++.h>
using namespace std;

// A iterative function that removes
// consecutive duplicates from string S
string removeDuplicates(string s){
	
int n = s.length();
string str="";
// We don't need to do anything for
// empty string.
if (n == 0)
	return str;

// Traversing string
	for(int i=0;i<n-1;i++){
	//checking if s[i] is not same as s[i+1] then add it into str
		if(s[i]!=s[i+1]){
			str+=s[i];
		}
	}
//Since the last character will not be inserted in the loop we add it at the end
str.push_back(s[n-1]);
return str;
}

// Driver Program
int main() {
	
	string s1 = "geeksforgeeks";
	cout << removeDuplicates(s1) << endl;
	
	string s2 = "aabcca";
	cout << removeDuplicates(s2) << endl;
	
	return 0;
}
