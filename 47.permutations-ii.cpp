/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> track;
    

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtrack(nums, track, used);
        return result;
    }

    void backtrack(vector<int>& nums, vector<int>& track, vector<bool>& used) {
        if (track.size() == nums.size())
        {
            result.push_back(track);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
            {
                continue;
            }

            if (i > 0 && nums[i-1] == nums[i] && !used[i-1])
            {
                continue;
            }

            used[i] = true;
            track.push_back(nums[i]);
            backtrack(nums, track, used);
            used[i] = false;
            track.pop_back();
        }
    }
};
// @lc code=end

