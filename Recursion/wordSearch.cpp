#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool search(int index, int row, int colm, vector<vector<char>> &board, string& word)
    {
        if (index == word.size())
            return true;

        if (row < 0 || colm < 0 ||
            row >= board.size() || colm >= board[0].size() ||
            word[index] != board[row][colm])
        {
            return false;
        }

        char temp = board[row][colm];
        board[row][colm] = '#';

        bool found =
            search(index + 1, row + 1, colm, board, word) ||
            search(index + 1, row - 1, colm, board, word) ||
            search(index + 1, row, colm + 1, board, word) ||
            search(index + 1, row, colm - 1, board, word);

        board[row][colm] = temp;

        return found;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (search(0, i, j, board, word))
                    return true;
            }
        }
        return false;
    }
};