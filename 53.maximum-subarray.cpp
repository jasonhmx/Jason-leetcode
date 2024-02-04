/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
/*
Notes:
First thoughts: same as increasing subsequence approach
dp[i] gives the largest sum of a subarray ending in nums[i]

*/
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len == 1){
            return nums[0];
        }
        vector<int> dp(len, 0);
        dp[0] = nums[0]; // first element is always nums[0]
        for (int i = 1; i < len; i++){
            // assuming we already have the subarray ending in i-1
            // with the greatest sum
            if (dp[i-1] <= 0){ // if previous subarray drags me down
                // imma start fresh
                dp[i] = nums[i];
            } else { // if previous adds to me
                // yay let's be together
                dp[i] = dp[i-1] + nums[i];
            }
        }
        int res = INT_MIN;
        for (auto i : dp){
            res = max(res, i);
        }
        return res;
    }
};
// @lc code=end

