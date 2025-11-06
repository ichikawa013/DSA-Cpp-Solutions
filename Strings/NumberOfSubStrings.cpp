#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        // vector<int> pos(3, -1);
        int a = -1, b = -1, c = -1;

        for (int i = 0; i < s.length(); i++)
        {
            // pos[s[i] - 'a'] = i;
            // if(pos['a' - 'a'] > -1 && pos['b' - 'a'] > -1 && pos['c' - 'a'] > -1)
            //     cnt += *min_element(pos.begin(), pos.end()) + 1;
            char ch = s[i];
            if(ch == 'a') a = i;
            else if(ch == 'b') b = i;
            else if(ch == 'c') c = i;

            if(a != -1 && b != -1 && c != -1) {
                int m = (a < b ? a : b);
                m = (m < c ? m : c);
                cnt += m + 1;
            }
            
        }
        return cnt;
    }
};