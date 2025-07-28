#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        map<int, int> mpp;
        mpp[0] = 1;
        int presum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            presum += nums[i];
            int  rem = presum - k;
            count += mpp[rem];
            mpp[presum] += 1;
        }

        return count;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    int k = 3;

    int result = s.subarraySum(nums, k);
    cout << result;
}