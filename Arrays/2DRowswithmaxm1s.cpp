#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lowerBound(vector<int> arr, int n, int x)
    {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= x)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        int max_cnt = -1;
        int m = arr.size();
        int n = arr[0].size();
        int res;

        for (int i = 0; i < m; i++)
        {
            int cnt = n - lowerBound(arr[i], n, 1);
            if (cnt > max_cnt){
                max_cnt = cnt;
                res = i;
            }
            
        }
        return res;
    }
};