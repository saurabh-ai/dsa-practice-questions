#include <bits/stdc++.h>

using namespace std;

/*

Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.

6 5 8
1 5 10 20 40 80
6 7 20 80 100
3 4 15 20 30 70 80 120

O/P
20 80
*/

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            int i=0,j=0,k=0;
            vector<int> m;
            while(i<n1 && j<n2 && k<n3){
                if(A[i]==B[j] && B[j]== C[k]){
                    if(m.size() ==0)
                    m.push_back(A[i]);
                    else if(m.back()!=A[i])
                    m.push_back(A[i]);
                    i++;
                    j++;
                    k++;
             
                    
                }
                else
                if(A[i]<=B[j] && A[i]<=C[k])
                i++;
                else if(B[j]<=A[i] && B[j]<=C[k])
                j++;
                else 
                k++;
            }
            
             return m;
        }




int main(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
        int *A = new int(n1); 
        int *B = new int(n2); 
        int *C = new int(n3); 

        for(int i=0;i<n1;i++) cin>>A[i];
        for(int i=0;i<n2;i++) cin>>B[i];
        for(int i=0;i<n3;i++) cin>>C[i];

        vector<int> vect = commonElements(A,B,C,n1,n2,n3);
        
        for(int i = 0; i<vect.size();i++) cout<<vect[i]<<" ";

    return 0;
}