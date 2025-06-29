
qs link --> https://leetcode.com/problems/course-schedule/description/

cycle detection  using dfs
  
class Solution {
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathvis) {
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathvis)) return true;
            } else if (pathvis[it]) {
                return true; // Cycle detected
            }
        }

        pathvis[node] = 0; // Backtrack
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); // Create adjacency list
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]); // fix: edge from prereq to course
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathvis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathvis)) return false; // cycle found
            }
        }  

        return true; // No cycle
    }
};
