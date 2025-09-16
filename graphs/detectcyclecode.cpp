// in undirected graph

bool dfs(int node, int parent, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;
    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            if (dfs(neigh, node, adj, visited)) return true;
        } 
        else if (neigh != parent) {
            return true; // found a back edge → cycle
        }
    }
    return false;
}

bool hasCycle(int n, vector<int> adj[]) {
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) return true;
        }
    }
    return false;
}

//  in directed graph
bool dfs(int node, vector<int> adj[], vector<bool>& visited, vector<bool>& inStack) {
    visited[node] = true;
    inStack[node] = true;

    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            if (dfs(neigh, adj, visited, inStack)) return true;
        } 
        else if (inStack[neigh]) {
            return true; // back edge → cycle
        }
    }

    inStack[node] = false; // backtrack
    return false;
}

bool hasCycle(int n, vector<int> adj[]) {
    vector<bool> visited(n, false), inStack(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, inStack)) return true;
        }
    }
    return false;
}

