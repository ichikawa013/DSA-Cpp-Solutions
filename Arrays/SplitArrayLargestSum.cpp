#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int validSum(vector<int>& nums, int sum){
//         int count = 1, divSum = 0;
//         bool validation = 1;
//         for (auto num : nums)
//         {
//             if(divSum + num <= sum) divSum += num;
//             else{
//                 divSum = num;
//                 count++;
//             }
//         }
//         return validation;
//     }
//     int splitArray(vector<int>& nums, int k) {
//         int low = *max_element(nums.begin(), nums.end());
//         int high = accumulate(nums.begin(), nums.end(), 0);
//         int ans = -1;

//         while(low <= high) {
//             int divisionSum = low + (high - low)/2;

//             if(validSum(nums, divisionSum) == k){
//                 ans = divisionSum;
//                 low = divisionSum + 1;
//             } else high = divisionSum - 1;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    bool validSum(const vector<int>& nums, int sum, int k){
        int count = 1, divSum = 0;
        for (auto num : nums)
        {
            if(divSum + num <= sum) divSum += num;
            else{
                divSum = num;
                count++;
            }
        }
        // if(count <= k) return true;
        return (count <= k);
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MIN;

        while(low <= high) {
            int divisionSum = low + (high - low)/2;

            if(validSum(nums, divisionSum, k)){
                ans = divisionSum;
                high = divisionSum - 1;
            } else low = divisionSum + 1;
        }
        return ans;
    }
};