/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<vector<int>>> memo; // memo[lo][hi][p]
    bool PredictTheWinner(vector<int>& nums) {
        memo.resize(nums.size());
        for(auto& i : memo){
            i.resize(nums.size());
            for (auto& k : i){
                k.resize(2, -1);
            }
        }
        int res1 = dp(nums, 0, nums.size()-1, 0);
        int res2 = dp(nums, 0, nums.size()-1, 1);
        return res1 >= res2;
    }

    int dp(vector<int>& nums, int lo, int hi, int player){
        // dp(nums, lo, hi, player) should give the max score
        // the first/second player AT THAT TURN could achieve
        // e.g. at the same lo hi, we might have player 1 taking first
        // or player 2 taking first. The max score at that point for the
        // same order player should be the same
        // player == 0 means first player, player == 1 second.

        // at dp(l, h), a few following scenarios can occur:
        // p1 l: dp(l, h, 0) = nums[l] + dp(l+1, h, 1)
        // p2 following p1: dp(l+1, h, 0);
        // p1 r: dp(l, h, 0) = nums[h] + dp(l, h-1, 1)
        // p2 following p1: dp(l, h-1, 0);

        // base case: l == h
        if(lo == hi){
            if(player == 0){
                return nums[lo];
            } else {
                return 0;
            }
        }
        if(memo[lo][hi][player] != -1){
            return memo[lo][hi][player];
        }

        int left = nums[lo] + dp(nums, lo+1, hi, 1);
        int right = nums[hi] + dp(nums, lo, hi-1, 1);
        int second;
        if(left > right){
            second = dp(nums, lo+1, hi, 0);
            memo[lo][hi][0] = left;
            return player == 0 ? left : second;
        } else {
            second = dp(nums, lo, hi-1, 0);
            memo[lo][hi][0] = right;
            memo[lo][hi][1] = second;
            return player == 0 ? right : second;
        }
    }
};
// @lc code=end

/* class Solution {
public:
    vector<vector<int>> memo;
    bool PredictTheWinner(vector<int>& nums) {
        memo.resize(nums.size());
        for(auto& i : memo){
            i.resize(nums.size(), -1);
        }
        int p1 = maxScore(nums, 0, nums.size()-1);
        // Problem is here: p1 is worked out successfully. but how do you know what p2 is?
        // our method doesn't help keep track of p1's actions
        // so you can't calculate p2 based on the already optimal (but unknown) choice of p1
        int p2 = ?;
        return p1>p2;
    }

    int maxScore(vector<int>& nums, int low, int high){
        // returns the max score you can get when it is your turn
        // and the array is bound between low and high
        if (low == high){
            return nums[low];
        }
        if (low > high){
            return 0;
        }
        if(memo[low][high] != -1){
            return memo[low][high];
        }
        int res = 0;
        // it is the max score of picking low vs picking high
        // 4 scenarios: 1 l 2 l, 1 l 2 r, 1 r 2 l, 1 r 2 r
        int p1lp2l = nums[low] + maxScore(nums, low+2, high);
        int p1lp2r = nums[low] + maxScore(nums, low+1, high-1);
        int minLeft = min(p1lp2l, p1lp2r); // p2 has the choice of making this worse for p1
        int p1rp2l = nums[high] + maxScore(nums, low+1, high-1);
        int p1rp2r = nums[high] + maxScore(nums, low, high-2);
        int minRight = min(p1rp2l, p1rp2r); // same here
        res = max(minLeft, minRight);
        memo[low][high] = res;
        return res;
    }
}; */