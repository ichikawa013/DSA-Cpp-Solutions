#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int a = llabs(dividend);
        int b = llabs(divisor);

        long long ans = 0;

        int sign = (dividend < 0 ^ divisor < 0) ? 1 : -1;

        while (a >= b)
        {
            int q = 1, temp = b;

            while ((temp << 1) <= a)
            {
                temp <<= 1;
                q <<= 1;
            }

            a -= temp;
            ans += q;
            
        }
        return ans*sign;
    }
};