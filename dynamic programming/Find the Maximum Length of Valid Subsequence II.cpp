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
