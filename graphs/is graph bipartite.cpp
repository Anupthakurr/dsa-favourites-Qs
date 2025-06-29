qs link  ----> https://leetcode.com/problems/is-graph-bipartite/

graph travesal  bfs 

class Solution {
    bool check(vector<vector<int>>& graph,int colour[],int node){
         colour[node] = 0;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : graph[node]){
                if(colour[it] == -1){
                    colour[it] = !colour[node];
                    q.push(it);
                }
                else if(colour[it] == colour[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int colour[n];
        for(int i =0;i<n;i++){
           colour[i] = -1;
        }
        for(int i=0;i<n;i++){
            if(colour[i]==-1){
                if(check(graph,colour,i) == false) return false;
            }
        } 
          return true;
            }
};
