qs link ------> https://leetcode.com/problems/count-different-palindromic-subsequences/description/



class Solution {
public:
    int countPalindromicSubsequences(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> next(n), prev(n);
        vector<int> last(4, -1);  // only 'a','b','c','d' allowed in LeetCode 730

        // prev[i] = previous occurrence of s[i]
        for (int i = 0; i < n; i++) {
            prev[i] = last[s[i] - 'a'];
            last[s[i] - 'a'] = i;
        }

        fill(last.begin(), last.end(), -1);
        // next[i] = next occurrence of s[i]
        for (int i = n - 1; i >= 0; i--) {
            next[i] = last[s[i] - 'a'];
            last[s[i] - 'a'] = i;
        }

        for (int i = 0; i < n; i++) dp[i][i] = 1;  // single chars

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (s[i] != s[j]) {
                    dp[i][j] = ((dp[i + 1][j] + dp[i][j - 1]) % MOD - dp[i + 1][j - 1] + MOD) % MOD;
                } else {
                    int l = next[i], r = prev[j];
                    if (l > r) {
                        // no same char between i and j
                        dp[i][j] = (2 * dp[i + 1][j - 1] % MOD + 2) % MOD;
                    } else if (l == r) {
                        // one same char between i and j
                        dp[i][j] = (2 * dp[i + 1][j - 1] % MOD + 1) % MOD;
                    } else {
                        // more than one same char
                        dp[i][j] = ((2 * dp[i + 1][j - 1] % MOD - dp[l + 1][r - 1]) % MOD + MOD) % MOD;
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
