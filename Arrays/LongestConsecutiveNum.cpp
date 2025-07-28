#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int lastnum = INT_MIN;
        int sequence = 0;
        int cnt = 0;
        int size = nums.size();

        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; i++)
        {
            if (nums[i] - 1 == lastnum)
            {
                cnt += 1;
                lastnum = nums[i];
            }
            else if (lastnum != nums[i])
            {
                cnt = 1;
                lastnum = nums[i];
            }
            sequence = max(sequence, cnt);
        }
        return sequence;
    }
};