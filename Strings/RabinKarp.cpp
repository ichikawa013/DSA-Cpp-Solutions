#include<bits/stdc++.h>
using namespace std;

// Brute
// class Solution {
// public:
//     int repeatedStringMatch(string a, string b) {
//         string original = a;
//         int cnt = 1; 

//         while(a.length() < b.length()) {
//             a += original;
//             cnt++;
//         }

//         if (a.find(b) != string::npos) return cnt;
//         if ((a + original).find(b) != string::npos) return cnt + 1;

//         return -1;

//     }
// };

//Rabin-Karp Implementation
class Solution {
public:
    vector<int> rabin_karp(const string& pattern, const string& text) {
        int base = 31;
        int mod = 1e9 + 9;

        int P = pattern.size();
        int T = text.size();

        // Precompute powers of base
        vector<long long> base_pow(max(P, T));
        base_pow[0] = 1;
        for (int i = 1; i < base_pow.size(); i++)
            base_pow[i] = (base_pow[i - 1] * base) % mod;

        // Prefix hash of text
        vector<long long> h(T + 1, 0);
        for (int i = 0; i < T; i++)
            h[i + 1] = (h[i] + (text[i] - 'a' + 1) * base_pow[i]) % mod;

        // Hash of pattern
        long long h_pattern = 0;
        for (int i = 0; i < P; i++)
            h_pattern = (h_pattern + (pattern[i] - 'a' + 1) * base_pow[i]) % mod;

        // Find occurrences
        vector<int> occurrences;
        for (int i = 0; i + P - 1 < T; i++) {
            long long cur_h = (h[i + P] + mod - h[i]) % mod;
            if (cur_h == h_pattern * base_pow[i] % mod)
                occurrences.push_back(i);
        }
        return occurrences;
    }

    int repeatedStringMatch(string a, string b) {
        string org = a;
        int cnt = 1;

        while (a.size() < b.size()) {
            a += org;
            cnt++;
        }

        if (!rabin_karp(b, a).empty())
            return cnt;

        a += org;
        if (!rabin_karp(b, a).empty())
            return cnt + 1;

        return -1;
    }
};
