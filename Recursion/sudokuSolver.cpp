#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(int row, int col, char num, vector<vector<char>>& board) {
        int m = board.size();
        //column check
        for (int i = 0; i < m; i++)
            if (board[i][col] == num)
                return false;
            
        //row check
        for (int i = 0; i < m; i++)
            if (board[row][i] == num)
                return false;      
                
        //3x3 block check
        int blockRow = (row / 3) * 3;
        int blockCol = (col/ 3) * 3;

        for (int i = 0; i < 3; i++)
            for (int j = 0;j < 3; j++)
                if (board[blockRow + i][blockCol + j] == num)
                    return false;
        
        return true;
    }
    bool placeNumber(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (isSafe(i, j, num, board)) {
                            board[i][j] = num;
                            if(placeNumber(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>> &board) {
        if(board.size() != board[0].size())
            return;

        placeNumber(board);
    }
};