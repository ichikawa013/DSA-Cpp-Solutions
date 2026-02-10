#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> res;

    bool isSafe(int row, int col, int n, vector<string> &board) {
        // for colm
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q')
                return false;

        // for upper left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')

                return false;

        // for upper right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')

                return false;

        return true;
    }

    int placeQueens(int row, int n, vector<string> &board) {
        if (row == n)
            return 1;
        
        int cnt = 0;
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, n, board)) {
                board[row][col] = 'Q';
                cnt += placeQueens(row + 1, n, board);
                board[row][col] = '.';
            }
        }
        return cnt;
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        return placeQueens(0, n, board);
    }
};