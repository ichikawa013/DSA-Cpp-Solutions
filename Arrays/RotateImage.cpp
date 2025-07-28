#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void transposeSquareMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void swapRow(vector<int> &rowEle){
        reverse(rowEle.begin(), rowEle.end());
    }

    void print(vector<vector<int>> &matrix){
        for (auto &row : matrix)
        {
            for (auto val : row)
            {
                cout << val << " ";
            }
            cout << '\n';
        }
        
    }

    void rotate(vector<vector<int>> &matrix)
    {
        transposeSquareMatrix(matrix);

        int row = matrix.size();
        int col = matrix[0].size();

        for (auto &row : matrix)
        {
            swapRow(row);
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    cout << "Original Matrix:\n";
    Solution obj;
    obj.print(matrix);

    obj.rotate(matrix);

    cout << "\nRotated Matrix (90 degrees clockwise):\n";
    obj.print(matrix);

    return 0;
}