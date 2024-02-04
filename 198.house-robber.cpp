/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // state: at index i, can/cannot rob certain house
        // let dp[i][flag] be the maximum amount of money I can make at i onwards
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        // populate last index
        int endIdx = nums.size() - 1;
        // can rob:
        dp[endIdx][1] = nums[endIdx];
        // can't rob:
        dp[endIdx][0] = 0;

        // dp[i][1] = max(rob this, skip this)
        // dp[i][0] = skip this
        for (int i  = endIdx - 1; i >= 0; i--){
            dp[i][1] = max(dp[i+1][0] + nums[i], dp[i+1][1]);
            dp[i][0] = dp[i+1][1];
        }
        return dp[0][1];
    }
};
// @lc code=end

