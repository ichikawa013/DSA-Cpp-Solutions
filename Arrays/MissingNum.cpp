#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num;
        int size = nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<size;i++){
            if(nums[i] != i){
                return i;
            }
        }

        return size;
    }
};