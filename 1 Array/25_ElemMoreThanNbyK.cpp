// C++ implementation
#include <bits/stdc++.h>
using namespace std;

// Function to find the number of array
// elements with frequency more than n/k times
void printElements(int arr[], int n, int k)
{

    // Calculating n/k
    int x = n / k;

    // Counting frequency of every
    // element using Counter
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]] += 1;

    // Traverse the map and print all
    // the elements with occurrence
    // more than n/k times
    for (int it = 0; it < mp.size(); it++) {
        if (mp[it] > x)
            cout << (it) << endl;
    }
}

// Driver code
int main()
{
    int arr[] = { 1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    printElements(arr, n, k);
}