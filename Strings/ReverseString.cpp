#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     string trim(const string &s)
//     {
//         string result = s;
//         result.erase(result.begin(),
//                      find_if(result.begin(), result.end(),
//                                   [](unsigned char ch)
//                                   { return !isspace(ch); }));
//         result.erase(find_if(result.rbegin(), result.rend(),
//                                   [](unsigned char ch)
//                                   { return !isspace(ch); })
//                          .base(),
//                      result.end());
//         return result;
//     }
//     string reverseWords(string s)
//     {
//         string ns = trim(s);
//         int i = 0, j = ns.length();
//         while (i <= j)
//         {
//             swap(ns[i],ns[j]);
//             i++;
//             j--;
//         }
//         return ns;
//     }
// };/

//S.C. - O(n)
// class Solution {
// public:
//     string reverseWords(string s) {
//         stack<string> st;
//         string ans = "";
//         string temp = "";

//         for (char c : s)
//         {
//             if(c == ' '){
//                 if(!temp.empty())
//                     st.push(temp);
//                 temp = "";
//             }
//             else temp += c;
//         }
//         if(!temp.empty())
//             st.push(temp);
//         while (!st.empty())
//         {
//             ans = st.top();
//             if(!st.empty()) ans += ' ';
//             st.pop();
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";

        for (char c : s)
        {
            if(c == ' '){
                if(!temp.empty()) 
                {
                    ans = temp + " " + ans;
                }
                temp = "";
            }
            else temp += c;
        }
        if(!temp.empty()) ans = temp + ans;
        
        return ans;
    }
};

int main(){
    Solution s;
    string st= "  hello world  ";
    cout << s.reverseWords(st);
    return 0;
}