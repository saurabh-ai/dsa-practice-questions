/*
N meetings in one room 
Easy Accuracy: 43.1% Submissions: 69652 Points: 2
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of 
meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the 
meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
*/

// C++ program to find maximum number of meetings
#include <bits/stdc++.h>
using namespace std;

// Function for finding maximum meeting in one room
void maxMeetings(int s[], int f[], int n)
{
	pair<int, int> a[n + 1];
	int i;
	for (i = 0; i < n; i++) {
		a[i].first = f[i];
		a[i].second = i;
	}
	// Sorting of meeting according to their finish time.
	sort(a, a + n);

	// time_limit to check whether new
	// meeting can be conducted or not.
	int time_limit = a[0].first;

	// Vector for storing selected meeting.
	vector<int> m;

	// Initially select first meeting.
	m.push_back(a[0].second + 1);

	// Check for all meeting whether it
	// can be selected or not.
	for (i = 1; i < n; i++) {
		if (s[a[i].second] > time_limit) {
			// Push selected meeting to vector
			m.push_back(a[i].second + 1);

			// update time limit
			time_limit = a[i].first;
		}
	}

	// Print final selected meetings.
	for (int i = 0; i < m.size(); i++) {
		cout << m[i] << " ";
	}
}

// Driver code
int main()
{
	// Starting time
	int s[] = { 1, 3, 0, 5, 8, 5 };

	// Finish time
	int f[] = { 2, 4, 6, 7, 9, 9 };

	// Number of meetings.
	int n = sizeof(s) / sizeof(s[0]);

	// Function call
	maxMeetings(s, f, n);

	return 0;
}


