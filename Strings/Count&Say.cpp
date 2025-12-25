#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string generateSeq(const string& s) {
        int cnt = 1;
        char lastNum = s[0];
        string res = "";
        res.reserve(s.size() * 2);
        int n = s.length();

        for(int i = 1; i < n; i++) {
            if (s[i] == lastNum) cnt++;
            else{
                res += to_string(cnt);
                res.push_back(lastNum);
                cnt = 1, lastNum = s[i]; 
            }
        }
        res += to_string(cnt);
        res.push_back(lastNum);

        return res;
    }
    string countAndSay(int n) {
        string res = "1";
        
        for(int i = 2; i <= n; i++){
            string next = generateSeq(res);
            res.swap(next);
        }
        return res;
    }
};