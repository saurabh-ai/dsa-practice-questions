#include<iostream>

using namespace std;

int main(){ 
    
    int n;
    cin>>n;
    int* arrInput = new int(n);
    
    for(int i=0;i<n;i++){
        cin >> arrInput[i];
    }
    
    for(int i=n-1;i>=0;i--){
        cout<< arrInput[i]<<" ";
    }

    return 0;
}