#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // long long fact(int n){
    //     long long factorial = 1;
    //     for (int i = 2; i <= n; i++)
    //     {
    //         factorial *= i;
    //     }
    //     return factorial;
    // }

    long long comb(int n, int r){
        int res = 1;
        for (int i = 0; i < r; i++)
        {
            res *= (n-i);
            res = res/(i+1);
        }
        return res;
    }

    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result(numRows);

        for (int i = 0; i < numRows; i++)
        {
            result[i].resize(i + 1);
            for (int j = 0; j <= i; j++)
            {
                result[i][j] = comb(i, j);
            }
        }

        return result;
    }
};

int main(){
    Solution S;
    int numRows;
    cin >> numRows;
    vector<vector<int>> answer;
    answer = S.generate(numRows);

    for (auto &row : answer)
    {
        for (auto val : row)
        {
            cout << val << ' ';
        }
        cout << '\n';
    }
    return 0;
}