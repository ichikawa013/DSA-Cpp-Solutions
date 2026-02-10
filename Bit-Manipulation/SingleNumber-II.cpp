#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int bit = 0; bit < 32; bit++){
            int cnt = 0;
            for(int num : nums)
                if(num & (1 << bit))
                    cnt++;

            if(cnt % 3 != 0)
                res |= (1 << bit);
        }

        return res;
    }
};