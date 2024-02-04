/*
 * @lc app=leetcode id=1024 lang=cpp
 *
 * [1024] Video Stitching
 */

// @lc code=start
/*
Notes:
strategy: sort by start time, find longest end time that starts from 0
for next ones, find overlapping one that ends the latest
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
        if(clips[0][0] != 0){ // no clip starts at beginning
            return -1;
        }
        int maxEnd = 0;
        int startIdx = 0;
        int res = 0;
        // maxEnd now notes the longest interval starting from 0
        // startIdx now points to the interval past intervals from 0
        while(startIdx < clips.size() && maxEnd < time){
            if (clips[startIdx][0] > maxEnd){
                return -1;
            }
            int prevEnd = maxEnd;
            while(startIdx < clips.size() && clips[startIdx][0] <= prevEnd){ // for all the overlapping ones, find new maxEnd
                maxEnd = max(maxEnd, clips[startIdx][1]);
                startIdx++;
            }
            res++;
        } 
        if(maxEnd < time && startIdx >= clips.size()){
            return -1;
        }
        return res;
    }
};
// @lc code=end

