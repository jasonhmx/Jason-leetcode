/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 2;
        vector<vector<vector<int>>> dp; 
        // dp[i][k][flag] gives max profit YOU CAN MAKE FROM day i, with k transactions left, whether we have a stock at hand
        // state transition function:
        // dp[i][k][0] = max(buy: dp[i+1][k][1] - price, skip: dp[i+1][k][0]) i.e. need [i+1][k][0/1]
        // dp[i][k][1] = max(sell: dp[i+1][k-1][0] + price, skip: dp[i+1][k][0]) i.e. need [i+1][k-1][0] and [i+1][k][0]
        // as long as we have base case at last i, all previous values can be worked out
        dp.resize(prices.size());
        for(auto& i : dp){
            // need transac = 0 to transac = k;
            i.resize(k+1);
            for (auto& j : i){
                j.resize(2, 0);
            }
        }

        // when k == 0, the amount you can make is 0, so default to 0
        // populate the i == prices.size()-1 case
        int endIdx = prices.size()-1;
        for(int transac = 1; transac <= k; transac++){
            dp[endIdx][transac][0] = 0; // no stock, can't do anything
            dp[endIdx][transac][1] = prices[endIdx]; // have stock, can sell
        }
        // now all of i == endIdx is populated, can start populating previous i's
        for(int i = endIdx-1; i>=0; i--){ // i goes down
            for(int transac = 1; transac <= k; transac++){ // k goes up
                dp[i][transac][0] = max(dp[i+1][transac][1] - prices[i], dp[i+1][transac][0]);
                dp[i][transac][1] = max(dp[i+1][transac-1][0] + prices[i], dp[i+1][transac][1]);
            }
        }
        return dp[0][k][0];
    }
};
// @lc code=end

