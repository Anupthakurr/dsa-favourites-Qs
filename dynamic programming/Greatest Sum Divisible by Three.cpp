qs link ---->  https://leetcode.com/problems/greatest-sum-divisible-by-three/description/?envType=daily-question&envId=2025-11-23


// dp 

class Solution {
public:
    int f(int i, int mod, int n, vector<int>& nums, vector<vector<int>>& dp) {
        // Base case
        if (i == n) {
            return (mod == 0 ? 0 : INT_MIN);  
        }

        if (dp[i][mod] != -1) return dp[i][mod];

        int take = INT_MIN ;

        int newMod = mod;
        if (mod == 3) newMod = 0; // convert start mod=-1 to 0 logic

        if (nums[i] % 3 == 1) {
            take = nums[i] + f(i + 1, (newMod + 1) % 3, n, nums, dp);
        } 
        else if (nums[i] % 3 == 2) {
            take = nums[i] + f(i + 1, (newMod + 2) % 3, n, nums, dp);
        } 
        else {
            take = nums[i] + f(i + 1, (newMod + 0) % 3, n, nums, dp);
        }

        int nottake = f(i + 1, mod, n, nums, dp);

        dp[i][mod] = max(take, nottake);
        return dp[i][mod];
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return max(0, f(0, 3, n, nums, dp)); // start state mod = -1 mapped to 3
    }
};


// greddy
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> g[2];
        g[0] = {0};
        g[1] = {0};
        
        int sum = 0;
        for(auto x : nums){
            sum += x;
            if(x % 3 == 1 && g[0].size() < 3) g[0].push_back(x);
            if(x % 3 == 2 && g[1].size() < 3) g[1].push_back(x);
        }
        int ans = 0;

        int s1 = 0;
        for(auto p : g[0]){
            s1 += p;
            int s2 = 0;
            for(auto q : g[1]){
                s2 += q;
                if((sum - s1 - s2) % 3 == 0){
                    ans = max(ans, sum - s1 - s2);
                }
            }
        }
        return ans;
    }
};
