#include <bits/stdc++.h>

using namespace std;

/*
2 3
10 12
5 18 20


As we have given two sorted array so we will start with first one's ending as when we 
start from there we are already at the largest element of 1st array now we will compare 
it with the 1st element of arr2 if arr2[1] < arr1[n-1] we will swap them . now similar will 
continue for while arr1 and after completion we will get the arr1 elements which are larger 
than arr2's element swapped not as both array will be unsorted now we will sort them both…  
A slight modification can also b done if during the process a no is not swapped it means now 
no number will be swapped after words so we will break the loop.

*/


int main(){
    int n,m;
    cin>>n>>m;
    int *arr1 = new int(n); 
    int *arr2 = new int(m); 

    for(int i=0;i<n;i++) cin>>arr1[i];
    for(int i=0;i<m;i++) cin>>arr2[i];
                     

    int i=n-1,j=0;
    while(i>=0&&j<m)    // Start to end of one array. End to start of other array
    {
      if(arr1[i]>arr2[j]){
      swap(arr1[i],arr2[j]);
      i--;j++;}

     else break;
    }
/*
    for(int i=0;i<n;i++) cout<<arr1[i]<<" ";
    cout<<endl;
    for(int i=0;i<m;i++) cout<<arr2[i]<<" ";
    cout<<endl;
*/
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
/*
    for(int i=0;i<n;i++) cout<<arr1[i]<<" ";
    cout<<endl;
    for(int i=0;i<m;i++) cout<<arr2[i]<<" ";
    */

    return 0;
}

