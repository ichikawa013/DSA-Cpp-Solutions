#include<bits/stdc++.h>
using namespace std;

//first solution using map
// class Solution {
// public:
//     vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
//         int row = grid.size();
//         int n = row * row; // number of elements in grid
//         int missing;
//         int repeated;
//         vector<int> result;

//         unordered_map<int, int> mp;
//         for (int i = 1; i <= n; i++) mp[i] = 0;
//         for (int i = 0; i < grid.size(); i++) {
//             for (int j = 0; j < grid[i].size(); j++) {
//                 mp[grid[i][j]]++;
//             }
//         }
//         for (int i = 1; i <= n; i++) {
//             if (mp[i] == 2)
//                 repeated = i;
//             else if (mp[i] == 0)
//                 missing = i;
//         }

//         result.insert(result.end(), {repeated, missing});

//         return result;
//     }
// };

//using vector for fast processing tc-n sc-n
// class Solution {
// public:
//     vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
//         int row = grid.size();
//         int n = row * row; // number of elements in grid
//         vector<int> freq(n+1,0);
//         vector<int> result(2,0);

//         for (int i = 0; i < grid.size(); i++) {
//             for (int j = 0; j < grid[i].size(); j++) {
//                 freq[grid[i][j]]++;
//             }
//         }
//         for (int i = 1; i <= n; i++) {
//             if (freq[i] == 2)
//                 result[0] = i;
//             else if (freq[i] == 0)
//                 result[1] = i;
//         }

//         return result;
//     }
// };


//optimal solution for sc-1 it uses the approach that we generally use for finding missing element 
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size() * grid.size();
        long long currentSum{0};
        long long actualSum = n*(n+1)/2;
        long long actualSumSquare = n*(n+1)*(2*n+1)/6;
        long long currentSumSquare{0};

        for(int i = 0;i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                currentSum += grid[i][j];
                currentSumSquare += grid[i][j]*grid[i][j];
            }
        }

        long long x, y;

        long long val1 = actualSum - currentSum;
        long long z = actualSumSquare - currentSumSquare;
        long long val2 = z / val1;

        x = (val1+val2)/2;
        y = x-val1;

        return {(int)y,(int)x};
    }
};