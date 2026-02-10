#include <bits/stdc++.h>
using namespace std;

//works but this one without memorization does too many calls
class Solution {
public:
    bool search(int index,string s, unordered_set<string>& dict) {
        if(index == s.size())
            return true;

        string temp;
        for(int i = index; i < s.size(); i++) {
            temp += s[i];
            if(dict.count(temp)) {
                if(search(i + 1, s, dict))
                    return true;
            }
        }

        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return search(0, s, dict);
    }
};

//we use memorization vector for keeping record of already initiated branch, 
//-1 -> not visited, 0 -> false(not found), 1 -> true(found)
class Solution {
public:
    bool search(int index,string s, unordered_set<string>& dict, vector<int>& record) {
        if(index == s.size())
            return true;

        if(record[index] != -1)
            return record[index];

        string temp;
        for(int i = index; i < s.size(); i++) {
            temp += s[i];
            if(dict.count(temp)) {
                if(search(i + 1, s, dict, record))
                    return record[index] = 1;
            }
        }

        return record[index] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> record(s.size(), -1);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return search(0, s, dict, record);
    }
};
