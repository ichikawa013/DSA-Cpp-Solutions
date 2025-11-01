#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int cnt = 0;        // stack<char> st;(increases S.C. to O(n))
        string ans = "";

        for (char c : s)
        {
            if (c == '(')
            {
                if (cnt > 0)
                    ans += c;
                cnt++;
            }
            else
            {
                cnt--;
                if (cnt > 0)
                    ans += c;
            }
        }
        return ans;
    }
};