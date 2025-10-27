#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxIndex(vector<int>& row) {
        int maxIndex = 0;
        for (int i = 1; i < row.size(); i++) {
            if (row[i] > row[maxIndex]) {
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int top = 0, bottom = m - 1;

        while (top <= bottom) {
            int mid = top + (bottom - top) / 2;

            int maxCol = findMaxIndex(mat[mid]);

            int up = (mid > 0) ? mat[mid - 1][maxCol] : -1;
            int down = (mid < m - 1) ? mat[mid + 1][maxCol] : -1;

            if (mat[mid][maxCol] > up && mat[mid][maxCol] > down) {
                return {mid, maxCol};
            }
            else if (mat[mid][maxCol] < up) {
                bottom = mid - 1;
            }
            else {
                top = mid + 1;
            }
        }

        return {-1, -1};
    }
};
