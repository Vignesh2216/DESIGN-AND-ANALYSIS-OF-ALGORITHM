// You are using GCC
#include <iostream>
using namespace std;
// Constants for maximum maze dimensions
const int MAX_N = 10;
// Function to print the solution path
void printSolution(int solution[MAX_N][MAX_N], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a move is valid
bool isSafe(int maze[MAX_N][MAX_N], int x, int y, int N) {
    // Check if (x, y) is within maze bounds and is not blocked (0)
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// Recursive function to solve the Rat in a Maze problem
bool solveMazeUtil(int maze[MAX_N][MAX_N], int x, int y, int solution[MAX_N][MAX_N], int N) {
    // If the rat reaches the destination (N-1, N-1), return true
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        solution[x][y] = 1;
        return true;
    }

    // Check if (x, y) is a valid move
    if (isSafe(maze, x, y, N)) {
        // Mark (x, y) as part of the solution path
        solution[x][y] = 1;
        if (solveMazeUtil(maze, x + 1, y, solution, N))
            return true;
        if (solveMazeUtil(maze, x, y + 1, solution, N))
            return true;

        // If neither right nor down leads to a solution, backtrack
        solution[x][y] = 0;
        return false;
    }
    return false; // (x, y) is not a valid move
}

// Function to solve the Rat in a Maze problem
void solveMaze(int maze[MAX_N][MAX_N], int N) {
    int solution[MAX_N][MAX_N] = {0}; // Initialize the solution array with zeros
    if (solveMazeUtil(maze, 0, 0, solution, N))
        printSolution(solution, N);
    else
        cout << "Solution doesn't exist" << endl;
}
int main() {
    int N;
    cin >> N;
    int maze[MAX_N][MAX_N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    }
    solveMaze(maze, N);
    return 0;
}