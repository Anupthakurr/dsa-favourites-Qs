qs link ----> https://leetcode.com/problems/word-break/

class Solution {
    bool f(int i, string &ans, string &s, vector<string>& wordDict, vector<int>& dp) {
        // base case
        if (ans == s) {
            return true;
        }

        // if we already computed this index
        if (dp[i] != -1) {
            return dp[i];
        }

        for (int k = 0; k < wordDict.size(); k++) {
            int j = wordDict[k].size();
            if (i + j <= s.size() && s.substr(i, wordDict[k].size()) == wordDict[k]) {
                ans = ans + wordDict[k];
                if (f(i + j, ans, s, wordDict, dp)) {
                    return dp[i] = true;
                } else {
                    ans.erase(ans.size() - j, j); // erase the word we added
                }
            }
        }

        return dp[i] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        string ans = "";
        vector<int> dp(s.size() + 1, -1);
        return f(0, ans, s, wordDict, dp);
    }
};
