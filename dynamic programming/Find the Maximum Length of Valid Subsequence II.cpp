qs link ---->  https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/?envType=daily-question&envId=2025-07-17


class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        //Using same LIS bottom up code

        int n = nums.size();
        vector<vector<int>> dp(k, vector<int>(n, 1));
        int maxSub = 1;

        //mod = 1
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int mod = (nums[j] + nums[i]) % k;
                //mod = 0 = 0th row , %2 = 0 waale case ka result
                //mod = 1 = 1st row, %2 = 1 waale case ka result
                dp[mod][i] = max(dp[mod][i], 1 + dp[mod][j]);
                maxSub = max(maxSub, dp[mod][i]);
            }
        }
        return maxSub;
    }
};

______________________________________________________________________________________________________________________
top down approach

class Solution {
public:
    int n, k;
    vector<vector<int>> dp;
    vector<int> nums;

    int check(int i, int prev) {
        if (i == n) return 0;

        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        int take = 0, notTake = 0;

        if (prev == -1) {
            notTake = check(i + 1, prev);

            for (int j = i + 1; j < n; ++j) {
                take = max(take, 2 + check(j, (nums[i] + nums[j]) % k));
            }
        } else {
            for (int j = i + 1; j < n; ++j) {
                if ((nums[i] + nums[j]) % k == prev) {
                    take = 1 + check(j, prev);
                    break;
                }
            }
        }

        return dp[i][prev + 1] = max(take, notTake);
    }

    int maximumLength(vector<int>& nums_, int k_) {
        nums = nums_;
        k = k_;
        n = nums.size();
        dp.assign(n, vector<int>(k + 1, -1));
        return check(0, -1);
    }
};



