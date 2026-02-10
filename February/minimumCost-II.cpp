#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumCost(vector<int> &nums, int k, int dist)
    {
        int n = nums.size();
        vector<int> indexes = {0};
        int ans = INT_MAX;
        int lastMinPrefix_index = 0;
        int i = 1;

        while (k--)
        {
            if (k == 1)
            {
                indexes.push_back(i);
                for (int j = i; j < nums.size(); j++)
                {
                    ans += nums[j];
                }
                break;
            }

            if (i - lastMinPrefix_index > dist)
            {
                indexes.push_back(i);
                lastMinPrefix_index = i;
            }
            i++;
        }

        int res = 0;
        for (int j = 0; j < indexes.size(); j++)
        {
            res += nums[j];
        }
        
    }
};
