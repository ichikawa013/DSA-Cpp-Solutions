#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int n = needle.size();
//         int h = haystack.size();

//         if(n == 0) return 0;
//         if(n > h) return -1;

//         char flag = needle[0];
//         for(int i{}; i <= h - n; i++) {
//             if(haystack[i] == flag){
//                 if(haystack.substr(i, n) == needle)
//                     return i;
//             }
//         }

//         return -1;
//     }
// };

//Using KMP
class Solution {
public:
    vector<int> buildLPS(const string& needle) {
        int n = needle.length();
        vector<int> lps(n, 0);
        lps[0] = 0;
        
        for(auto i = 1, len = 0; i < n;) {
            if(needle[len] == needle[i])
                lps[i++] = ++len;
            else if(len > 0) 
                len = lps[len - 1];
            else 
                lps[i++] = 0;
        }

        return lps;
    }

    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;

        vector<int> lps = buildLPS(needle);

        int i = 0, j = 0;
        while(i < haystack.length()) {
            if(haystack[i] == needle[j]) {
                i++, j++;
                if(j == needle.length()) return i - j;
            } else if (j > 0) {
                j = lps[j - 1]; 
            } else {
                i++;
            }
        }
        return -1;
    }
};