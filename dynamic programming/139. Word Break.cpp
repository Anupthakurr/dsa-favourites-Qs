qs link -------> https://leetcode.com/problems/word-break/description/

class Solution {
    bool f(int i, string &s, vector<string>& wordDict, vector<int>& dp) {
        // base case
        if(i == s.size()){
            return true;
        }
        if(dp[i] != -1) return dp[i];

        for(int k = 0; k < wordDict.size(); k++){
            int j = wordDict[k].size();
            if(s.substr(i, wordDict[k].size()) == wordDict[k]){
                if(f(i + j, s, wordDict, dp)){
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return f(0, s, wordDict, dp);
    }
};
