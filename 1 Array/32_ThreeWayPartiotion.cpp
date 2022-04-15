// C++ program to implement three way partitioning 
// around a given range. 
#include<iostream> 
using namespace std; 

// Partitions arr[0..n-1] around [lowVal..highVal] 
void threeWayPartition(int arr[], int n, 
                int lowVal, int highVal) 
{ 
    // Initialize ext available positions for 
    // smaller (than range) and greater elements 
    int start = 0, end = n-1; 

    // Traverse elements from left 
    for (int i=0; i<=end;) 
    { 
        // If current element is smaller than 
        // range, put it on next available smaller 
        // position. 
        if (arr[i] < lowVal) 
        {
          //if i and start are same in that case we can't swap
          //swap only if i is greater than start
          if(i==start)
          {
            start++;
            i++;
          }
          else
            swap(arr[i++], arr[start++]); 
        }

        // If current element is greater than 
        // range, put it on next available greater 
        // position. 
        else if (arr[i] > highVal) 
            swap(arr[i], arr[end--]); 

        else
            i++; 
    } 
} 

// Driver code 
int main() 
{ 
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 
                98, 3, 1, 32}; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    threeWayPartition(arr, n, 10, 20); 

    cout << "Modified array \n"; 
    for (int i=0; i<n; i++) 
        cout << arr[i] << " "; 
} 