#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void generateSub(int index, string s, vector<string> part,
                     vector<vector<string>>& res) {
        if (index == s.size()) {
            res.push_back(part);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                part.push_back(s.substr(index, i - index + 1));
                generateSub(i + 1, s, part, res);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> part;
        vector<vector<string>> res;

        generateSub(0, s, part, res);
        return res;
    }
};