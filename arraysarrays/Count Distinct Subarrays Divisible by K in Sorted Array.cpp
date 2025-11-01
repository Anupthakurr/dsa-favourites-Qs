qs link --->  https://leetcode.com/problems/count-distinct-subarrays-divisible-by-k-in-sorted-array/description/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        vector<long long> ps(n + 1, 0);

        // prefix sum
        for (int i = 0; i < n; ++i)
            ps[i + 1] = ps[i] + nums[i];

        // count total possible subarrays where remainder is same
        unordered_map<long long, long long> mp;
        mp[0] = 1;

        for (int i = 0; i < n; ++i) {
            long long key = ((ps[i + 1] % k) + k) % k; // handle negatives
            ans += mp[key];
            mp[key]++;
        }

        // count and remove duplicates
        unordered_map<string, long long> mp2;
        for (int i = 0; i < n; ++i) {
            string key = to_string(((ps[i + 1] % k) + k) % k) + "#" + to_string(nums[i]);
            ans -= mp2[key];
            mp2[key]++;
        }

        return ans;
    }
};
