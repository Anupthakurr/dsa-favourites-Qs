qs link -------->> https://leetcode.com/problems/count-palindromic-subsequences/description/


class Solution {
public:
    int countPalindromes(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        // left2[a][b] = number of subsequences of form ab in prefix
        vector<vector<long long>> left2(n, vector<long long>(100, 0));
        // right2[a][b] = number of subsequences of form ab in suffix
        vector<vector<long long>> right2(n, vector<long long>(100, 0));

        // prefix counts of single digits
        vector<long long> freq(10, 0);
        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            if (i > 0) left2[i] = left2[i - 1];
            for (int a = 0; a < 10; a++) {
                left2[i][a * 10 + d] += freq[a];
            }
            freq[d]++;
        }

        // suffix counts of single digits
        fill(freq.begin(), freq.end(), 0);
        for (int i = n - 1; i >= 0; i--) {
            int d = s[i] - '0';
            if (i < n - 1) right2[i] = right2[i + 1];
            for (int a = 0; a < 10; a++) {
                right2[i][d * 10 + a] += freq[a];
            }
            freq[d]++;
        }

        // now try each middle character (c)
        long long ans = 0;
        for (int mid = 2; mid <= n - 3; mid++) {
            for (int a = 0; a < 10; a++) {
                for (int b = 0; b < 10; b++) {
                    long long leftCount = left2[mid - 1][a * 10 + b];
                    long long rightCount = right2[mid + 1][b * 10 + a];
                    ans = (ans + (leftCount % MOD) * (rightCount % MOD)) % MOD;
                }
            }
        }

        return (int)ans;
    }
};

