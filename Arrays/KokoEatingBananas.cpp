#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool timeLimit(vector<int>& piles, int h, int mid) {
        long long time = 0;
        for (auto num : piles) {
            time += ((num + mid - 1) / mid);
            if (time > h) return false;
        }

        return true;
    };
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (timeLimit(piles, h, mid)) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return ans;
    }
};