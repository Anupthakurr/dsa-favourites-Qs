qs link -----------> https://leetcode.com/problems/longest-palindromic-substring/description/

  class Solution {
    string s;
    int n;
    int startIdx = 0, maxLen = 1;

    // expand around center recursively
    void expand(int left, int right) {
        if (left < 0 || right >= n) return;
        if (s[left] != s[right]) return;

        if (right - left + 1 > maxLen) {
            startIdx = left;
            maxLen = right - left + 1;
        }

        expand(left - 1, right + 1); // expand outward
    }

public:
    string longestPalindrome(string str) {
        s = str;
        n = s.size();

        for (int center = 0; center < n; center++) {
            expand(center, center);     // odd-length palindromes
            expand(center, center + 1); // even-length palindromes
        }
        return s.substr(startIdx, maxLen);
    }
};
