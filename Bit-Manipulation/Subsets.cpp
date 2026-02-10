#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        for (int subsetMask = 0; subsetMask < (1 << n); subsetMask++) {
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                if (subsetMask & (1 << i)) {
                    temp.push_back(nums[i]);
                } 
            }
            res.push_back(temp);
        }
        return res;
    }
};