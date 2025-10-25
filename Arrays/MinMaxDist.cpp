#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     double minMaxDist(vector<int>& stations, int K) {
//         int n = stations.size();
//         if (n == 1) return 0.00;

//         auto cmp = [](pair<double,int> a, pair<double,int> b) {
//             return (a.first / a.second) < (b.first / b.second);
//         };

//         priority_queue<pair<double,int>, vector<pair<double,int>>, decltype(cmp)> pq(cmp);

//         for (int i = 0; i < n - 1; i++) {
//             pq.push({(double)(stations[i + 1] - stations[i]), 1});
//         }

//         while (K--) {
//             auto [gap, parts] = pq.top(); pq.pop();
//             pq.push({gap, parts + 1});
//         }

//         auto [gap, parts] = pq.top();
//         return gap / parts;
//     }
// };

// long double minimiseMaxDistance(vector<int> &arr, int k) {
//     int n = arr.size();
//     vector<int> howMany(n - 1, 0);
//     priority_queue<pair<long double, int>> pq;

//     // Step 1: Push initial differences between consecutive stations
//     for (int i = 0; i < n - 1; i++) {
//         pq.push({(long double)(arr[i + 1] - arr[i]), i});
//     }

//     // Step 2: Add gas stations one by one
//     for (int gasStations = 1; gasStations <= k; gasStations++) {
//         auto tp = pq.top(); pq.pop();
//         int secInd = tp.second;

//         howMany[secInd]++;  // one new gas station in this segment

//         long double iniDiff = arr[secInd + 1] - arr[secInd];
//         long double newSecLen = iniDiff / (long double)(howMany[secInd] + 1);

//         pq.push({newSecLen, secInd});
//     }

//     return pq.top().first;
// }


