#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generateComb(int index, int target, vector<int> curr, vector<int> &candidates, vector<vector<int>> &res)
    {
        if (target == 0)
        {
            res.push_back(curr);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            if (candidates[i - 1] == candidates[i] && i > index)
                continue;

            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);
            generateComb(i + 1, target - candidates[i], curr, candidates, res);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        vector<vector<int>> res;
        generateComb(0, target, curr, candidates, res);

        return res;
    }
};