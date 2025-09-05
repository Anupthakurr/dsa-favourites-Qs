qs link -----> https://leetcode.com/problems/longest-palindromic-subsequence/description/

class Solution {
    int f(int i,int j,string &s,vector<vector<int>>&v){
        if(i>j){
            return 0;}
        if(i == j){
            return 1;
        }
        if (v[i][j] != -1) return v[i][j];
        int result 
        if(s[i] == s[j]){
            return v[i][j] = 2 +  f(i+1,j-1,s,v);
        }
        else{
            return v[i][j] = max(f(i+1,j,s,v),f(i,j-1,s,v));
        }
    }
public:
    int longestPalindromeSubseq(string s) {
       vector<vector<int>>v(s.size(),vector<int>(s.size(),-1));
       return f(0,s.size()-1,s,v);
    }
};
