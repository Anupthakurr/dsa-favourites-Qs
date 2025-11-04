qs link ----->   https://leetcode.com/problems/sum-of-subarray-ranges/description/

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> ple(n), nle(n), pge(n), nge(n);
        stack<int> st;

        // Previous Less Element (strictly less)
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack for reuse
        while (!st.empty()) st.pop();

        // Next Less Element (strictly less)
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Clear stack again
        while (!st.empty()) st.pop();

        // Previous Greater Element (strictly greater)
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack again
        while (!st.empty()) st.pop();

        // Next Greater Element (strictly greater)
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Now calculate contributions
        long long minSum = 0, maxSum = 0;

        for (int i = 0; i < n; ++i) {
            long long leftMin = i - ple[i];
            long long rightMin = nle[i] - i;
            minSum += (long long)nums[i] * leftMin * rightMin;

            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;
            maxSum += (long long)nums[i] * leftMax * rightMax;
        }

        return maxSum - minSum;
    }
};
