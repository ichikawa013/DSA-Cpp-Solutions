#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        int n = nums.size();
        
        int ans = INT_MAX;
        int minPrefix = nums[1]; 
        for (int j = 2; j < n; j++) {
            ans = min(ans, minPrefix + nums[j]);// we keep checking for minimum sum, so that when we change it geta assinged to the minPrefix
            minPrefix = min(minPrefix, nums[j]);
        }
        
        return nums[0] + ans;
    }
};
