/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        vector<vector<int>> dp(height + 1);
        for(auto& i:dp){
            i.resize(width + 1, INT_MAX);
        }
        // dp[i][j] denotes the min distance from i j to corner
        dp[height][width-1] = 0;
        for (int i = height-1; i>=0; i--){
            for (int j = width-1; j>=0; j--){
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j];
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

