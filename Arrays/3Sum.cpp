#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n-1; i++)
        {
            if ( i > 0 && nums[i] == nums[i - 1]) continue;
            

            int k = i+1, j = n - 1;
            while (k<j)
            {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum < 0)
                {
                    k++;
                }
                else if (sum > 0)
                {
                    j--;
                }
                else{
                    result.push_back({nums[i],nums[k],nums[j]});
                    k++;
                    j--;
                    while (k<j && nums[k]==nums[k-1]) k++;
                    while (k<j && nums[j]==nums[j-1]) j--;
                }
            }
        }

        return result;
    }
};

int main(){
    Solution S;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> answer;
    answer = S.threeSum(nums);

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