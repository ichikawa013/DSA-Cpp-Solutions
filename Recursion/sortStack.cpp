#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void insertSorted(stack<int> &st, int temp) {
        if(st.empty() || st.top() < temp) {
            st.push(temp);
            return;
        }

        int temp1 = st.top();
        st.pop();

        insertSorted(st, temp);
        st.push(temp1);
    }
    void sortStack(stack<int> &st) {
        if(st.empty())
            return;

        int temp = st.top();
        st.pop();

        sortStack(st);

        insertSorted(st, temp);
    }
};
