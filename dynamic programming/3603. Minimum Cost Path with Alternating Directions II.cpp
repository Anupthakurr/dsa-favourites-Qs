qs link ------>   https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/


class Solution {
    int f(int i, int j, long long sec, int m, int n, vector<vector<int>>& waitCost) {
        long long cost = 0;   

        // Base case
        if (i == m - 1 && j == n - 1) {
            return 0;
        }

        // Even second → wait
        if ((sec % 2) == 0) {
            cost = waitCost[i][j] + f(i, j, sec + 1, m, n, waitCost);
        }
        // Odd second → move
        else {
            long long moveDown = LLONG_MAX, moveRight = LLONG_MAX;

            // Move down if within bounds
            if (i + 1 < m) {
                moveDown = (i + 2) * (j + 1) + f(i + 1, j, sec + 1, m, n, waitCost);
            }

            // Move right if within bounds
            if (j + 1 < n) {
                moveRight = (i + 1) * (j + 2) + f(i, j + 1, sec + 1, m, n, waitCost);
            }

            cost = min(moveDown, moveRight);
        }

        return cost;
    }

public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        long long sec = 1;
        return f(0, 0, sec, m, n, waitCost) + 1;
    }
};
