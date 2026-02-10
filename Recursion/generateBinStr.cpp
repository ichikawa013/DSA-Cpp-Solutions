#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void generateString(string curr, int n, vector<string>& res) {
        if(curr.size() == n) {
            res.push_back(curr);
            return;
        }

        curr.push_back('0');
        generateString(curr, n, res);
        curr.pop_back();

        curr.push_back('1');
        generateString(curr, n, res);
        curr.pop_back();
    }

    vector<string> binstr(int n) {
        // code here
        vector<string> res;
        string opt = "01";
        generateString("", n, res);
        
        return res;
    }
};