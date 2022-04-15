#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    
    int *arrA = new int(n); 
    int *arrB = new int(n); 

    for(int i=0;i<n;i++) cin>>arrA[i];
    for(int i=0;i<n;i++) cin>>arrB[i];

    set<int> s;
      
    for(int i=0;i<n;i++)s.insert(arrA[i]);
    for(int i=0;i<m;i++)s.insert(arrB[i]);

    //cout<<s.size();

    for (auto it = s.begin(); it != s.end(); ++it)
        cout << ' ' << *it;

    return 0;
}