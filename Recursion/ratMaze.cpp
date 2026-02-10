#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> ans;

    void findPath(int row,int col, string res, vector<vector<int>>& maze){
        if(row == maze.size() - 1 && col == maze[0].size() - 1) {
            ans.push_back(res);
            return;
        }

        if (row < 0 || col < 0 ||
            row >= maze.size() || col >= maze[0].size() ||
            maze[row][col] == 0)
        {
            return;
        }

        maze[row][col] = 0;
        findPath(row + 1, col, res + 'D', maze);
        findPath(row, col - 1, res + 'L', maze);
        findPath(row, col + 1, res + 'R', maze);
        findPath(row - 1, col, res + 'U', maze);
        maze[row][col] = 1;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        if (maze[0][0] == 0)
            return {};
            
        findPath(0, 0, "", maze);

        return ans;
    }
};