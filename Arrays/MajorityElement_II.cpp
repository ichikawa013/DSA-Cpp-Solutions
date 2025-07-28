#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // unordered_map<int, int> mp;
        // int n = nums.size();

        // for (auto it : nums) mp[it]++;

        // auto it = mp.begin();
        // vector<int> res;
        // while (it != mp.end())
        // {
        //     if(it->second > n/3)
        //         res.emplace_back(it->first);
        //     it++;
        // }

        // return res;

        int ele1 = -1, ele2 = -1;
        int count1 = 0, count2 = 0;
        vector<int> res;

        for (auto num : nums)
        {
            if (count1 == 0 && ele2 != num)
            {
                count1 = 1;
                ele1 = num;
            }
            else if (count2 == 0 && ele1 != num)
            {
                count2 = 1;
                ele2 = num;
            }
            else if (num == ele1)
                count1++;
            else if (num == ele2)
                count2++;
            else
            {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for (auto num : nums)
        {
            if (num == ele1)
                count1++;
            else if (num == ele2)
                count2++;
        }

        int n = nums.size();
        if (count1 > n/3)
            res.push_back(ele1);
        if (count2 > n/3)
            res.push_back(ele2);

        return res;
    }
};