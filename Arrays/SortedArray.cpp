#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int counter=0;
        int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            if(nums[i]>nums[i+1] && nums[i]!=nums[i+1])
                counter++;
        }
        if(nums[0]<nums[nums.size()-1]) counter++;
        return counter<=1;
    }
};