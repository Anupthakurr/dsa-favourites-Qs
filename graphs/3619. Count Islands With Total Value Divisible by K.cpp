qs link---->  https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/


class Solution {
     int n,m;
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int dfs(vector<vector<int>>& grid,int i,int j){
        long long sum = grid[i][j];
         grid[i][j] = 0;
         for(auto &d : dirs){
          int nexti = i + d[0];
          int nextj = j + d[1];

        if(nexti>=0 && nextj>=0 && nexti<n && nextj<m && grid[nexti][nextj] != 0){
            sum += dfs(grid,nexti,nextj);
            grid[nexti][nextj] = 0;
        }
        }
        return sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
       

        n = grid.size();
        m = grid[0].size();
        int count = 0;
        for(int i= 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] > 0){
                    int total = dfs(grid,i,j);
                    if(total % k == 0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
