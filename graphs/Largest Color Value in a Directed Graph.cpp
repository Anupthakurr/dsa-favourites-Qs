qs link ---->  https://leetcode.com/problems/largest-color-value-in-a-directed-graph/


//  dp solution 

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);

        for (auto &e : edges)
            adj[e[0]].push_back(e[1]);

        vector<vector<int>> dp(n, vector<int>(26, 0));
        vector<int> ch(n, 0); // 0 = unvisited, 1 = visiting, 2 = done
        int check = 0;

        function<void(int)> dfs = [&](int u) {
            if (ch[u] == 1) {
                check = 1;     // cycle found
                return;
            }
            if (ch[u] == 2)
                return;

            ch[u] = 1;

            for (int v : adj[u]) {
                dfs(v);
                if (check) return;

                for (int c = 0; c < 26; c++)
                    dp[u][c] = max(dp[u][c], dp[v][c]);
            }

            int curr = colors[u] - 'a';
            dp[u][curr]++;

            ch[u] = 2;
        };

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (ch[i] == 0)
                dfs(i);

            if (check) return -1;
            ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
        }

        return ans;
    }
};


//    topo sort solution  

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), ans = 0;
        vector<vector<int>> cnt(n, vector<int>(26));
        vector<vector<int>> graph(n);

        vector<int> indegree(n);
        for (auto &v : edges) {
            graph[v[0]].push_back(v[1]);
            indegree[v[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int processed = 0;

        while (!q.empty()) {
            auto f = q.front();
            q.pop();

            processed++;
            cnt[f][colors[f] - 'a']++;

            // updating answer for this node
            ans = max(ans, cnt[f][colors[f] - 'a']);

            for (auto nbr : graph[f]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);

                // passing colors to the neighbor, updating with max
                for (int j = 0; j < 26; j++) {
                    cnt[nbr][j] = max(cnt[nbr][j], cnt[f][j]);
                }
            }
        }

        return processed == n ? ans : -1;
    }
};
