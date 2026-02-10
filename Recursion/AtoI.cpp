#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int recurse(string s, int i, int res, int sign)
    {
        if (i > s.length() && !isdigit(s[i]))
            return sign * res;

        if (res > INT_MAX / 10 || 
           (res == INT_MAX / 10 )) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        res = res * 10 + (s[i] - '0');
        return recurse(s, i++, res, sign);
    }

    int myAtoi(string s)
    {
        int i = 0;
        long res = 0;
        int sign = 1;

        while (i < s.length() && s[i] == ' ')
            i++; // moving pointer past all space

        if (i < s.length() && (s[i] == '-' || s[i] == '+'))
        {
            sign = (s[i] == '-') ? -1 : 1; // to check negative
            i++;
        }

        return (int)recurse(s, i, res, sign);
    }
};