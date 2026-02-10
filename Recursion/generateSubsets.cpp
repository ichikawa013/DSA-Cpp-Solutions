#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generateSubsets(int i,vector<int>& nums, vector<vector<int>>& res, vector<int> curr) {
        if(i == nums.size()) {
            res.push_back(curr);
            return;
        }
        
        generateSubsets(i + 1, nums, res, curr);

        curr.push_back(nums[i]);
        generateSubsets(i + 1, nums, res, curr);
        curr.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        generateSubsets(0, nums, res, curr);

        return res;
    }
};