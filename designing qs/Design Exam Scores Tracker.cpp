qs link -----> https://leetcode.com/problems/design-exam-scores-tracker/description/

#include <bits/stdc++.h>
using namespace std;

class ExamTracker {
public:
    vector<int> times;          // stores times of exams
    vector<long long> prefix;   // prefix sum of scores

    ExamTracker() {}

    void record(int time, int score) {
        times.push_back(time);
        if (prefix.empty()) prefix.push_back(score);
        else prefix.push_back(prefix.back() + score);
    }

    long long totalScore(int startTime, int endTime) {
        // find left index (first >= startTime)
        int l = lower_bound(times.begin(), times.end(), startTime) - times.begin();
        // find right index (last <= endTime)
        int r = upper_bound(times.begin(), times.end(), endTime) - times.begin() - 1;

        if (l > r) return 0; // no exams in range

        long long total = prefix[r];
        if (l > 0) total -= prefix[l - 1];
        return total;
    }
};
