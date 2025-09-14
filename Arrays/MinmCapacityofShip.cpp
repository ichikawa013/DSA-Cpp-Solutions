#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool validWeight(const vector<int>& weights, int days, int mid) {
        int weightLimit = 0;
        int count = 1;
        for (auto weight : weights) {
            if (weightLimit + weight > mid) {
                count++;
                weightLimit = weight;
            } else {
                weightLimit += weight;
            }
            if (count > days)
                return false;
        }

        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;
        bool ok = true;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int weightLimit = 0;
            int count = 1;

            for (auto weight : weights) {
                if (weightLimit + weight > mid) {
                    count++;
                    weightLimit = weight;
                } else {
                    weightLimit += weight;
                }
                if (count > days)
                    ok = false;
            }

            if (validWeight(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};