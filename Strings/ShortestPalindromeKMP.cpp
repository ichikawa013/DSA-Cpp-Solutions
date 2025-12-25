#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> buildLPS(const string& str) {
        int n = str.length();
        vector<int> lps(n, 0);
        lps[0] = 0;
        
        for(auto i = 1, len = 0; i < n;) {
            if(str[len] == str[i])
                lps[i++] = ++len;
            else if(len > 0) 
                len = lps[len - 1];
            else 
                lps[i++] = 0;
        }

        return lps;
    }

    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        vector<int> lps = buildLPS(s);
        
        int i = 0, j = 0;
        while(i < rev.length()) {
            if(rev[i] == s[j]) {
                i++, j++;
            } else if (j > 0) {
                j = lps[j - 1]; 
            } else {
                i++;
            }
        }

        string prefix = s.substr(j);
        reverse(prefix.begin(), prefix.end());

        return prefix + s;
    }
};