/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start

/*
Notes:
Dynamic programming. Commented code at the end is my initial thought which does the job but is too slow.
Requires a 4d state map.

The better and faster way is to go bottom up, with clever definition of what each dp field means
Personally, I found it easier to understand what I've written out below
basically, think of each field dp[i][k][flag] as the amount of money you can make
starting on the ith day, with the stocks left, and with k transactions left.
Then build the array from end to start.
*/
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    // 4d memo to track sub problems: k, idx, bought, prof
    //unordered_map<string, int> memo; // maps from serialised state into profit

    // use bottom up approach
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp; 
        // dp[i][k][flag] gives max profit YOU CAN MAKE FROM day i, with k transactions left, whether we have a stock at hand
        // state transition function:
        // dp[i][k][0] = max(buy: dp[i+1][k][1] - price, skip: dp[i+1][k][0]) i.e. need [i+1][k][0/1]
        // dp[i][k][1] = max(sell: dp[i+1][k-1][0] + price, skip: dp[i+1][k][0]) i.e. need [i+1][k-1][0] and [i+1][k][0]
        // as long as we have base case at last i, all previous values can be worked out
        dp.resize(prices.size());
        for(auto& i : dp){
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

/*     int dp(int k, vector<int>& prices, int idx, bool bought, int prof) {
        // k !bought means we can still buy and sell k times
        // k bought means we can buy k-1 times and sell k times
        // prof tracks current profit, passes down the function call
        if (k == 0){
            return prof;
        }
        if (idx == prices.size()){ // and k is not 0
            return prof;
        }
        string state = to_string(k) + ',' + to_string(idx) + ',' + to_string((int)(bought)) + ',' + to_string(prof);
        if (memo.count(state)){
            return memo[state];
        }

        // at any idx, the max profit is current profit + max profit of actions you can do here
        int res;
        int skip = dp(k, prices, idx+1, bought, prof);
        if(bought){
            // can sell or skip
            int sell = dp(k-1, prices, idx+1, !bought, prof + prices[idx]);
            res = max(sell, skip);
        } else {
            // can buy or skip
            int buy = dp(k, prices, idx+1, !bought, prof - prices[idx]);
            res = max(buy, skip);
        }
        memo[state] = res;
        return res;
    } */
