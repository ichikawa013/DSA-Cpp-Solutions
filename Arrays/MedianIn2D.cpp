#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int n = mat.size(); //rows
        int m = mat[0].size(); //columns
        
        //number of elements required to be smaller than mid
        auto requiredSmallerNum = (n * m + 1) / 2;

        //global maxima and minima
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            low = min(low,mat[i][0]);
            high = max(high, mat[i][m-1]);
        }

        auto countLesserNums = [&](int mid) {
            int count = 0;

            for (int i = 0; i < n; i++)
            {
                count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            return count;
        };
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            
            if (countLesserNums(mid) < requiredSmallerNum)
            {
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};
