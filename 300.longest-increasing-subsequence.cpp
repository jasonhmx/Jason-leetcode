/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start

/*
Notes:
Dynamic programming.
dp(i) denotes the longest sub-sequence ending in nums[i]
*/
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 1){
            return 1;
        }
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++){
            // for all idxs k from 0 to i-1, check if nums[i] > nums[k] 
            // if so, curr = dp[k] + 1, else 1
            // update res to be max
            // dp[i] = res
            int res = 1;
            for (int k = 0; k < i; k++){
                if (nums[i] > nums[k]){
                    res = max(res, dp[k] + 1);
                }
            }
            dp[i] = res;
        }
        int res = 1;
        for (int i = 0; i < nums.size(); i++){
            res = max(res, dp[i]);
        }
        return res;
    }

};
// @lc code=end

