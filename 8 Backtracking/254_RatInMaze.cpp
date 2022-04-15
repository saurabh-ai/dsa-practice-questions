/*
Rat in a Maze Problem - I 
Medium Accuracy: 37.73% Submissions: 100k+ Points: 4
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). 
Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can 
move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and 
rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
*/

/* C++ program to solve Rat in
a Maze problem using backtracking */
#include <stdio.h>

// Maze size
#define N 4

bool solveMazeUtil(
	int maze[N][N], int x,
	int y, int sol[N][N]);

/* A utility function to print
solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d ", sol[i][j]);
		printf("\n");
	}
}

/* A utility function to check if x,
y is valid index for N*N maze */
bool isSafe(int maze[N][N], int x, int y)
{
	// if (x, y outside maze) return false
	if (
		x >= 0 && x < N && y >= 0
		&& y < N && maze[x][y] == 1)
		return true;

	return false;
}

/* This function solves the Maze problem
using Backtracking. It mainly uses
solveMazeUtil() to solve the problem.
It returns false if no path is possible,
otherwise return true and prints the path
in the form of 1s. Please note that there
may be more than one solutions, this
function prints one of the feasible
solutions.*/
bool solveMaze(int maze[N][N])
{
	int sol[N][N] = { { 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 } };

	if (solveMazeUtil(
			maze, 0, 0, sol)
		== false) {
		printf("Solution doesn't exist");
		return false;
	}

	printSolution(sol);
	return true;
}

/* A recursive utility function
to solve Maze problem */
bool solveMazeUtil(
	int maze[N][N], int x,
	int y, int sol[N][N])
{
	// if (x, y is goal) return true
	if (
		x == N - 1 && y == N - 1
		&& maze[x][y] == 1) {
		sol[x][y] = 1;
		return true;
	}

	// Check if maze[x][y] is valid
	if (isSafe(maze, x, y) == true) {
		// Check if the current block is already part of solution path.
		if (sol[x][y] == 1)
			return false;
	
		// mark x, y as part of solution path
		sol[x][y] = 1;

		/* Move forward in x direction */
		if (solveMazeUtil(
				maze, x + 1, y, sol)
			== true)
			return true;

		/* If moving in x direction
		doesn't give solution then
		Move down in y direction */
		if (solveMazeUtil(
				maze, x, y + 1, sol)
			== true)
			return true;
	
		/* If none of the above movements
		work then BACKTRACK: unmark
		x, y as part of solution path */
		sol[x][y] = 0;
		return false;
	}

	return false;
}

// driver program to test above function
int main()
{
	int maze[N][N] = { { 1, 0, 0, 0 },
					{ 1, 1, 0, 1 },
					{ 0, 1, 0, 0 },
					{ 1, 1, 1, 1 } };

	solveMaze(maze);
	return 0;
}

