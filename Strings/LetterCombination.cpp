#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void backtrack(unordered_map<char, string> mp,int index, vector<string> res, srting comb) {
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> res;
        string comb;

        backtrack(digits, 0, res, comb);
        return res;
    }
};