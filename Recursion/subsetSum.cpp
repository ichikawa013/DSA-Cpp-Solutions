#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void generateSubset(int index,int sum, vector<int>& arr, vector<int>& res) {
        if(index == arr.size()) {
            res.push_back(sum);
            return;
        }

        generateSubset(index, sum, arr, res);

        generateSubset(index + 1, sum + arr[index], arr, res);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> res;
        generateSubset(0, 0,  arr, res);
        
        return res;
    }
};