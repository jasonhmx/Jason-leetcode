/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // only 2d dp needed. dp[i][k][flag] means on day i, k transactions left, with/without a stock, max profit that can be made
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        // populate last day: 
        int endIdx = prices.size()-1;
        // when k == 0, nothing can do, base case profit 0, default initialised.
        dp[endIdx][0] = 0; // no stock at hand, don't buy
        dp[endIdx][1] = prices[endIdx] - fee; // stock at hand, can sell
        for (int i = endIdx - 1; i >= 0; i--){
            // we only care about k == 1, k == 0 is just for base case and always gives 0
            // not having a stock = max (if we buy, if we skip)
            dp[i][0] = max(dp[i+1][1] - prices[i], dp[i+1][0]);
            // having a stock; sell prices here (no future sells) or skip
            dp[i][1] = max(dp[i+1][0] + prices[i] - fee, dp[i+1][1]);
        }
        return dp[0][0];
    }
};
// @lc code=end

