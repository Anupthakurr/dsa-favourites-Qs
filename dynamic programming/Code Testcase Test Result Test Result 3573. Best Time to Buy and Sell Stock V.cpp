qs link ----->  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/description/


class Solution {
public:
  // state: 0 = idle, 1 = after buy (waiting to sell), 2 = after sell (waiting to buy)
  vector<vector<vector<long long>>>dp;
    long long solve(int day, vector<int>& prices, int k, int state) {
        if (day >= prices.size()) {
            return (state) ? -1e18 : 0;
        }
        if (k <= 0)
            return 0;
        if(dp[day][k][state]!=-1) return dp[day][k][state];
        long long ans = 0;
        
        // case 1 : either maine kharida hoga, ab bechta hu or aage future mein
        // bechta hu
        // case 2 : ya fir pehle becha hoga , ab kharidna padega or
        // aage chalke kharidunga
        // case 3 : ya fir kuch nhi, khali hath hi hu abhi tak
        if (state==1) {
            // ab bechta hu or
            long long abhiBechtaHu =
                prices[day] + solve(day + 1, prices, k - 1, 0);
            // aage future mein bechta hu
            long long futureMeinBechtaHu =
                solve(day + 1, prices, k, 1);
            ans = max(abhiBechtaHu, futureMeinBechtaHu);
        } else if (state==2) {
            // ab kharidna padega or
            long long abhiKharidtaHu =
                -prices[day] + solve(day + 1, prices, k - 1,0);
            // aage chalke kharidunga
            long long aageChalKeKharidataHu =
                solve(day + 1, prices, k,2);
            ans = max(abhiKharidtaHu, aageChalKeKharidataHu);
        } else {
            //  ya fir kuch nhi, khali hath hi hu abhi tak
            // either kharid lu
            long long kharidLu =
                -prices[day] + solve(day + 1, prices, k, 1);
            // ya fir bech du
            long long bechDu =
                prices[day] + solve(day + 1, prices, k, 2);
            // ya toh  aage chal ke dekhta hu
            long long aageDekhataHu = solve(day + 1, prices, k,0);
            ans = max(kharidLu, max(bechDu, aageDekhataHu));
        }
        return dp[day][k][state]= ans;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        dp.resize(n+1, vector<vector<long long>>(k+1, vector<long long>(4, -1)));
        return solve(0, prices, k, 0);
    }
};
