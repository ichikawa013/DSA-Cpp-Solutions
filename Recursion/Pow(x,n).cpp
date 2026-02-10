#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long solve(long long base, long long count) {
        if(count == 0)
            return 1;
        
        long long half = solve(base, count/2);
        half = (half*half) % MOD;

        if (count % 2)
            return (half * base) % MOD;
        
        return half;
    }
    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1)/2;
        long long oddCount = n / 2;

        long long res = (solve(5, evenCount) * solve(4, oddCount)) % MOD;

        return (int)res;
    }
};