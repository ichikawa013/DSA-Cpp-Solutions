#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> buildLPS(const string& str) {
        int n = str.size();
        vector<int> lps(n);
        
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

    string longestPrefix(string s) {
        if(s.size() == 0) return "";

        vector<int> lps = buildLPS(s);
        return s.substr(0, lps.back());
    }
};