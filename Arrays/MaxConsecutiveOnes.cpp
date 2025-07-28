#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m=0,count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0){
                if(count != 0){
                    m = max(m,count);
                }
                count = 0;
            }
            else count++;
        }
        m = max(m, count);
        return m;
    }
};