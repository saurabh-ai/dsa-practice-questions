#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n;
    cin>>k;
    int *arr = new int(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);
    cout<< arr[k-1];

    return 0;
}