#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        int minLength = strs[0].length();
        for(string s : strs){
            minLength = min(minLength, (int)s.length());
        }

        string prefix = "";

        for (int i = 0; i < minLength; i++)
        {
            for (string s : strs)
            {
                if(s[i] != strs[0][i]) return prefix;
            }
            prefix += strs[0][i];
            
        }
        return prefix;
    }
};