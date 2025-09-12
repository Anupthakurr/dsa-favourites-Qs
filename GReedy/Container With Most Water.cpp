qs link -----------> https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if (n < 2) return 0;

        // suffix max array
        vector<int> suffMax(n);
        suffMax[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffMax[i] = max(height[i], suffMax[i+1]);
        }

        // prefix max array
        vector<int> prefMax(n);
        prefMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefMax[i] = max(height[i], prefMax[i-1]);
        }

        int ans = 0;

        // from left: find farthest right >= height[i]
        for (int i = 0; i < n; i++) {
            int lo = i+1, hi = n-1, best = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (suffMax[mid] >= height[i]) {
                    best = mid;      // candidate
                    lo = mid + 1;    // go farther
                } else {
                    hi = mid - 1;
                }
            }
            if (best != -1) {
                ans = max(ans, (best - i) * height[i]);
            }
        }

        // from right: find farthest left >= height[i]
        for (int i = n-1; i >= 0; i--) {
            int lo = 0, hi = i-1, best = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (prefMax[mid] >= height[i]) {
                    best = mid;      // candidate
                    hi = mid - 1;    // go farther left
                } else {
                    lo = mid + 1;
                }
            }
            if (best != -1) {
                ans = max(ans, (i - best) * height[i]);
            }
        }

        return ans;
    }
};
