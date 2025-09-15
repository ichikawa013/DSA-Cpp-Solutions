#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int minDivisor;

        while(low <= high) {
            int count = 0;
            int mid = low + (high - low)/2;

            for(auto num : nums) {
                count += ceil(num/mid);
            }
            if(count > threshold) low = mid;
            else {
                int minDivisor = mid;
                high = mid - 1;
            }
        }
        return minDivisor;
    }
};