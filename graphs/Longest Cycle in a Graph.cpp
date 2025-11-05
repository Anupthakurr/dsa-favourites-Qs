qs link -------> https://leetcode.com/problems/longest-cycle-in-a-graph/description/

class Solution {
    int dfs(int node, vector<int>& edges, vector<int>& vis, vector<int>& inStack, vector<int>& depth, int curDepth, int& ans) {
        vis[node] = 1;
        inStack[node] = 1;
        depth[node] = curDepth;

        int neigh = edges[node];
        if (neigh != -1) {
            if (!vis[neigh]) {
                dfs(neigh, edges, vis, inStack, depth, curDepth + 1, ans);
            } else if (inStack[neigh]) {
                // cycle detected
                ans = max(ans, curDepth - depth[neigh] + 1);
            }
        }

        inStack[node] = 0; // backtrack
        return ans;
    }

public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0), inStack(n, 0), depth(n, 0);
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, edges, vis, inStack, depth, 0, ans);
            }
        }
        return ans;
    }
};

