#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFreq(const int freq[26]) {
        int mn = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0 && freq[i] < mn)
                mn = freq[i];
        }
        return (mn == INT_MAX) ? 0 : mn;
    }

    int maxFreq(const int freq[26]) {
        int mx = INT_MIN;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > mx)
                mx = freq[i];
        }
        return (mx == INT_MIN) ? 0 : mx;
    }

    int beautySum(string s) {
        int n = s.length();
        if (n == 1) return 0;

        int res = 0;
        for (int i = 0; i < n; i++) {
            int freq[26] = {0}; // we could also use array<int, 26> but it has more overhead
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int beauty = maxFreq(freq) - minFreq(freq);
                res += beauty;
            }
        }
        return res;
    }
};
