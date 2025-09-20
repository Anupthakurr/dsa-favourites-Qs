qs link -----> https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    int f(int i , int j , string &s , string &p , vector<vector<int>>& dp){
        if(i<0 && j < 0)return true ;
        if(i< 0 && j>=0)return false;
        if(i>=0 && j< 0 ){
            for(int ii = 0 ; ii < i ; ii++){
                if(p[ii]!= '*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(p[i]==s[j] || p[i] == '?'){
            return dp[i][j]= f(i-1 , j-1 , s , p,dp);
        }
        if(p[i]=='*'){
            return dp[i][j]=f(i-1 , j , s , p, dp) |f(i , j-1 , s , p, dp);
        }
        return dp[i][j]=false ;

    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>>dp(m +1, vector<bool>(n+1, false));
        dp[0][0]= true;
        for(int j = 1 ; j<= n ; j++){
            dp[0][j]= false;
        }
        for(int i = 1 ; i<=m  ; i++){
            bool flag = true ;
            for(int ii = 0 ; ii<i ; ii++){
                if(p[ii]!='*'){
                    flag = false;
                    break;
                }
            }
            dp[i][0]= flag ;
        }
        for(int i =1 ; i <= m ; i++){
            for(int j =1 ; j<= n ; j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[i-1] =='*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        
        return dp[m][n];

        
    }
};
