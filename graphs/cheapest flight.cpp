url ------------>    https://leetcode.com/problems/cheapest-flights-within-k-stops/description/?utm_source=chatgpt.com


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        dist[src][0] = 0;
        pq.push({0, src, 0}); // {cost, node, edgesUsed}

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int cost = curr[0];
            int node = curr[1];
            int edges = curr[2];

            if (cost > dist[node][edges])
                continue;

            if (edges == k + 1)
                continue;

            for (auto &it : adj[node]) {

                int adjNode = it.first;
                int wt = it.second;

                if (cost + wt < dist[adjNode][edges + 1]) {

                    dist[adjNode][edges + 1] = cost + wt;
                    pq.push({cost + wt, adjNode, edges + 1});
                }
            }
        }

        int ans = INT_MAX;

        for (int i = 0; i <= k + 1; i++) {
            ans = min(ans, dist[dst][i]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
