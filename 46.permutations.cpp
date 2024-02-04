/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        vector<bool> used(nums.size(), false);
        backtrack(nums, track, used);
        return result;
    }

    void backtrack(vector<int>& nums, vector<int>& track, vector<bool>& used) {
        if (track.size() == nums.size()){
            result.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if(!used[i]){
                track.push_back(nums[i]);
                used[i] = true;
                backtrack(nums, track, used);
                track.pop_back();
                used[i] = false;
            }
        }
    }
};
// @lc code=end

