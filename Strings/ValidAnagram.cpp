#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        // unordered_map<char, int> mpS;
        // for(const char& c : s) mpS[c]++;

        // unordered_map<char, int> mpT;
        // for(const char& c : t) mpT[c]++;

        // for(const auto& [key, value] : mpS){
        //     if(mpT.find(key) == mpT.end() || mpT[key] != value)
        //         return false; 
        // }

        array<int, 26> contains {0};                //we could have used 
        for(int i = 0; i < s.length(); i++){        //vector<int> contains(26, 0); but it would take more memory
            contains[s[i] - 'a']++;
            contains[t[i] - 'a']--;
        }

        for(const auto& ele : contains){
            if(ele != 0) return false;
        }

        return true;
    }
};