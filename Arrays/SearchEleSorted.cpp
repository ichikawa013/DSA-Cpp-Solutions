#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = -1;
        int end = -1;
        int low = 0;
        int high = n - 1;
        //looking for start
        while (low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] > target) high = mid - 1;
            else if (nums[mid] == target){
                high = mid - 1;
                start = mid;
            } else low = mid + 1;
        }

        //looking for end
        low = 0;
        high = n - 1;
        while (low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] > target){
                high = mid - 1;
            } else if (nums[mid] == target) {
                end = mid;
                low = mid + 1;
            } else low = mid + 1;
        }

        return {start, end};
    }
};