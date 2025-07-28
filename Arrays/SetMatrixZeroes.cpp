#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int numberofrow = matrix.size();
        int numberofcol = matrix[0].size();

        vector<int> row(matrix.size(),0);
        vector<int> col(matrix[0].size(),0);

        // int row[matrix.size()] = {0};
        // int col[matrix[0].size()] = {0};

        for (int i = 0; i < numberofrow; i++)
        {
            for (int j = 0; j < numberofcol; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i = 0; i < numberofrow; i++)
        {
            for (int j = 0; j < numberofcol; j++)
            {
                if (row[i] || col[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};