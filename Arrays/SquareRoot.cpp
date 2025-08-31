#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        int low = 1;
        int ans;
        int high = x;

        while(low <= high){
            long long mid = low + (high - low)/2;

            if((long long)(mid * mid) > x) high = mid - 1;
            else { ans = mid; low = mid + 1;}
        }  
        return ans;
    }
};

//I skipped nth root of m problem