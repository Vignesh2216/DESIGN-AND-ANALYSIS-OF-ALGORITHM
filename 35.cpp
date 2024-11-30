// You are using GCC
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<int> &board, int row, int col, int N) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int row, int N, vector<int> &board, int &count) {
    if (row == N) {
        count++;
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row] = col;
            solveNQueens(row + 1, N, board, count);
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> board(N, -1);
    int count = 0;
    solveNQueens(0, N, board, count);
    cout << count << endl;
    return 0;
}