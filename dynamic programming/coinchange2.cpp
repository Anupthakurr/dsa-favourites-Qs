qs link -----> https://leetcode.com/problems/coin-change-ii/description/

class Solution {
     int f(int i,int n,int amount,vector<int>& coins,vector<vector<int>>& dp){
        //   base case
        if(amount == 0){
            return 1;
        }
        if(i>=n || amount < 0){
            return 0;
        }
         if(dp[i][amount] != -1){
            return dp[i][amount];
         }
           int ways =  f(i, n, amount - coins[i],coins,dp); // pick same coin 
                ways = ways + f(i+1, n, amount,coins,dp); 
           return  dp[i][amount] = ways;
     }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount + 1,-1));
        return f(0,n,amount,coins,dp);
    }
};
