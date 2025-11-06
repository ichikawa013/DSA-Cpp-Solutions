#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        long res = 0;
        int sign = 1;

        while(i < s.length() && s[i] == ' ') i++; //moving pointer past all space

        if(i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1; //to check negative
            i++;
        }

        while(i < s.length() && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');
            i++;
            if(sign == 1 && res > INT_MAX) return INT_MAX;
            else if(sign == -1 && -res < INT_MIN) return INT_MIN;
        }
        return sign * res;
    }
};