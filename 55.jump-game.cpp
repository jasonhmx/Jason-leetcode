/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1){
            return true;
        }
        vector<bool> dp(nums.size(), false);
        dp[nums.size()-1] = true;
        for (int i = nums.size()-2; i >= 0; i--){
            int canStep = nums[i];
            for (int j = 1; j <= canStep && (i+j) < nums.size(); j++){
                if(dp[i+j]){
                    dp[i] = true;
                }
            }
        }
        return dp[0];
    }

};
// @lc code=end

