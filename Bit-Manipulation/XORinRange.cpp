#include<bits/stdc++.h>
using namespace std;
//solution based from https://codeforces.com/blog/entry/135951
class Solution {
  public:
    int xorTill(int n) {
        if(n < 0) return 0;
        else if(n % 4 == 0) return n;
        else if(n % 4 == 1) return 1;
        else if(n % 4 == 2) return n + 1;
        else if(n % 4 == 3) return 0;
    }

    int findXOR(int l, int r) {
        return xorTill(r) ^ xorTill(l - 1);
    }
};