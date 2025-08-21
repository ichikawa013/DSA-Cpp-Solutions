#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp;
        unordered_map<int, int> mp;
        mp[0] = -1;


        int sum {0};
        int maxm{};

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if(mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
            else{
                int size =  i - mp[sum]; 
                maxm = max(size, maxm);
            }
        }
        return maxm;
        
    }
};