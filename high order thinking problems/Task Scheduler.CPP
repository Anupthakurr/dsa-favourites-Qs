qs link ----> https://leetcode.com/problems/task-scheduler/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char t : tasks)
            freq[t - 'A']++;

        int maxFreq = *max_element(freq.begin(), freq.end());
        int countMax = count(freq.begin(), freq.end(), maxFreq);

        int partCount = maxFreq - 1;
        int partLength = n + 1;
        int minTime = partCount * partLength + countMax;

        return max((int)tasks.size(), minTime);
    }
};
