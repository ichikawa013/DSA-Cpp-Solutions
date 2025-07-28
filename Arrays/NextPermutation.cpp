#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int flag = -1;
        int size = nums.size();

        for (int i = size - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                flag = i;
                break;
            }
        }

        if (flag == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        
        else
        {
            for (int i = size - 1; i > flag; i--)
            {
                if (nums[flag] < nums[i])
                {
                    swap(nums[i], nums[flag]);
                    break;
                }
            }
            reverse(nums.begin()+1+flag, nums.end());
        }

        for (int it : nums)
        {
            cout << it << " ";
        }
        
    }
};