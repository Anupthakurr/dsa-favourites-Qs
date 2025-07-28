qs link --->  https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/

class Solution {
    long long f(int i, int j, int k, vector<vector<int>>& coins, vector<vector<vector<long long>>>& dp) {
         if (i == 0 && j == 0) {
            if (coins[i][j] >= 0) return coins[i][j]; // Gain the coins
            return (k > 0 ? 0 : coins[i][j]); // Neutralize if k > 0
        }
        if (i < 0 || j < 0) return INT_MIN;

        // Check if the result is already computed
        if (dp[i][j][k] != INT_MIN) return dp[i][j][k];

        long long up = 0, left = 0;

        if (coins[i][j] >= 0) {
            // If the cell has positive coins
            up = coins[i][j] + f(i - 1, j, k, coins, dp);
            left = coins[i][j] + f(i, j - 1, k, coins, dp);
        } else {
            // If the cell has a robber (negative coins)
            if (k > 0) {
                // Neutralize the robber
                up = f(i - 1, j, k - 1, coins, dp);
                left = f(i, j - 1, k - 1, coins, dp);

                // dontup = coins[i][j] +  f(i - 1, j, k, coins, dp);
                // dontleft = coins[i][j] + f(i, j - 1, k, coins, dp);

                up =  max(up,coins[i][j] +  f(i - 1, j, k, coins, dp));
                left = max(left,coins[i][j] + f(i, j - 1, k, coins, dp));
            }
            else{
            // Do not neutralize the robber
            up =    coins[i][j] +  f(i - 1, j, k, coins, dp);
            left =  coins[i][j] + f(i, j - 1, k, coins, dp);
            }
        }

        // Store the result in dp and return
        return dp[i][j][k] = max(up, left);
    }

public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();    // Number of rows
        int m = coins[0].size(); // Number of columns
        int k = 2;               // Number of neutralizations available

        // 3D DP table: dp[i][j][k] -> max coins at (i, j) with k neutralizations remaining
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(m, vector<long long>(k + 1, INT_MIN)));

        // Start from the bottom-right corner
        return f(n - 1, m - 1, k, coins, dp);
    }
};
