#include <bits/stdc++.h>

/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

https://www.youtube.com/watch?v=LuLCLgMElus

3
1 1 5

OP - 1 5 1

*/

using namespace std;

void nextPermutation(vector<int>& nums){
	int n = nums.size(),k,l;
	for(k=n-2;k>=0;k--){
		if(nums[k] < nums[k+1]){
			break;
		}	
	}
	if(k<0){
		reverse(nums.begin(), nums.end());
	}else{
		for(l=n-1 ; l>k ; l--){
			if(nums[l] > nums[k]){
				break;
			}
		}
		swap(nums[k],nums[l]);
		reverse(nums.begin()+k+1, nums.end());
	}

}



int main(){
    int n,input;
    cin>>n;
    //int *arr = new int(n);
    vector<int> arr; 

    for(int i=0;i<n;i++){
        cin>>input;
        arr.push_back(input);
    } 
    

    nextPermutation(arr);
    
    for(int i=0;i<n;i++) cout<<arr[i];

    return 0;
}