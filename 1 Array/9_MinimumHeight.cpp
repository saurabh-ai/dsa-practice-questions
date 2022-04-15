// Minimise the maximum difference between heights [V.IMP]

#include <bits/stdc++.h>

using namespace std;

 int getMinDiff(int arr[], int n, int k) {
       sort(arr, arr+n);
       int ans=arr[n-1]-arr[0]; // Difference of the smallest and the largest element
       int small=arr[0]+k;
       int large=arr[n-1]-k;    // In worst case scenario this stays the biggest value. No value before this becomes big after adding k
       int mn, mx;
       for(int i=0; i<n-1; i++)
       {    
           cout<<small<<"  -"<<arr[i+1]<<" "<<arr[i+1]-k<<" ___ "<<large<<"  +"<<arr[i]<<" "<<arr[i]+k<<endl;
           mn=min(small, arr[i+1]-k);
           mx=max(large, arr[i]+k);
           cout << mn <<" - "<<mx<<endl<<endl;
           if(mn<0)
           continue;
           else
           ans=min(ans, mx-mn);
       }
       return ans;
 }


int main(){
    int n,k;
    cin>>n>>k;
    int *arr = new int(n); 

    for(int i=0;i<n;i++) cin>>arr[i];

    
    cout<<getMinDiff(arr,n,k);
    
    //for(int i=0;i<n;i++) cout<<arr[i];

    return 0;
}