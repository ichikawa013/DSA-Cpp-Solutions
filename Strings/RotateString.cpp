#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;
        if (s == goal)
            return true;

        // for (int i = 0; i < s.length(); i++) {
        //     string rotated  = s;
        //     reverse(rotated.begin(), rotated.end());
        //     reverse(rotated.begin(), rotated.begin() + i);
        //     reverse(rotated.begin() + i, rotated.end());

        //     if (rotated == goal)
        //         return true;
        // }

        if( (s+s).find(goal) != string::npos) return true;
        return false;
    }
};