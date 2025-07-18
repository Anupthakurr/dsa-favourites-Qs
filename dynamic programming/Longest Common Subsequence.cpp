qs link ---> https://leetcode.com/problems/longest-common-subsequence/


class Solution {
private:
    int f(int i,int j,string &text1, string &text2, vector<vector<int>> &dp){
        //  base case
       if(i<0 || j<0){
           return 0;
       }
       if (dp[i][j] != -1) return dp[i][j];
       if(text1[i]==text2[j]){
        return dp[i][j] = 1 + f(i-1,j-1,text1,text2,dp);
       }
       else{
        return dp[i][j] = max(f(i,j-1,text1,text2,dp),f(i-1,j,text1,text2,dp));
       }
       
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1,n-1,text1,text2,dp);
    }
};
