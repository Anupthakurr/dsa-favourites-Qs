qs link ---> https://leetcode.com/problems/sum-of-subarray-ranges/


class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;

        // Sum of max contributions
        stack<int> st;
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || nums[st.top()] < nums[i])) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                res += 1LL * nums[mid] * (mid - left) * (right - mid);
            }
            st.push(i);
        }

        // Subtract min contributions
        while (!st.empty()) st.pop(); // clear stack

        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                res -= 1LL * nums[mid] * (mid - left) * (right - mid);
            }
            st.push(i);
        }

        return res;
    }
};
