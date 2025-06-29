qs link ---->  https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/



class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>adj[n];
        int m=queries.size();
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        vector<int>ans(m);
        for(int i=0;i<m;i++){
            int start=queries[i][0];
            int end=queries[i][1];
            adj[start].push_back(end);
            vector<int>dist(n,1e7);
            dist[0]=0;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            pq.push({0,0});
            while(!pq.empty()){
                auto temp=pq.top();
                pq.pop();
                int node=temp.first;
                int d=temp.second;
                for(auto it:adj[node]){
                    if(dist[it]>d+1){
                        dist[it]=d+1;
                        pq.push({it,d+1});
                    }
                }
            }
            ans[i]=dist[n-1];
        } 
        return ans;
    }
};
