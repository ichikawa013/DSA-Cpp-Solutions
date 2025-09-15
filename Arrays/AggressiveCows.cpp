#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool possible(vector<int> &stalls, int k,int mid){
        int lastStall = stalls[0];
        int count = 1;
        
        
        for (int i = 1; i < stalls.size(); i++)
        {
            if ((stalls[i] - lastStall) >= mid)
            {
                    lastStall = stalls[i];
                    count++;
                    if (count >= k) return true;
            }
                
        }
         return false;   
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls[stalls.size()-1] - stalls[0];
        int possibleDistance = 0;
        

        while(low <= high){
            int mid = low + (high - low)/2;

            if(possible(stalls, k , mid)) {
                low = mid + 1;
                possibleDistance = max(mid, possibleDistance);
                
            }else high = mid - 1;
            
            
        }
        return possibleDistance;
    }
};