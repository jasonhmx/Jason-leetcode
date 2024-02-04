/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
/*
Notes:
First thought is it's difficult to come up with base case. But I suppose we still can. Pick one house as base
case and populate the circle

That doesn't quite work. Instead use top down approach and consider two separate cases:
rob 0th not last; rob last not 0th
essentially two ranges
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> memo;
    int rob(vector<int>& nums) {
        if (nums.size() == 1){ // if we have less than 2 elements
            return nums[0];
        }
        memo.resize(nums.size());
        for(auto& i : memo){
            i.resize(2, -1);
        }
        int canRobFirst = dp(nums, nums.size()-2, 0, true);
        for(auto& i : memo){ // clear memo
            i[0] = -1;
            i[1] = -1;
        }
        int canRobLast = dp(nums, nums.size()-1, 1, true); // omits first
        return max(canRobFirst, canRobLast);
    }

    int dp(vector<int>& nums, int end, int i, bool canRob){
        if (i > end){ // out of bounds
            return 0;
        }
        if (memo[i][canRob] != -1){
            return memo[i][canRob];
        }
        int res = 0;
        if (canRob){
            res = max(nums[i] + dp(nums, end, i+1, false), dp(nums, end, i+1, true));
        } else {
            res = dp(nums, end, i+1, true);
        }
        memo[i][canRob] = res;
        return res;
    }
};
// @lc code=end

