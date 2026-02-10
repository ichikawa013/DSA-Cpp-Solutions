#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> res;

    void findOperators(string num, int target) {
        if (val == target) {
            if ()
            res.push_back(exp);
            return;
        }

        
    }

    vector<string> addOperators(string num, int target) {
        
        findOperators(0, num, target);
        return res;
    }
};

int main() {
    Solution s;
    string num = "123"; int target = 6;

    vector<string> exp = s.addOperators(num, target);

    for (string str : exp)
        cout << str;

    return 0;
}