qs link -----> https://leetcode.com/problems/coin-change/description/

class Solution {
    int f(int i, int n, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (amount == 0) return 0;         // no coins needed
        if(amount <=0 || i>=n){
            return 1e9;
        }
        if (dp[i][amount] != -1) return dp[i][amount];

        int take = 1e9;
            take = 1 + f(i, n, coins, amount - coins[i], dp); // pick same coin (unlimited supply)
        int skip = f(i+1, n, coins, amount, dp);  // skip coin

        return dp[i][amount] = min(take, skip);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = f(0, n, coins, amount, dp);
        return (ans >= 1e9 ? -1 : ans);
    }
};
