qs link ------> https://leetcode.com/problems/split-and-merge-array-transformation/description/
  
class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        if (nums1 == nums2) return 0;

        queue<vector<int>> q;
        set<vector<int>> st;
        q.push(nums1);
        st.insert(nums1);

        int cnt = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                vector<int> crr = q.front();
                q.pop();

                if (crr == nums2) return cnt;

                // Try removing prefix [0..r]
                for (int r = 0; r < n; r++) {
                    vector<int> prefix(crr.begin(), crr.begin() + r + 1);
                    vector<int> rest(crr.begin() + r + 1, crr.end());

                    for (int idx = 0; idx <= (int)rest.size(); idx++) {
                        if (idx == 0) continue; // reinserting at same place → no change
                        vector<int> finalli = rest;
                        finalli.insert(finalli.begin() + idx, prefix.begin(), prefix.end());

                        if (!st.count(finalli)) {
                            st.insert(finalli);
                            q.push(finalli);
                        }
                    }
                }

                // Try removing suffix [l..n-1]
                for (int l = 0; l < n; l++) {
                    vector<int> suffix(crr.begin() + l, crr.end());
                    vector<int> rest(crr.begin(), crr.begin() + l);

                    for (int idx = 0; idx <= (int)rest.size(); idx++) {
                        if (idx == (int)rest.size()) continue; // same place
                        vector<int> finalli = rest;
                        finalli.insert(finalli.begin() + idx, suffix.begin(), suffix.end());

                        if (!st.count(finalli)) {
                            st.insert(finalli);
                            q.push(finalli);
                        }
                    }
                }
            }
            cnt++;
        }

        return -1; // not reachable
    }
};
