#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {  //we can add this as inline, if used repeteadly
        int open = 0, close = 0;    // stack<char> st;

        for(char c : s){
            // if(st.empty()) {
            //     stack.push(c);
            // }
            // else {
            //     if(st.top() == '(' && c == ')') st.pop();
            //     else st.push(c); 
            // }

            if(c == '(') open++;
            else {
                if(open > 0) open--;
                else close++;
            }
        }
         return open + close;  //return st.size();
    }
};