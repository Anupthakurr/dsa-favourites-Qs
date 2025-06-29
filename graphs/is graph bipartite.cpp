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


dfs --> 
    
class Solution {
    bool dfs(vector<vector<int>>& graph,int colour[],int node){
            for(auto it : graph[node]){
                if(colour[it] == -1){
                    colour[it] = !colour[node];
                   if(dfs(graph,colour,it)==false) return false;
                }
                else if(colour[it] == colour[node]){
                    return false;
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
                colour[i]=0;
                if(dfs(graph,colour,i) == false) return false;
            }
        } 
          return true;
            }
};


odd length and even length wali approach using bfs

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> level(n, -1); // -1 means unvisited

        for (int i = 0; i < n; i++) {
            if (level[i] == -1) {
                queue<int> q;
                q.push(i);
                level[i] = 0; // Start at level 0

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : graph[node]) {
                        if (level[neighbor] == -1) {
                            level[neighbor] = level[node] + 1;
                            q.push(neighbor);
                        } else if (level[neighbor]  == level[node] ) {
                            // Same level parity → odd-length cycle
                            return false;
                        }
                    }
                }
            }
        }
        return true; // No odd-length cycles
    }
};
