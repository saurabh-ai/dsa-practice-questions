/*

Input:  txt[] = "THIS IS A TEST TEXT"
        pat[] = "TEST"
Output: Pattern found at index 10

Input:  txt[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12

*/

#include <bits/stdc++.h>

using namespace std;




int main(){
    int n;
    cin>>n;
    int *arr = new int(n); 

    for(int i=0;i<n;i++) cin>>arr[i];

    for(int i=0;i<n;i++) cout<<arr[i];

    return 0;
}