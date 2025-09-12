qs link ----------> https://leetcode.com/problems/longest-palindromic-subsequence-after-at-most-k-operations/description/

class Solution {
    int f(int i,int j,int k,string &s,vector<vector<vector<int>>> &dp){
        if(i>j){
            return 0;
            }
        if(i == j){
            return 1;
        }
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        if(s[i] == s[j] ){
            return  dp[i][j][k] = 2 +  f(i+1,j-1,k,s,dp);
        }
        else{
        int minop;
         minop = min(abs(s[i] - s[j]),(abs(s[j] - 'z') + 1 + abs('a' - s[i])));
         minop = min(minop,min(abs(s[i] - s[j]),(abs(s[i] - 'z') + 1 + abs('a' - s[j]))));
          if(minop <=  k){
          return dp[i][j][k] =  max(2 + f(i+1,j-1,k-minop,s,dp),max(f(i+1,j,k,s,dp),f(i,j-1,k,s,dp)));
          }
          else{
          return dp[i][j][k] = max(f(i+1,j,k,s,dp),f(i,j-1,k,s,dp));
          }
        }
    }
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
         return f(0,s.size()-1,k,s,dp);
    }
};
