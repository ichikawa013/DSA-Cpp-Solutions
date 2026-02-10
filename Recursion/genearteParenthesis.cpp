#include <bits/stdc++.h>
using namespace std;
//brute
// class Solution {
// public:
//     bool isValid(string s) {
//         int balance = 0;
//         for (char c : s) {
//             if (c == '(')
//                 balance++;
//             else
//                 balance--;
//             if (balance < 0)
//                 return false;
//         }
//         return balance == 0;
//     }

//     void generateAll(string curr, int n, vector<string>& res) {
//         if (curr.length() == 2 * n) {
//             if (isValid(curr))
//                 res.push_back(curr);
//             return;
//         }
//         generateAll(curr + '(', n, res);
//         generateAll(curr + ')', n, res);
//     }

//     vector<string> generateParenthesis(int n) {
//         vector<string> res;
//         generateAll("", n, res);
//         return res;
//     }
// };

//optimal with less recursive calls using neg and pos that replave the isValid function
class Solution {
public:
    void generateAll(string curr,int pos,int neg, int n, vector<string>& res) {
        if (curr.length() == 2 * n) {
            res.push_back(curr);
            return;
        }
        if(pos > n)
            generateAll(curr + '(', pos + 1, neg, n, res);

        if(neg < pos)
            generateAll(curr + ')', pos, neg + 1, n, res);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateAll("", 0, 0, n, res);
        return res;
    }
};