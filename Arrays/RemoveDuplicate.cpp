#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size =nums.size();
        int j=1;
        for(int i=0;i<size-1;i++){
            if(nums[i]!=nums[i+1]){
                nums[j]=nums[i+1];
                j++;
            }
        }
        return j;
    }
};