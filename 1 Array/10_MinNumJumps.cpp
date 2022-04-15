#include <bits/stdc++.h>

using namespace std;

int minJumps(int arr[], int n){

     int jump=1,m=arr[0],step=arr[0];
     if(n<=1)
         return 0;
     if(arr[0]==0)
         return -1;
     for(int i=1;i<n-1;i++){
         cout<<m<<" "<<i<<" "<<i+arr[i]<<endl;
         m=max(m,i+arr[i]);
         step--;
        cout<<m<<" "<<step<<endl;
         if(m==n) return jump+1;
         if(step==0){
             jump++;
             if(i>m-1)
                 return -1;
             step=m-i;
         }
     }
     return jump;
  }


int main(){
    int n;
    cin>>n;
    int *arr = new int(n); 

    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<minJumps(arr,n);
    
    //for(int i=0;i<n;i++) cout<<arr[i];

/*
11
1 3 5 8 9 2 6 7 6 8 9

*/

    return 0;
}