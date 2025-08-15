qs link -----> https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/1625624410/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        set<char> st;
        
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (st.find(s[j]) != st.end()) {
                    break;
                }
                st.insert(s[j]);
            }
            maxi = max(maxi, (int)st.size()); 
            st.clear();
            if(maxi > (s.size() -1) - i) break;
        }

        return maxi;
    }
};
