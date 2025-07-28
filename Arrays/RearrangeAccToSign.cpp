#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> positive;
        vector<int> negative;

        for (auto it : nums)
        {
            if (it > 0)
            {
                positive.emplace_back(it);
            }
            else
                negative.emplace_back(it);
        }

        int flag = 0,i = 0,j = 0;
        
        
        while (i < positive.size() || j < negative.size())
        {
            if(flag%2 == 0){
                nums[flag] = positive[i++];
            }
            if(flag%2 != 0) 
            {
                nums[flag] = negative[j++];
            }

            flag++;
        }
        
        while (flag < positive.size()){
            nums[flag++] = positive[flag]++;
        }

        while (flag < negative.size()){
            nums[flag++] = negative[flag++];
        }

        return nums;
    }
};