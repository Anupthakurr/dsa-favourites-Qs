qs link ---->  https://leetcode.com/problems/wildcard-matching/description/

class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        // Base cases
        if (i < 0 && j < 0) return true;               // both strings fully matched
        if (j < 0 && i >= 0) return false;             // pattern ended, s still left
        if (i < 0 && j >= 0) {                         // string ended, pattern left
            // pattern can still match if all remaining are '*'
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        // if already computed
        if (dp[i][j] != -1) return dp[i][j];

        // If characters match or pattern has '?'
        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);

        // If pattern has '*'
        if (p[j] == '*') {
            // two possibilities:
            // 1. '*' matches empty sequence -> move pattern back (j - 1)
            // 2. '*' matches one or more characters -> move string back (i - 1)
            return dp[i][j] = solve(i, j - 1, s, p, dp) || solve(i - 1, j, s, p, dp);
        }

        // no match
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, s, p, dp);
    }
};
