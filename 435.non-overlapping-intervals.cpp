/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort with regards to end time
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[1] < b[1];});
        int startIdx = 0;
        int endTime = 0;
        int res = 0;
        while (startIdx < intervals.size()) {
            endTime = intervals[startIdx][1];
            int newIdx = startIdx + 1;
            while(newIdx < intervals.size() && intervals[newIdx][0] < endTime){
                res++;
                newIdx++;
            }
            startIdx = newIdx;
        }
        return res;
    }
};
// @lc code=end

