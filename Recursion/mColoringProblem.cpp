#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isColorAvailable(int node, int color, vector<int>& colors, vector<vector<int>>& adj, vector<vector<int>> &edges) {
        for (int neighbour : adj[node])
        {
            if(colors[neighbour] == color) return false;
            return true;
        }
        
    }
    bool colorNodes(int node, int v, vector<int>& colors, vector<vector<int>>& adj, vector<vector<int>> &edges, int m) {
        if(node == v)
            return true;

        for (int color = 0; color < m; color++)
        {
            if(isColorAvailable(node, color, colors, adj,  edges)) {
                colors[node] = color;
                colorNodes(node + 1, v, colors, adj,  edges, m);
                colors[node] = 0;
            }
        }

        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<int>> adj(v);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }

        vector<int> colors(v, 0);
        return colorNodes(0, v, colors, adj, edges, m);
    }
};