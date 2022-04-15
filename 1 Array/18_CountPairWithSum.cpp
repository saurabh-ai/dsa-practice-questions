#include <bits/stdc++.h>

using namespace std;

/*
Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

4 6 
1 5 7 1

*/

    int getPairsCount(int arr[], int n, int k) {
        sort(arr,arr+n);
        int i=0;
        int j=n-1;
        int c=0;
        while(i<j){
            if(arr[i]+arr[j]==k){
                c++;
                int m=i+1;
                while(m<j && (arr[m]+arr[j]) == k){
                    c++;
                    m++;
                }
                j--;
            }
            else if(arr[i]+arr[j] < k){
                i++;
            }
            else if(arr[i]+arr[j] > k){
                j--;
            }
        }
        return c;
    }



int main(){
    int n,k;
    cin>>n>>k;
    int *arr = new int(n); 

    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<getPairsCount(arr,n,k);

    //for(int i=0;i<n;i++) cout<<arr[i];

    return 0;
}