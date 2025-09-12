qs link ---------> https://leetcode.com/problems/balanced-k-factor-decomposition/

class Solution {
public:
    vector<int> getFactors(int n) {
        vector<int> factors;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                if (i != n / i) factors.push_back(n / i);
            }
        }
        return factors;
    }

    void backtrack(int n, int k, int start, vector<int>& path,
                   vector<int>& factors, vector<vector<int>>& res) {
        if (k == 0) {
            if (n == 1) res.push_back(path); // valid split
            return;
        }

        for (int i = start; i < factors.size(); i++) {
            int f = factors[i];
            if (n % f == 0) {
                path.push_back(f);
                backtrack(n / f, k - 1, i, path, factors, res);
                path.pop_back();
            }
        }
    }

    vector<int> minDifference(int n, int k) {
        vector<int> factors = getFactors(n);
        vector<int> path;
        vector<vector<int>> allSplits;

        backtrack(n, k, 0, path, factors, allSplits);

        // pick the one with minimum (max - min)
        vector<int> best;
        int bestDiff = INT_MAX;
        for (auto& split : allSplits) {
            int mn = *min_element(split.begin(), split.end());
            int mx = *max_element(split.begin(), split.end());
            if (mx - mn < bestDiff) {
                bestDiff = mx - mn;
                best = split;
            }
        }
        return best;
    }
};

