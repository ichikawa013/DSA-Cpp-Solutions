#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0, depth = 0;
        for (const char& c : s) {
            if (c == '(') {
                if (++depth > maxDepth)
                    maxDepth = depth;
            }
            else if (c == ')'){
                depth--;
            }
        }

        return maxDepth;
    }
};