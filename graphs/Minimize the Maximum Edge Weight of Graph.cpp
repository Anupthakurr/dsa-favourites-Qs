qs link ---> https://leetcode.com/problems/minimize-the-maximum-edge-weight-of-graph/


graph + binary search


  class Solution {
private:
     void dfs(int node,vector<vector<pair<int,int>>>&adj,int mid,vector<bool>&vis){
         vis[node] = true;
        for(auto adjnode : adj[node]){
            if(adjnode.second <= mid && vis[adjnode.first] != true){
                dfs(adjnode.first,adj,mid,vis);
            }
        }
     } 
private:
     bool check( int n,vector<vector<pair<int,int>>>adj,int mid){
        vector<bool>vis(n,false);
         dfs(0,adj, mid,vis);
         for(int i=0;i<n;i++){
            if(vis[i] == false){
                return false;
            }
         }   
         return true;
     }
     
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>>adj(n);
        int maxi = 0;
        for(auto it : edges){
            adj[it[1]].push_back({it[0],it[2]});
            maxi = max(maxi,it[2]);
        }
        int result = INT_MAX;
        int left = 0,right = maxi;
        while(left<=right){
        int mid = left + (right - left)/2;
         if(check(n,adj,mid)){
           result = mid;
           right = mid-1;
         }
         else{
            left = mid + 1;
         }
        }
        return result==INT_MAX?-1:result;
    }
};
