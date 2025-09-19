qs link --------> https://leetcode.com/problems/car-fleet-ii/description/

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ans(n, -1.0);
        stack<int> st; // indices of cars ahead

        for (int i = n - 1; i >= 0; --i) {
            int pos = cars[i][0], speed = cars[i][1];

            while (!st.empty()) {
                int j = st.top();
                int pos2 = cars[j][0], speed2 = cars[j][1];

                // if car i cannot catch up
                if (speed <= speed2) {
                    st.pop();
                    continue;
                }

                // time to collide with j
                double t = (double)(pos2 - pos) / (speed - speed2);

                // if j collides before t, i can't collide with j directly
                if (ans[j] < 0 || t <= ans[j]) {
                    ans[i] = t;
                    break;
                } else {
                    st.pop();
                }
            }

            st.push(i);
        }
        return ans;
    }
};
