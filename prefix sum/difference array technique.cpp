//  hard level qs


qs link ------>>>  https://leetcode.com/problems/xor-after-range-multiplication-queries-ii/description/

class Solution {
public:
    static const int MOD = 1e9+7;

    int modPow(long long a, long long e) {
        long long r = 1;
        while (e) {
            if (e & 1) r = r * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return (int)r;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        unordered_map<long long, vector<int>> diff;

        for (auto &q : queries) {
            int l=q[0], r=q[1], k=q[2], v=q[3];
            int rem = l % k, start=(l-rem)/k, end=(r-rem)/k;

            long long key = (1LL*k<<32) | rem;
            if (!diff.count(key)) diff[key] = vector<int>((n-rem+k-1)/k+1, 1);

            auto &d = diff[key];
            long long inv = v ? modPow(v, MOD-2) : 0;
            d[start] = 1LL * d[start] * v % MOD;
            if (end+1 < d.size()) d[end+1] = 1LL * d[end+1] * (v?inv:1) % MOD;
        }

        for (auto &[key, d] : diff) {
            int k = key>>32, rem = key&((1LL<<32)-1);
            long long run=1;
            for (int i=0;i<d.size();i++) {
                run = run * d[i] % MOD;
                int idx = rem + i*k;
                if (idx>=n) break;
                nums[idx] = 1LL * nums[idx] * run % MOD;
            }
        }

        int ans=0;
        for (int x:nums) ans^=x;
        return ans;
    }
};
