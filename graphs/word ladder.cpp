qs link ------> https://leetcode.com/problems/word-ladder/description/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord)) return 0; // endWord must be in the list

        queue<string> que;
        que.push(beginWord);
        int steps = 1; // beginWord counts as level 1

        while (!que.empty()) {
            int sz = que.size(); // process one full level at a time

            for (int i = 0; i < sz; i++) {
                string word = que.front();
                que.pop();

                if (word == endWord)
                    return steps;

                // generate all possible 1-char transformations
                for (int j = 0; j < word.size(); j++) {
                    char original = word[j];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[j] = ch;
                        if (st.find(word) != st.end()) {
                            que.push(word);
                            st.erase(word); // mark visited
                        }
                    }
                    word[j] = original;
                }
            }

            steps++; // increment after processing a full BFS level
        }

        return 0;
    }
};
