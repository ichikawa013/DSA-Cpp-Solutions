#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generateComb(int index, int target, vector<int> curr, vector<int>& candidates, vector<vector<int>>& res){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        
        if(target < 0 || index == candidates.size())
            return;

        curr.push_back(candidates[index]);
        generateComb(index, target - candidates[index], curr, candidates, res);
        curr.pop_back();

        generateComb(index + 1, target, curr, candidates, res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        generateComb(0, target, {}, candidates, res);

        return res;
    }
};