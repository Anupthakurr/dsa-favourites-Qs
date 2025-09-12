qs link -----------> https://leetcode.com/problems/maximum-earnings-from-taxi/description/


class Solution {
public:
    struct Ride {
        int start, end, tip;
    };

    long long solve(int idx, vector<Ride>& rides, vector<long long>& dp) {
        if (idx == rides.size()) return 0;
        if (dp[idx] != -1) return dp[idx];

        // Option 1: skip this ride
        long long skip = solve(idx + 1, rides, dp);

        // Option 2: take this ride
        long long profit = (rides[idx].end - rides[idx].start) + rides[idx].tip;

        // Find next ride that does not overlap (scan forward)
        int nextIdx = idx + 1;
        while (nextIdx < rides.size() && rides[nextIdx].start < rides[idx].end) {
            nextIdx++;
        }

        long long take = profit + solve(nextIdx, rides, dp);

        return dp[idx] = max(skip, take);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& input) {
        vector<Ride> rides;
        for (auto &r : input) rides.push_back({r[0], r[1], r[2]});

        // sorting is optional here, but it helps ensure rides are in a useful order
        sort(rides.begin(), rides.end(), [](Ride &a, Ride &b) {
            return a.start < b.start;
        });

        vector<long long> dp(rides.size(), -1);
        return solve(0, rides, dp);
    }
};
