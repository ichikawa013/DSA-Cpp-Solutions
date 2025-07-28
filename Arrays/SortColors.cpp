#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> Map;

        for (int num : nums)
        {
            Map[num]++;
        }

        int index = 0; 
        for (auto it = Map.begin(); it != Map.end(); ++it)
        {
            for (int i = 0; i < it->second; ++i)
            {
                nums[index++] = it->first;
            }
        }

        for (int num : nums)
        {
            cout << num << " ";
        }
        cout << endl;
    }
};