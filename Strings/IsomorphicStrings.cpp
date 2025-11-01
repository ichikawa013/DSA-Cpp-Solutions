#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for(int i = 0; i < t.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            if(mp1.count(c1) && mp1[c1] != c2) return false;
            if(mp2.count(c2) && mp2[c2] != c1) return false;

            mp1[c1] = c2;
            mp2[c2] = c1;
        }
        return true;
    }
};