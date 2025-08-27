#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int floor = -1;
        int ceil = -1;
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == x){
                return {nums[mid],nums[mid]};
            } else if (nums[mid] < x){
                floor = nums[mid];
                low = mid + 1;
            } else {
                ceil = nums[mid];
                high = mid - 1;
            } 
        }

        return {floor, ceil};
    }
};