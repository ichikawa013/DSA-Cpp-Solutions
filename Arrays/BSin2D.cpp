#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
    int n = nums.size(); 
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low - (low - high )/ 2;
        if (nums[mid] == target) return true;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        
        for (int i = 0; i < m; i++)
        {
            if(search(matrix[i], target)){
                return true;
            }
        }
        return false;
    }
};