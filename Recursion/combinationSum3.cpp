#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generateComb(int index, int k, int n, vector<int>& nums, vector<int>& curr, vector<vector<int>>& res) {
        if(curr.size() == k && n == 0) {
            res.push_back(curr);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            if (nums[i] > n)
                break;

            curr.push_back(nums[i]);
            generateComb(i + 1, k, n - nums[i], nums, curr, res);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums= {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> curr;
        vector<vector<int>> res;

        generateComb(0, k, n, nums, curr, res);

        return res;
    }
};