/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<string, int> memo; // vectors don't work since track can be negative
    // can turn to string and use as hash key
    int findTargetSumWays(vector<int>& nums, int target) {
        return dp(nums, target, 0, 0);
    }

    int dp(vector<int>& nums, int target, int i, int track){
        if (track == target && i == nums.size()){ // needs to make sure we have reached the end
            return 1;
        }
        if (i >= nums.size()){
            return 0;
        }
        string hash = to_string(i) + ',' + to_string(track);
        if (memo.count(hash)){
            return memo[hash];
        }
        int res = 0;
        // can choose to add or subtract the current number
        res = dp(nums, target, i+1, track-nums[i]) + dp(nums, target, i+1, track+nums[i]);
        memo[hash] = res;
        return res;
    }
};
// @lc code=end

