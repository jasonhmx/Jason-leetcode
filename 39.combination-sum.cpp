/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> track;
        int sum = 0;
        backtrack(candidates, track, sum, 0, target);
        return result;
    }

    void backtrack(vector<int>& candidates, vector<int>& track, int& sum, int start, int target)
    {
        if (sum == target)
        {
            result.push_back(track);
        }

        if (sum > target)
        {
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            sum += candidates[i];
            track.push_back(candidates[i]);
            backtrack(candidates, track, sum, i, target);
            sum -= candidates[i];
            track.pop_back();
        }
    }
};
// @lc code=end

