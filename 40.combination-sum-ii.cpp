/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> track;
    
    int sum = 0;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(track, candidates, target, sum, 0);
        return result;
    }

    void backtrack(vector<int>& track, vector<int>& candidates, int target, int& sum, int start)
    {
        // essentially, find subset that can add up to target
        if (sum == target){
            result.push_back(track);
        }

        if (sum > target){
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start && candidates[i] == candidates[i-1])
            {
                continue;
            }
            track.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(track, candidates, target, sum, i+1);
            sum -= candidates[i];
            track.pop_back();
        }
    }
};
// @lc code=end

