#include<bits/stdc++.h>
using namespace std;

//Passed 33/35 cases, not entirely wrong but missed to separate them as there might be some integers that also give same result on XOR^num on line 16
// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         int XOR = 0;
//         vector<int> res;

//         for(int num :  nums) 
//             XOR ^= num;

//         for (int num : nums)
//         {
//             int temp = XOR ^ num;
//             if(find(nums.begin(), nums.end(), temp) != nums.end()) {
//                 res.push_back(temp);
//             }
//         }
        
//         return res;
//     }
// };

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long XOR = 0;
        vector<int> res;

        for(int num : nums) 
            XOR ^= num;

        long long diffBit = XOR & (-XOR);
        int a = 0, b = 0;

        for (int num : nums)
        {
            if(num & diffBit)
                a ^= num;
            else
                b ^= num;
        }
        
        return {a,b};
    }
};