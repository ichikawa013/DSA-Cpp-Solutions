#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxm = nums[0];

        for(auto it : nums){
            sum += it;
            maxm = max(sum, maxm);
            if (sum < 0) sum = 0;
        }
        return maxm;
    }
};
