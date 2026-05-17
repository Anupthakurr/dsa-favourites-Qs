#include <bits/stdc++.h>

using namespace std;



// ---------- DSU (Union-Find) ----------

class DSU {

public:

    vector<int> parent, rank;



    DSU(int n) {

        parent.resize(n);

        rank.resize(n, 0);

        for (int i = 0; i < n; i++)

            parent[i] = i;

    }



    int find(int x) {

        if (x == parent[x]) return x;

        return parent[x] = find(parent[x]); // path compression

    }



    void unite(int x, int y) {

        x = find(x);

        y = find(y);

        if (x != y) {

            if (rank[x] < rank[y]) 

                parent[x] = y;

            else if (rank[y] < rank[x])

                parent[y] = x;

            else {

                parent[y] = x;

                rank[x]++;

            }

        }

    }

};



// ---------- Kruskal Algorithm ----------

int kruskalMST(int n, vector<vector<int>> &edges) {

    // edges: {u, v, weight}

    

    // Step 1: Sort edges by weight

    sort(edges.begin(), edges.end(), [](auto &a, auto &b){

        return a[2] < b[2];

    });



    DSU dsu(n);

    int mstCost = 0;

    int edgesUsed = 0;



    // Step 2: Pick edges in sorted order

    for (auto &e : edges) {

        int u = e[0];

        int v = e[1];

        int w = e[2];



        // Step 3: If u and v belong to different sets → include

        if (dsu.find(u) != dsu.find(v)) {

            dsu.unite(u, v);

            mstCost += w;

            edgesUsed++;

        }



        if (edgesUsed == n - 1) break;

    }



    return mstCost;

}



// ---------- Example Usage ----------

int main() {

    int n = 4;

    vector<vector<int>> edges = {

        {0, 1, 10},

        {0, 2, 6},

        {0, 3, 5},

        {1, 3, 15},

        {2, 3, 4}

    };



    cout << "MST Cost = " << kruskalMST(n, edges) << endl;

    return 0;

}
