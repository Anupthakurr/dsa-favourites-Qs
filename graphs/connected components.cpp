url ---------->>>>>    https://leetcode.com/problems/similar-string-groups/


class Solution {
public:
    bool similar(string &a, string &b) {
        int diff = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                diff++;
        }

        return diff == 0 || diff == 2;
    }

    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
        vis[node] = 1;

        for (int neigh : adj[node]) {
            if (!vis[neigh])
                dfs(neigh, adj, vis);
        }
    }

    int numSimilarGroups(vector<string>& strs) {

        int n = strs.size();

        vector<vector<int>> adj(n);

        // Build graph
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (similar(strs[i], strs[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);

        int groups = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                groups++;
                dfs(i, adj, vis);
            }
        }

        return groups;
    }
};
