qs link ------> https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/description/


  #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string ans;
    int n;
    // dfs returns true if it found an answer (and ans is set)
    bool dfs(const string &target, vector<int> &freq, string &curr, int idx) {
        if (idx == n) {
            // We have constructed a string equal to target -> not strictly greater,
            // so this path fails (we require strictly greater).
            return false;
        }
        int t = target[idx] - 'a';
        // Try characters in increasing order from target[idx] to 'z'
        for (int c = t; c < 26; ++c) {
            if (freq[c] == 0) continue;
            // Choose this character
            freq[c]--;
            curr.push_back(char('a' + c));

            if (c > t) {
                // If we pick strictly greater char, we can fill the rest smallest-first
                string suffix;
                for (int k = 0; k < 26; ++k) suffix.append(freq[k], char('a' + k));
                ans = curr + suffix;
                return true; // success
            } else {
                // c == t : only proceed if the remaining suffix can yield a strict greater
                bool ok = dfs(target, freq, curr, idx + 1);
                if (ok) return true;
                // else backtrack and try next char (which will be a greater one if available)
            }

            // backtrack
            curr.pop_back();
            freq[c]++;
        }

        // No choice at this index leads to a valid strictly-greater permutation
        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        n = s.size();
        vector<int> freq(26, 0);
        for (char ch : s) freq[ch - 'a']++;

        string curr;
        // Try to construct using backtracking as described
        if (dfs(target, freq, curr, 0)) {
            return ans;
        }
        return "";
    }
};


