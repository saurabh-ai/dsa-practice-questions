/*
Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.

Examples : 

Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3 
Output: 3 3 4 5 5 5 6
Explanation: 
Maximum of 1, 2, 3 is 3
Maximum of 2, 3, 1 is 3
Maximum of 3, 1, 4 is 4
Maximum of 1, 4, 5 is 5
Maximum of 4, 5, 2 is 5 
Maximum of 5, 2, 3 is 5
Maximum of 2, 3, 6 is 6

Input: arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}, K = 4 
Output: 10 10 10 15 15 90 90
Explanation:
Maximum of first 4 elements is 10, similarly for next 4 
elements (i.e from index 1 to 4) is 10, So the sequence 
generated is 10 10 10 15 15 90 90
*/

#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	int maximum;
};

// it is a modification in the way of implementation of queue using two stack

void insert(stack<node> &s2 , int val)
{
	//inserting the element in s2
	node other;
	other.data=val;
	
	if(s2.empty()) other.maximum=val;
	else
	{
		node front=s2.top();
		//updating maximum in that stack push it
		other.maximum=max(val,front.maximum);
	}
	s2.push(other);
	return;
}

void delete(stack<node> &s1 ,stack<node> &s2 )
{
	//if s1 is not empty directly pop
	//else we have to push all element from s2 and thatn pop from s1
	//while pushing from s2 to s1 update maximum variable in s1
	if(s1.size()) s1.pop();
	else
	{
		while(!s2.empty())
		{
			node val=s2.top();
			insert(s1,val.data);
			s2.pop();
		}
		s1.pop();
	}
}

int get_max(stack<node> &s1 ,stack<node> &s2 )
{
	// the maximum of both stack will be the maximum of overall window
	int ans=-1;
	if(s1.size()) ans=max(ans,s1.top().maximum);
	if(s2.size()) ans=max(ans,s2.top().maximum);
	return ans;
}


vector<int> slidingMaximum(int a[], int b,int n) {
	//s2 for push
	//s1 for pop
	vector<int>ans;
	stack<node>s1,s2;
	
	//shifting all value except the last one if first window
	for(int i=0;i<b-1;i++) insert(s2,a[i]);
	
	for(int i=0;i<=n-b;i++)
	{
		//removing the last element of previous window as window has shift by one
		if(i-1>=0) delete(s1,s2);
		
		//adding the new element to the window as the window is shift by one
		insert(s2,a[i+b-1]);
		
		ans.push_back(get_max(s1,s2));
	}
	return ans;
}

int main()
{
	int arr[] = { 8, 5, 10, 7, 9, 4, 15, 12, 90, 13 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 4;
	vector<int> ans=slidingMaximum(arr,k,n);
	for(auto x:ans) cout<<x<<" ";
	return 0;
}

