qs link ---------> https://leetcode.com/problems/inverse-coin-change/description/


class Solution {
    int f(int i, int amount, int n, vector<int>& output,vector<vector<int>>&dp) {
        // base cases
        if (amount == 0) return 1;
        if (i >= n || amount < 0) return 0;
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        // pick current coin (only if posi[i] is allowed)
        int ways = 0;
            ways = f(i, amount - output[i], n, output,dp);
        // skip coin
        ways += f(i + 1, amount, n, output,dp);

        return dp[i][amount] = ways;
    }

public:
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> output;
        bool flag = true;
        int n = numWays.size();

        // check each possible value
        for (int i = 0; i < n; i++) {
            vector<vector<int>>dp(output.size(),vector<int>(i+1+1,-1));
            int nways = f(0, i + 1, output.size(), output,dp);
            if(nways > numWays[i]){
                flag = false;
            }
            else if (numWays[i] == 0) {
               continue;
            } 
            else if(nways == numWays[i]){
               continue;
            }
            else if (nways == (numWays[i] - 1)) {
                output.push_back(i + 1);
            } 
            else if (nways < numWays[i]) {
                flag = false;
            }
        }

        if (!flag) {
            return {};
        }
        else{
        return output;
        }
    }
};
