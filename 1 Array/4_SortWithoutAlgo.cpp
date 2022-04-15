//Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int *arr = new int(n); 

    for(int i=0;i<n;i++) cin>>arr[i];

    int numberOfTwos = 0;
    int numberOfOnes = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) numberOfOnes++;
        if (arr[i] == 2) numberOfTwos++;
    }
        
    for (int i = 0; i < n; i++) {
        if (i < (n - (numberOfOnes + numberOfTwos))) arr[i] = 0;
        else if (i < (n - numberOfTwos)) arr[i] = 1;
        else arr[i] = 2;
    }

    for(int i=0;i<n;i++) cout<<arr[i];

    return 0;
}