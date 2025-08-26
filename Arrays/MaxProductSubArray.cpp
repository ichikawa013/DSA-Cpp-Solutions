#include<bits/stdc++.h>
using namespace std;

//self thought 168/190 testcases passed
// 

//improved Kadane's algo solution(upgradation of my one)
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int product = 1;
//         int maxm = 0;
//         int minm = 0;

//         if(n == 1) return nums[0];
        
//         for (int i = 0; i < n; i++)
//         {
//             product *= nums[i];
//             maxm = max(max(maxm, nums[i]), max(product, minm));
//             minm = min(min(maxm, nums[i]), min(product, minm));
//             if (product == 0)
//             {
//                 product = 1;
//             }
//         }
//         return maxm;
//     }
// };

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1;
        int n = nums.size();
        int suffix = 1;
        int maxm = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            maxm = max(maxm, max(prefix, suffix));
        }

        return maxm;
    }
};