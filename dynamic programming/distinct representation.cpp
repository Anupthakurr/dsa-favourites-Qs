
qs link ----->   https://www.codechef.com/problems/DIREP

 codechef  problem 


#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int solveDP(int i, const string &s, vector<int> &memo) {
    int n = s.size();
    if (i == n-1) return 1;          // base case: reached end        // overshot
    if (memo[i] != -1) return memo[i];

    int ways = solveDP(i + 1, s, memo); // skip operation

    // check if we can apply operation at i
    if (i + 3 < n && s[i] == s[i + 2] && s[i + 1] == s[i + 3] && s[i] != s[i + 1]) {
        ways = (ways + solveDP(i + 3, s, memo)) % MOD; // apply operation
    }

    return memo[i] = ways;  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> memo(n + 1, -1);
        cout << solveDP(0, s, memo) << '\n';
    }

    return 0;
}
