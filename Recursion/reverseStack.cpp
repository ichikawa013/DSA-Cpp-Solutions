#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void insertSorted(stack<int> &st, int temp) {
        if(st.empty()) {
            st.push(temp);
            return;
        }

        int temp1 = st.top();
        st.pop();

        insertSorted(st, temp);
        st.push(temp1);
    }
    void reverseStack(stack<int> &st) {
        if(st.empty())
            return;

        int temp = st.top();
        st.pop();

        reverseStack(st);

        insertSorted(st, temp);
    }
};

