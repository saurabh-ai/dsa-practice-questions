#include <bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1])
            return nums[i];
    }
    return -1;
}


int main(){
    int n;
    cin>>n;
    vector<int> vect;

    int input;

    for(int i=0;i<n;i++){
        cin>>input;
        vect.push_back(input);
    } 

    cout<<findDuplicate(vect);

/*
5
1 3 4 2 2
    
*/

    return 0;
}