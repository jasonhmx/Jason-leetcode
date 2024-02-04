/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
/*
Notes:
Same as finding maximum non-overlapping points. Number of arrows = number of non-overlapping balloons remaining
Careful with edge cases, since the touching edges can also burst adjacent balloons
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){return a[1] < b[1];});
        int startIdx = 0;
        int endTime = 0;
        int res = 0;
        while (startIdx < points.size()) {
            endTime = points[startIdx][1];
            int newIdx = startIdx + 1;
            while(newIdx < points.size() && points[newIdx][0] <= endTime){
                res++;
                newIdx++;
            }
            startIdx = newIdx;
        }
        return points.size() - res;
    }
};
// @lc code=end

