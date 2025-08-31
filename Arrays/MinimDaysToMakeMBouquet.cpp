#include<bits/stdc++.h>
using namespace std;

// Brute force solution
// class Solution {
// public:
//     int minDays(vector<int>& bloomDay, int m, int k) {
//         int low = *min_element(bloomDay.begin(), bloomDay.end());
//         int high = *max_element(bloomDay.begin(), bloomDay.end());
//         int count{0};
//         int bouquet{0};

//         if ((long long)m * k > bloomDay.size())
//             return -1;
//         for (int day = low; day <= high; day++) {
//             for (int j = 0; j < bloomDay.size(); j++) {
//                 if (bloomDay[j] <= day) {
//                     count++;
//                     if (count == k) {
//                         bouquet++;
//                         count = 0;
//                     }
//                 } else {
//                     count = 0;
//                 }
//             }
//             if (bouquet >= m)
//                 return day;
//             bouquet = 0;
//             count = 0;
//         }

//         return -1;
//     }
// };

//Optimal
class Solution {
public:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int count{0};
        int bouquet{0};
            for (int j = 0; j < bloomDay.size(); j++) {
                if (bloomDay[j] <= day) {
                    count++;
                    if (count == k) {
                        bouquet++;
                        count = 0;
                    }
                } else {
                    count = 0;
                }
            }
            if (bouquet >= m)
                return true;

            return false;
    };
        
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans;
        if ((long long)m * k > bloomDay.size())
            return -1;

        while(low<=high) {
            int day = low + (high - low)/2;

            if(canMakeBouquets(bloomDay, m, k, day)){
                high = day - 1;
                ans = high;
            } else {
                low = day + 1;
            }
            return high;
        }

        return -1;
    };
};