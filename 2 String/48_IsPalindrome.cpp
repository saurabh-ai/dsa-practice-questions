#include <bits/stdc++.h>

using namespace std;


int isPalindrome(string S)
{
	for(int i = 0; i < S.size()/2; i++)
	    if(S[i] != S[S.size() - i - 1]) return 0;
	return 1;
}


int main(){
    string s="HelloolleH";

    cout<<isPalindrome(s);

    return 0;
}
