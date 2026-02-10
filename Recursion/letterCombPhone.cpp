#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string curr;
        vector<string> res;
        unordered_map<char, string> mp= {
            {'3' , "def"},
            {'4' , "ghi"},
            {'5' , "jkl"},
            {'2' , "abc"},
            {'6' , "mno"},
            {'7' , "pqrs"},
            {'8' , "tuv"},
            {'9' , "wxyz"}
        };

        generateSub(0, curr, digits, res, mp);

        return res;
    }

    static void generateSub(int index, string curr, string digits, vector<string>& res, unordered_map<char, string>& mp) {
        if(curr.size() == digits.size()) {
            res.push_back(curr);
            return;
        }

        string str = mp.at(digits[index]);

        for (char ch : str)
        {
            curr.push_back(ch);
            generateSub(index + 1, curr, digits, res, mp);
            curr.pop_back();
        }
        
    }
};