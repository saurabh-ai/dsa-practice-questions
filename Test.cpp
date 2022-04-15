#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int *arr = new int(n); 

	for (int i = 2; i <= n; i++) {
		
		for (int j = 0; j < i; j++)
            cout<< i <<" "<<j<<" "<<" "<<i - j - 1<<endl;
	}

    return 0;
}