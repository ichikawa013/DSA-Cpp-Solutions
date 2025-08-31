#include<bits/stdc++.h>
using namespace std;

// this is optimal and easiest way
// class Solution {
// public:
//     bool canbeDivisor(const vector<int> nums, int threshold, int mid) {
//         int dividend = 0;
//         for (auto num : nums)
//         {
//             dividend += num / mid; 
//         }
//         return (dividend <= threshold) ? true : false;
//     }
//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int low = *min_element(nums.begin(), nums.end());
//         int high = *max_element(nums.begin(), nums.end());

//         if(threshold == nums.size()) return high;
//         while (low <= high)
//         {
//             int divisor = low + (high - low) / 2;

//             if(canbeDivisor(nums, threshold, divisor)){
//                 high = divisor; 
//             } else low = divisor + 1;
//         }
//         return high;
//     }
// };

//to reduce function overhead and reduce runtime and and memory we remove our canveDivisor()
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans;

        while (low <= high) {
            int divisor = low + (high - low) / 2;
            long long dividend = 0;
            bool ok = true;
            for (auto num : nums) {
                dividend += (num + divisor - 1) / divisor;
                if (dividend > threshold) {
                    ok = false;
                    break;
                }
            }
            if(ok){
                ans = divisor;
                high = divisor - 1; 
            } else low = divisor + 1;
        }
        return ans;
    }
};