#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(const char& c : s){
            mp[c]++;
        }

        // priority_queue<pair<int, char>> pq;
        
        // for(const auto& [ch, freq] : mp) {
        //     pq.push({freq, ch});
        // }

        vector<string> buckets(s.length() + 1);
        for(const auto& [ch, freq] : mp){
            buckets[freq].append(freq, ch);
        }

        string res = "";
        for(int i = s.length(); i > 0; i--){
            res += buckets[i];
        }
        return res;
    }
};