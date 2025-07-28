#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int n = nums.size()/2;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                count = 1;
                ele = nums[i];
            }
            else if (nums[i] == ele)
                count++;

            else
                count--; 
        }
        int count1 = 0;
        for (int i = 0; i < nums.size(); i++){
            if(nums[i] == ele) count1++;
        }
        if (count1 > n) return ele;
        return -1;
    }
};