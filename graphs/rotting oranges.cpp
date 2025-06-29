https://leetcode.com/problems/rotting-oranges/description/




class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int totalOranges = 0, rottedOranges = 0, days = 0;
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;

        // Count total oranges and enqueue initially rotten ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) totalOranges++;
                if (grid[i][j] == 2) q.push({i, j});
            }
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            int k = q.size();
            rottedOranges += k;

            while (k--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int newX = x + dx[i];
                    int newY = y + dy[i];

                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                    }
                }
            }
            // Increment day only if there are still oranges to rot
            if (!q.empty()) days++;
        }
        return totalOranges == rottedOranges ? days : -1;
    }
};
