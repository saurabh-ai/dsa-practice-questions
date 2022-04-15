/* 

C++ program to rearrange positive and negative integers in alternate fashion while keeping
the order of positive and negative numbers. 

Negative first and positive later

https://www.youtube.com/watch?v=V_QB59AaeCk - Better

*/

#include <assert.h>
#include <iostream>
using namespace std;

// Utility function to right rotate all elements between
// [outofplace, cur]
void rightrotate(int arr[], int n, int outofplace, int cur)
{
	char tmp = arr[cur];
	for (int i = cur; i > outofplace; i--)
		arr[i] = arr[i - 1];
	arr[outofplace] = tmp;
}

void rearrange(int arr[], int n)
{
	int outofplace = -1;

	for (int index = 0; index < n; index++)
	{
		if (outofplace >= 0)
		{
			
			if (((arr[index] >= 0) && (arr[outofplace] < 0)) 
            
            || 
            
            ((arr[index] < 0) && (arr[outofplace] >= 0)))
			{
				rightrotate(arr, n, outofplace, index);

				// the new out-of-place entry is now 2 steps
				// ahead
				if (index - outofplace >= 2)
					outofplace = outofplace + 2;
				else
					outofplace = -1;
			}
		}

		// if no entry has been flagged out-of-place
		if (outofplace == -1) {
			// check if current entry is out-of-place
			if (((arr[index] >= 0) && (!(index & 0x01)))
				|| ((arr[index] < 0) && (index & 0x01))) { // -ve and odd, +ve and even
				outofplace = index;
			}
		}
	}
}



/*
int rightRotate(int arr[], int from, int to){
	int temp = arr[to];
	for(int i=to; i>from; i++) 
		arr[i] = arr[i-1];
	arr[from] = temp;
}

void rearrange(int arr[], int n){
	int wrongIndex = -1;
	for(int i = 0; i<n ; i++){
		if(wrongIndex != -1){
			if((arr[wrongIndex] >= 0 && arr[i] < 0) || (arr[wrongIndex] < 0 && arr[i] >= 0)){
				rightRotate(arr,wrongIndex,i);
				
				if(i-wrongIndex,i >= 2)
					wrongIndex += 2;
				else
					wrongIndex = -1;
				
			}else{
				if((arr[wrongIndex] < 0 && i%2 == 1) || (arr[i]>=0 && i%2 == 0))
				wrongIndex = -1;
			}
		
		}
		
	}
	

}*/
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	
	int arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, n);

	rearrange(arr, n);

	cout << "Rearranged array is \n";
	printArray(arr, n);

	return 0;
}
