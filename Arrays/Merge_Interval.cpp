#include <bits/stdc++.h>
using namespace std;


//Brute
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         int n = intervals.size();
//         if(n == 0) return {};
    
//         //to ensure all the inner vectors are sorted because the question shows that it has sort tag
//         sort(intervals.begin(), intervals.end());

//         vector<int> present = intervals[0];
//         vector<vector<int>> res;
//         int flag;
//         for (int i = 0; i < n; i++)
//         {
//             if(intervals[i][0] <= present[1])
//                 present[1] = max(present[1],intervals[i][1]);
//             else if(intervals[i][0] == present[1] && intervals[i][1] == present[1]+1){
//                 present[1] = max(present[1],intervals[i][1]);
//                 flag = i;
//             }
//             else {
//                 res.push_back(present);
//                 present = intervals[i];
//                 flag = i;
//             }
//         }

//         if(flag < intervals.size()){
//             for (int i = flag; i < n; i++)
//             {
//                 res.push_back(intervals[i]);
//             }
//         }
        
//         return res;
//     }
// };

//Optimal
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        //to ensure all the inner vectors are sorted because the question shows that it has sort tag
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
        {
            if(res.empty() || intervals[i][1] > res.back()[1]){
                res.push_back(intervals[i]);
            }
            else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
    
        return res;
    }
};