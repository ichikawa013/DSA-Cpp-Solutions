#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int romanToInt(string s) {
//         int res = 0;
//         int i = 0;
//         while(i < s.length()) {
//             if(s[i] == 'I' && i + 1 < s.length()) {
//                 if(s[i + 1] == 'V') {res += 4; i += 2; continue;}
//                 else if(s[i + 1] == 'X') {res += 9; i += 2; continue;}
//             } 
//             else if(s[i] == 'X' && i + 1 < s.length()) {
//                 if(s[i+1] == 'L') {res += 40; i += 2; continue;}
//                 else if(s[i + 1] == 'C') {res += 90; i += 2; continue;}
//             }
//             else if(s[i] == 'C' && i + 1 < s.length()) {
//                 if(s[i + 1] == 'D') {res += 400; i += 2; continue;}
//                 else if(s[i + 1] == 'M') {res += 900; i += 2; continue;}
//             }
//             if(s[i] == 'I') {res += 1;}
//             else if(s[i] == 'V') {res += 5;}
//             else if(s[i] == 'X') {res += 10;}
//             else if(s[i] == 'L') {res += 50;}
//             else if(s[i] == 'C') {res += 100;}
//             else if(s[i] == 'D') {res += 500;}
//             else if(s[i] == 'M') {res += 1000;}
//             i++;
//         }
//         return res;
//     }
// };


// class Solution {
// public:
//     int romanToInt(string s) {
//         unordered_map<char, int> mp = {
//             {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
//         };

//         int res = 0;
//         for(int i = 0; i < s.length(); i++) {
//             if ( i + 1 < s.length() && mp[i] >= mp[i+1]) {
//                 res += mp[s[i]];
//             }
//             else {
//                 res -= mp[s[i]];
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int romanToInt(string s) {
        //using fixed size array for memory optimization
        int val[26] = {};
        val['I' - 'A'] = 1;
        val['V' - 'A'] = 5;
        val['X' - 'A'] = 10;
        val['L' - 'A'] = 50;
        val['C' - 'A'] = 100;
        val['D' - 'A'] = 500;
        val['M' - 'A'] = 1000;

        int res = 0;
        for(int i = 0; i < s.length(); i++){
            int curr = val[s[i] - 'A'];
            int next = (i + 1 < s.length()) ? val[s[i + 1] - 'A'] : 0;
            if(curr >= next) res += curr;
            else res -= curr;
        }

        return res;
    }
};