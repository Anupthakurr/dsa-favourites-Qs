qs link -----> https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int mint = 0; // Count of edges to travel
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<bool> path;
    vector<bool> hasApple;

    bool dfs(int node) {
        visited[node] = true;
        bool foundApple = hasApple[node];
        for (auto neigh : adj[node]) {
            if (!visited[neigh]) {
                if (dfs(neigh)) {
                    foundApple = true;
                }
            }
        }
        path[node] = foundApple;
        return foundApple;
    }

    void bdfs(int node) {
        visited[node] = true;
        for (auto neigh : adj[node]) {
            if (!visited[neigh] && path[neigh]) {
                mint++;
                bdfs(neigh);
            }
        }
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasAppleInput) {
        // Step 1: Build adjacency list
        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        hasApple = hasAppleInput;
        visited.assign(n, false);
        path.assign(n, false);

        // Step 2: Mark nodes on the path to apples
        dfs(0);

        // Step 3: Count edges needed
        visited.assign(n, false);
        bdfs(0);

        return 2 * mint;
    }
};
