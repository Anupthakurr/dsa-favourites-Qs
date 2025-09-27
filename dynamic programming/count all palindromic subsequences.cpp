qs link --->  //

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

