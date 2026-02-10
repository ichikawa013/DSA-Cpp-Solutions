#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;

    int checkSum(int index, int minEle,int maxEle,bool taken, int target, vector<int>& nums) {
        if(index == nums.size()) {
            if(taken && minEle + maxEle <= target) return 1;
            return 0;
        }

        int leave = checkSum(index + 1, minEle, maxEle, taken, target, nums);

        int take = 0;
        if(!taken) {
            take = checkSum(index + 1, nums[index], nums[index], true, target, nums);
        }
        else{
            int newMin = min(minEle, nums[index]);
            int newMax = max(maxEle, nums[index]);

            
            take = checkSum(index + 1, newMin, newMax, true, target, nums);
        }

        return (leave + take) % MOD;
    }

    int numSubseq(vector<int>& nums, int target) {
        return checkSum(0, 0, 0, false, target, nums);
    }
};