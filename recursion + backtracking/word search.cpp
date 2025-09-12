qs link ------> https://leetcode.com/problems/word-search/description/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        int L = word.size();

        // directions: up, down, left, right
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    // queue: (row, col, index, visited)
                    queue<tuple<int,int,int,vector<vector<bool>>>> q;
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    visited[i][j] = true;
                    q.push({i, j, 0, visited});

                    while (!q.empty()) {
                        auto [x, y, idx, vis] = q.front();
                        q.pop();

                        if (idx == L - 1) return true; // full word matched

                        for (auto [dx, dy] : dirs) {
                            int nx = x + dx, ny = y + dy;
                            if (nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny] && board[nx][ny] == word[idx+1]) {
                                auto new_vis = vis;
                                new_vis[nx][ny] = true;
                                q.push({nx, ny, idx+1, new_vis});
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};
