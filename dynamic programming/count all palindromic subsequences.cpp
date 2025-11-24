qs link --->  https://www.geeksforgeeks.org/problems/count-palindromic-subsequences/1


//  my solution
class Solution {
  public:
    /*You are required to complete below method */
    long long int solve(int i, int j,string &s,vector<vector<int>> &dp){
        
        int mod = 1000000007;
        // base case 
        if(i>j){
            return 0;
        }
        if(i == j){
            return 1;
        }
         if(dp[i][j] != -1){
             return dp[i][j];
         }
       
        int take1 = 0;
        int take2 = 0;
        int take3 = 0;
        if(s[i] == s[j]){
            take1 = 1 + solve(i+1,j-1,s,dp);
            take2 = solve(i,j-1,s,dp);
            take3 = solve(i+1,j,s,dp)-solve(i+1,j-1,s,dp);
        }
        else{
         take2 = solve(i,j-1,s,dp);
         take3 =  solve(i+1,j,s,dp) - solve(i+1,j-1,s,dp);
         
        }
        
        return dp[i][j] =  take1 + take2 + take3;
        
    }
    
    long long int  countPS(string str) {
          
          int n=str.length();
          vector<vector<int>> dp(n,vector<int>(n,-1));
          return solve(0,n-1,str,dp);
    }
    
};

// solution from youtube pepcoding
  
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        const int MOD = 1e9 + 7;
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int g = 0; g < n; g++) {
            for (int i = 0, j = g; j < n; i++, j++) {
                if (g == 0) {
                    dp[i][j] = 1;
                } else if (g == 1) {
                    dp[i][j] = (s[i] == s[j]) ? 3 : 2;
                } else {
                    if (s[i] == s[j]) {
                        dp[i][j] = ( (dp[i][j - 1] + dp[i + 1][j]) % MOD + 1 ) % MOD;
                    } else {
                        dp[i][j] = ( ( (dp[i][j - 1] + dp[i + 1][j]) % MOD - dp[i + 1][j - 1] ) % MOD + MOD ) % MOD;
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};

